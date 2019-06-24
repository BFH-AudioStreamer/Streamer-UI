/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup tools
 * @{
 * @defgroup Config_loader
 * @{
 ******************************************************************************/
#pragma once

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief
 */
class Config_loader {
public:
    static json load(std::string path);
};

/**
 * @}
 * @}
 * @} */