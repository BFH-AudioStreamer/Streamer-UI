# Streamer-UI

![](doc/img/BFH-logo-en.svg)

The Streamer-UI is a QtQML based user application to control a Mopidy music server. It can display title, artist and a timelien of the currently played song, as well as the album art. The playback can be controlled with on screen buttons.

# Structure

- src: C++ Code
    - controller: controller classes and backend connectors
        - data: grouped information for internal data transfer
    - model: data model containing the application information
    - tools: miscellaneous helper classes
- res: QML resources
    - element: custom UI elements
    - font: fonts packed with the application
    - img: images
    - model: data model stored in the UI (to be avoided, move models to C++ classes)
    - view: view screens
- lib: external libraries

# Usage

Thes usage of this application is simple and straigt forward as shown in the image below.
![Streamer-UI Track Information](doc/img/ui-trackinfo.png)

To launch the Streamer-UI you need to provide a valid configuration file named `streamer-ui.conf` placed in the same directory as the application. The configuration contains the information about the used backend conector and port configuration. An example `streamer-ui.conf` is given below:
```json
{
    "Version": 1,
    "App_config": {
        "Backend_connector": "Mopidy_mpd_connector",
        "Mopidy_connector": {
            "hostname": "Audio-Streamer",
            "port": 6680
        },
        "Mpd_connector": {
            "hostname": "localhost",
            "port": 6600
        }
    }
}
```

# Prerequisites

You will need:
- CMake 3.13+
- Qt5Core
- Qt5Quick
- Qt5QuickControls2
- Qt5QML
- Qt5WebSockets
- libmpdclient
- A Mopdy server

## Building

### PC

```sh
mkdir build && cd build
cmake ..
make -j4
```

### Audio-Streamer (iMX6)

Building for the Audio-Streamer requires the complete sysroot and toolchain in the `/opt/audio-streamer/` directory.

```sh
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=bfh-audio-streamer.cmake ..
make -j4
```

# Authors

- Stefan Lüthi (Maintainer), stefan.luethi@students.bfh.ch
- Rafael Klossner (Developer), rafael.klossner@students.bfh.ch

# Contributing

Feel free to contribute code to this project. The C++ code follows the **C++ Core Guildines** which can be found [here](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).

Be sure to document your code with doxygen. The code documentation is build automatically and pushed [here](https://luethi.gitlab.io/streamer-ui/).

# License
This project is licensed under the MIT license. See [LICENSE](LICENSE.md).
