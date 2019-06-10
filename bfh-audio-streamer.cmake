#########################
# User Paths
#########################
set(BASE_PATH /opt/audio-streamer/tools)
set(TOOLCHAIN_PATH ${BASE_PATH}/linaro/gcc-linaro-6.2.1-2016.11-x86_64_arm-linux-gnueabihf)
set(CMAKE_SYSROOT ${BASE_PATH}/rootfs/debian)

# Target
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Toolchain
set(PLATFORM arm-linux-gnueabihf)
set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/bin/${PLATFORM}-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/bin/${PLATFORM}-g++)

set(CMAKE_FIND_ROOT_PATH ${CMAKE_SYSROOT})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Sysroot library paths
link_directories(
        ${CMAKE_SYSROOT}/usr/lib/${PLATFORM}
        ${CMAKE_SYSROOT}/lib/${PLATFORM}
        ${CMAKE_SYSROOT}/local/qt5/lib
)