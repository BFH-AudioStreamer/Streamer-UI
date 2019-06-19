################################################################################
# Project Settings
################################################################################
cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)

project(Streamer-UI)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
file(GLOB_RECURSE HEADERS "*.hpp" "*.h")
file(GLOB SOURCES
        "src/*.cpp"
        "src/*.h"
        "src/controller/*.cpp"
        "src/controller/*.h"
        "src/controller/data/*.cpp"
        "src/controller/data/*.h"
        "src/model/*.cpp"
        "src/model/*.h"
        "src/tools/*.cpp"
        "src/tools/*.h"
        "res/*.qrc"
)

################################################################################
# Macros
################################################################################
# QtCreator remote upload settings
file(WRITE "${CMAKE_SOURCE_DIR}/QtCreatorDeployment.txt" "/usr/local/bin\n")

macro(add_deployment_file SRC DEST)
    file(RELATIVE_PATH path ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
    file(APPEND "${CMAKE_SOURCE_DIR}/QtCreatorDeployment.txt" "${path}/${SRC}:${DEST}\n")
endmacro()

macro(add_deployment_directory SRC DEST)
    file(GLOB_RECURSE files RELATIVE "${CMAKE_CURRENT_BINARY_DIR}" "${SRC}/*")
    foreach(filename ${files})
        get_filename_component(path ${filename} PATH)
        add_deployment_file("${filename}" "${DEST}/${path}")
    endforeach(filename)
endmacro()

set(REMOTE_USER audiostreamer)
set(REMOTE_HOST Audio-Streamer)
set(REMOTE_DIR /usr/local/bin)

################################################################################
# Dependencies
################################################################################
# Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Core Quick QuickControls2 WebSockets REQUIRED)
set(QT_MISSING_DEPENCIES
        GLESv2
        drm
        dl
        rt
        z
        png
        ICU::data
        ICU::i18n
        ICU::uc
        glapi
)

# MPD Client
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")
find_package(LibMPDClient REQUIRED)
include_directories(${LIBMPDCLIENT_INCLUDE_DIR})

# nlohmann JSON library
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(lib/json)

################################################################################
# Executable
################################################################################
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# Enable QML bebugging only on debug builds
if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
endif()

################################################################################
# Link Dependencies
################################################################################

find_package(ICU COMPONENTS data i18n uc)
# added manual symlink for glapi.so -> glapi.so.0

target_link_libraries(${CMAKE_PROJECT_NAME}
        pthread
        #${QT_MISSING_DEPENCIES}
        Qt5::Core
        Qt5::Qml
        Qt5::Quick
        Qt5::WebSockets

        ${LIBMPDCLIENT_LIBRARY}
        nlohmann_json::nlohmann_json
)
