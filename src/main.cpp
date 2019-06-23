/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @defgroup Main
 * @{
 * @brief Main module
 *
 * Ladidadida
 *
 * @authors Stefan Lüthi
 ****************************************************************************//*
 * Copyright (c) 2019 Audio-Streamer Project Group
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

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/model/Model.h"
#include "controller/Controller.h"
#include "tools/Config_loader.h"

/**
 * @brief Main method
 */
int main(int argc, char* argv[]) {
    auto config = Config_loader::load("streamer-ui.conf");
    if (config.is_null()) {
        return EXIT_FAILURE;
    }
    auto app_config_it = config.find("App_config");
    if (app_config_it == config.end()) {
        std::cout << "Main: No App_config found in config!";
        return EXIT_FAILURE;
    }
    auto app_config = *app_config_it;

    auto model = new Model();
    auto controller = new Controller(*model, app_config);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    /* Make model and controller available in QML */
    engine.rootContext()->setContextProperty("model", model);
    engine.rootContext()->setContextProperty("controller", controller);

    engine.load(QUrl(QStringLiteral("qrc:view/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return QGuiApplication::exec();
}

/**
 * @}
 * @}
 */
