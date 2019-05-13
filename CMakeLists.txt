cmake_minimum_required(VERSION 3.12)
project(EnigmaGUI)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(SDL2_GFX "/Users/hordon/SDL2_plugins/gfx")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL_MIXER_INCLUDE_DIR})

include_directories(${SDL2_GFX}/inc)
file(GLOB gfx_inc "${SDL2_GFX}/inc/*.h")
file(GLOB gfx_src "${SDL2_GFX}/src/*.c")

# Change this to the name of the directory that contains your code
set(PROJECT_LIB_NAME appLibrary)

# Change this to the name of the directory that contains your tests
set(PROJECT_TESTS_NAME appTests)

# Change this to the path where you extracted the Google Test files to
set(PATH_TO_GOOGLETEST "/Users/hordon/Desktop/GreenFox/googletest")

# The next line creates an executable file from main.cpp with the same name as your project
add_executable(${PROJECT_NAME} main.cpp ${gfx_inc} ${gfx_src})

# This block includes the subdirectories containing your code and tests
include_directories(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_TESTS_NAME})

# This line links your code to the main executable
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIB_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL_MIXER_LIBRARIES})