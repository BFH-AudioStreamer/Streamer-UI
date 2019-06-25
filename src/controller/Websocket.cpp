#include <utility>

#include <utility>

/**
 *******************************************************************************
 * @addtogroup Websocket
 * @{
 * @brief Brief descriptions
 *
 * Elaborate Description
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

#include <iostream>
#include <nlohmann/json.hpp>

#include "Websocket.h"

using json = nlohmann::json;

/**
 * @brief Websocket::Websocket connect to websocket
 * @param url
 */
Websocket::Websocket(const std::string& url)
        :m_url(url) {
    connect(&m_web_socket, &QWebSocket::connected, this, &Websocket::on_connected);
    connect(&m_web_socket, &QWebSocket::disconnected, this, &Websocket::closed);
}

/**
 * @brief Websocket::register_on_connected register callback function connect
 * @param _callback_on_connected
 */
void Websocket::register_on_connected(std::function<void()> _callback_on_connected) {
    callback_on_connected = std::move(_callback_on_connected);
}

/**
 * @brief Websocket::register_on_message_received register callback function on receive
 * @param _callback_on_message_received
 */
void Websocket::register_on_message_received(
        std::function<void(std::string)> _callback_on_message_received) {

    callback_on_message_received = std::move(_callback_on_message_received);
}

/**
 * @brief Websocket::send_message send message to websocket
 * @param message
 */
void Websocket::send_message(std::string message) {
    m_web_socket.sendTextMessage(QString::fromStdString(message));
}

/**
 * @brief Websocket::open open websocket
 */
void Websocket::open() {
    /* only accept open request if socket is closed */
    if (m_web_socket.state()==QAbstractSocket::UnconnectedState) {
        m_web_socket.open(QUrl(QString::fromStdString(m_url)));
    }
}

/**
 * @brief Websocket::close close websocket
 */
void Websocket::close() {
    m_web_socket.close();
}

/**
 * @brief Websocket::on_connected function called on connect
 */
void Websocket::on_connected() {
    callback_on_connected();
    connect(&m_web_socket,
            &QWebSocket::textMessageReceived,
            this,
            &Websocket::on_message_received);
}

/**
 * @brief Websocket::on_message_received function called on message received
 * @param message
 */
void Websocket::on_message_received(QString message) {
    callback_on_message_received(message.toStdString());
}

/** @} */
