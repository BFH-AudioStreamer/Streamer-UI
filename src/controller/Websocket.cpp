//
// Created by stefan on 17.06.19.
//

#include <iostream>

#include "Websocket.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

Websocket::Websocket(const std::string& url)
{
    connect(&m_webSocket, &QWebSocket::connected, this, &Websocket::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &Websocket::closed);
    m_webSocket.open(QUrl(QString::fromStdString(url)));
}

void Websocket::onConnected()
{
    json j = {
            {"jsonrpc", "2.0"},
            {"id", 1},
            {"method", "core.playback.get_current_track"}
    };

    std::cout << "WebSocket connected!" << std::endl;
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &Websocket::onTextMessageReceived);
    m_webSocket.sendTextMessage(QString::fromStdString(j.dump()));
}

void Websocket::onTextMessageReceived(QString message)
{
    static bool first_request = true;
    static std::string song_uri{};
    auto rec = json::parse(message.toStdString());
    std::cout << "Message received: " << std::endl <<
                 rec.dump(4) << std::endl;

    if (first_request) {
        /* parse track info to get track uri */
       song_uri = rec["result"]["uri"];

        /* request album art */
        json j = {
                {"jsonrpc", "2.0"},
                {"id", 1},
                {"method", "core.library.get_images"},
                {"params", {
                        {"uris", {song_uri}}}
                }
        };
        std::cout << "Send message: " << std::endl <<
                     j.dump(4) << std::endl;

        m_webSocket.sendTextMessage(QString::fromStdString(j.dump()));
        first_request = false;
    }
    else {
        /* receive image uri */
        std::cout << rec["result"][song_uri][0]["uri"] << std::endl;
        m_webSocket.close();
    }
}
