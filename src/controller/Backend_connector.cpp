/**
 *******************************************************************************
 * @addtogroup Backend_connector
 * @{
 * @brief Factory creating backend connectors from app configuration
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

#include "Backend_connector.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief Reads backend class name from config and creates specified backend
 *        connector
 *
 * The application configuration must specify a backend connector as shown in
 * the example below:
 * @code{.json}
 * {
 *     "Backend_connector": "Mopidy_mpd_connector"
 * }
 * @endcode
 * @param app_config Application configuration object
 * @return std::unique_ptr<I_backend_connector> Pointer the instantiated backend
 *         connector
 */
std::unique_ptr<I_backend_connector> Backend_connector::create(const json& app_config) {
    /* parse config and create backend connector */
    auto connector_it = app_config.find("Backend_connector");
    if (connector_it==app_config.end()) {
        std::cout << "Backend_connector: No backend connector specified in config!"
                  << std::endl;
        return nullptr;
    }

    std::string connector = *connector_it;

    /* check for type of backend connector, then instantiate it */
    std::unique_ptr<I_backend_connector> backend_connector = nullptr;
    if (connector=="Mopidy_mpd_connector") {
        backend_connector = std::make_unique<Mopidy_mpd_connector>(
                Mopidy_mpd_connector(app_config));
    }
    return backend_connector;
}

/** @} */
