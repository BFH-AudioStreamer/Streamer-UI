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
    explicit Websocket(const std::string &url, std::string &imageUri);
    void trackImage();
    void open();
    void close();


Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket m_QwebSocket;
    std::string m_url;
    bool m_debug;
    std::string &imageUri;
};


#endif // WEBSOCKET_H
