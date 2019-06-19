/**
 *******************************************************************************
 * @addtogroup Mopidy_connector
 * @{
 * @brief Brief descriptions
 *
 * Elaborate Description
 *
 * @authors Rafael Klossner
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
 *******************************************************************************
 */

#include <utility>
#include "Mopidy_connector.h"

Mopidy_connector::Mopidy_connector(const json& app_config) {
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
    hostname = *hostname_it;
    port = *port_it;
    client = new Websocket("ws://"+hostname+":"+std::to_string(port)+"/mopidy/ws", imageUri);
}

std::string Mopidy_connector::image_uri() {
    Data_track_info trackInfo;
    //client = new Websocket("ws://192.168.138.131:6680/mopidy/ws");
    client->open();
    //client->trackImage();
    return imageUri;
}

/** @} */
