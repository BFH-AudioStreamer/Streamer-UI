/**
 *******************************************************************************
 * @addtogroup Mopidy_connector
 * @{
 * @brief Backend connector for a Mopidy WebSocket server
 *
 * @authors Stefan Lüthi
 ****************************************************************************//*
 * Copyright (C) 2019 Audio-Streamer Project Group
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/

#include <utility>
#include <functional>
#include "Mopidy_connector.h"

/**
 * @brief Loads backend information from config file, create websocket and
 *        registers callback methods
 *
 * The application configuration must specify the Mopidy hostname and port as
 * shown in the example below:
 * @code{.json}
 * {
 *     "Mopidy_connector": {
 *          "hostname": "Audio-Streamer",
 *          "port": 6680
 *      }
 * }
 * @endcode
 * @param app_config
 */
Mopidy_connector::Mopidy_connector(const json& app_config) {
    /* validate config */
    auto connector_it = app_config.find("Mopidy_connector");
    if (connector_it==app_config.end()) {
        std::cout << "Mopidy_connector: Config missing!" << std::endl;
        return;
    }
    auto connector = *connector_it;
    auto hostname_it = connector.find("hostname");
    auto port_it = connector.find("port");
    if ((hostname_it==connector.end()) || (port_it==connector.end())) {
        std::cout << "Mopidy_connector: hostname or port missing in config!" << std::endl;
        return;
    }
    /* create WebSocket */
    hostname = *hostname_it;
    port = *port_it;
    client = new Websocket("ws://"+hostname+":"+std::to_string(port)+"/mopidy/ws");
    /* register callback methods */
    client->register_on_connected(std::bind(
            &Mopidy_connector::request_image,
            this));
    client->register_on_message_received(std::bind(
            &Mopidy_connector::receive_image,
            this,
            std::placeholders::_1));
}

/**
 * @brief Gets buffered album art URI from track URI
 *
 * Getting the album art URI is non-blocking, therefore this method returns the
 * image URI of the last request which is internally buffered
 * @param _track_uri Track URI to load an image for
 * @return Buffered image URI
 */
std::string Mopidy_connector::album_art_uri(std::string _track_uri) {
    track_uri = std::move(_track_uri);
    client->open();
    return image_uri;
}

/**
 * @brief Sends image request over WebSocket to Mopidy
 */
void Mopidy_connector::request_image() {
    /* JSON packet to request current image for track */
    json j = {
            {"jsonrpc", "2.0"},
            {"id",      1},
            {"method",  "core.library.get_images"},
            {"params",  {
                                {"uris", {track_uri}}}
            }
    };

    client->send_message(j.dump());
}

/**
 * @brief Extracts data from JSON object and saves them
 * @param message Text message received over WebSocket (must have JSON format)
 */
void Mopidy_connector::receive_image(std::string message) {
    auto rec = json::parse(message);

    /* extract image URI */
    std::string new_image_uri{};
    try {
        new_image_uri = rec["result"][track_uri][0]["uri"];
        image_uri = new_image_uri;
    }
    catch (std::exception e) { }
    client->close();
}

/** @} */
