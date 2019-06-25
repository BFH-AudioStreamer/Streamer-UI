/**
 *******************************************************************************
 * @addtogroup Config_loader
 * @{
 * @brief Load a JSON based configuration file
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

#include <fstream>
#include <iostream>
#include "Config_loader.h"

/**
 * @brief Loads a JSON formattet  configuration file
 * @param path Path to the file including the file extension
 * @return config file as nlohmann::json object
 */
json Config_loader::load(std::string path) {
    std::ifstream config_file(path);
    json config_json;
    try {
        config_json = json::parse(config_file);
    }
    catch (std::exception e) {
        std::cout << "Config_loader: Config file at '" << path << "' not found" <<
                  std::endl;
    }
    return config_json;
}


/** @} */

