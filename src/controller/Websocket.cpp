//
// Created by stefan on 17.06.19.
//

#include <iostream>

#include "Websocket.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

Websocket::Websocket(const std::string& url)
        :m_url(url) {
    connect(&m_QwebSocket, &QWebSocket::connected, this, &Websocket::onConnected);
    connect(&m_QwebSocket, &QWebSocket::disconnected, this, &Websocket::closed);

    //std::cout << "open: " << url << std::endl;
}

void Websocket::open() {
    if (m_QwebSocket.state() == QAbstractSocket::UnconnectedState) {
        m_QwebSocket.open(QUrl(QString::fromStdString(m_url)));
    }
}

void Websocket::onConnected() {
    //std::cout << "WebSocket connected! -----------------------------" << std::endl;
    trackImage();
}

void Websocket::trackImage() {
    /* json to request current track */
    json j = {
            {"jsonrpc", "2.0"},
            {"id",      1},
            {"method",  "core.playback.get_current_track"}
    };

    connect(&m_QwebSocket, &QWebSocket::textMessageReceived,
            this, &Websocket::onTextMessageReceived);

    //std::cout << j.dump(2) << std::endl;
    m_QwebSocket.sendTextMessage(QString::fromStdString(j.dump()));
}

void Websocket::onTextMessageReceived(QString message) {
    static bool first_request = true;
    static std::string song_uri{};
    auto rec = json::parse(message.toStdString());
    //std::cout << "Message received: " << std::endl <<
    //              rec.dump(2) << std::endl;

    if (first_request) {
        /* parse track info to get track uri */
        try {
            song_uri = rec["result"]["uri"];
        }
        catch (std::exception e) {

        }

        /* request album art */
        json j = {
                {"jsonrpc", "2.0"},
                {"id",      1},
                {"method",  "core.library.get_images"},
                {"params",  {
                                    {"uris", {song_uri}}}
                }
        };
        //std::cout << "Send message: " << std::endl <<
        //             j.dump(2) << std::endl;

        m_QwebSocket.sendTextMessage(QString::fromStdString(j.dump()));
        first_request = false;
    }
    else {
        /* receive image uri */
        first_request = true;

        std::string image_uri{};

        try {
            image_uri = rec["result"][song_uri][0]["uri"];
            std::cout << "Image URI: " << image_uri << std::endl;
            close();
        }
        catch (std::exception e) { }

        // ignore wrong packets
        if (image_uri == "null") {
            first_request = false;
        }
    }
}

void Websocket::close() {
    m_QwebSocket.close();
}
