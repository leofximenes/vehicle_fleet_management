cmake_minimum_required(VERSION 3.20)
project(VehicleFleetManagement C)

set(CMAKE_C_STANDARD 17)

add_executable(VehicleFleetManagement
        src/main.c
        src/utils/utils.c
        src/vehicles/vehicles.c
        src/menu/menu.c
        src/utils/utils.h
        src/utils/colors.h
)

target_include_directories(VehicleFleetManagement PRIVATE src)