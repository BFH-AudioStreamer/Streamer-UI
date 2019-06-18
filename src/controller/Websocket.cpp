//
// Created by stefan on 17.06.19.
//

#include <iostream>

#include "Websocket.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

Websocket::Websocket(const std::string& url)
{
    std::cout << "trackImage state: " << m_QwebSocket.state() << std::endl;

    /* connect the QWebSocket */
    connect(&m_QwebSocket, &QWebSocket::connected, this, &Websocket::onConnected);
    connect(&m_QwebSocket, &QWebSocket::disconnected, this, &Websocket::closed);

    /* open the QWebSocket with specyfied url */
    m_QwebSocket.open(QUrl(QString::fromStdString(url)));

    std::cout << "open: " << url << std::endl;
}

void Websocket::onConnected(){
    std::cout << "WebSocket connected!" << std::endl;
}

void Websocket::trackImage(){
    /* json to request current track */
    json j = {
            {"jsonrpc", "2.0"},
            {"id", 1},
            {"method", "core.playback.get_current_track"}
    };

    std::cout << "trackImage state: " << m_QwebSocket.state() << std::endl;



    connect(&m_QwebSocket, &QWebSocket::textMessageReceived,
            this, &Websocket::onTextMessageReceived);

    std::cout << "trackImage state: " << m_QwebSocket.state() << std::endl;

    m_QwebSocket.sendTextMessage(QString::fromStdString(j.dump()));
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

        m_QwebSocket.sendTextMessage(QString::fromStdString(j.dump()));
        first_request = false;
    }
    else {
        /* receive image uri */
        std::cout << rec["result"][song_uri][0]["uri"] << std::endl;
        m_QwebSocket.close();
    }
}
