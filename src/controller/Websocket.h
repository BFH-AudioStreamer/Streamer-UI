//
// Created by stefan on 17.06.19.
//

#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>

class Websocket : public QObject {
    Q_OBJECT
public:
    explicit Websocket(const std::string &url);

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;
};


#endif // WEBSOCKET_H
