# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 
# # ==== ==== ==== ====       Resources       ==== ==== ==== ==== 
# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 
# # we yoink this from:
# #       https://github.com/raysan5/raylib/wiki/Working-with-CMake
# #       https://github.com/raysan5/raylib/blob/master/projects/CMake/CMakeLists.txt
# #       https://github.com/brunosxs/raylib-raygui-cmake-template/blob/master/CMakeLists.txt

# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 
# # ==== ==== ==== ====   Setup environment   ==== ==== ==== ==== 
# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 

# cmake_minimum_required(VERSION 3.5) # FetchContent is available in 3.11+

# project(csv_handler C CXX) # name our project

# set(CMAKE_C_STANDARD 11) # Requires C11 standard
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../dist/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../dist/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../dist)
# set(BUILD_RPATH_USE_ORIGIN TRUE)
# # Generate compile_commands.json
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_BUILD_TYPE Debug)

# set(RAYLIB_VERSION 4.2.0)
# set(RAYGUI_VERSION 3.2)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -ggdb")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -ggdb -std=c++20")


# option(USE_RAYGUI "Download and include Raygui" ON)

# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 
# # ==== ==== ==== ====   Setup raylib info   ==== ==== ==== ==== 
# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 

# # setup raylib pathings
# set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
# # add_subdirectory(external/raylib external/raylib/bin)
# set(BUILD_RAYGUI_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build raygui examples
# # add_subdirectory(external/raygui/projects/CMake)

# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 
# # ==== ==== ==== ====  Setup project info   ==== ==== ==== ==== 
# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 

# set(SOURCES
#     Main.cpp
# )


# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 
# # ==== ==== ==== ====     Dependencies      ==== ==== ==== ==== 
# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 

# # try get raylib
# find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
# find_package(raygui ${RAYGUI_VERSION} QUIET) # QUIET or REQUIRED



# # handle getting raylib
# if (NOT raylib_FOUND) # If there's none, fetch and build raylib
#   include(FetchContent)
#   FetchContent_Declare(
#     raylib
#     GIT_REPOSITORY https://github.com/raysan5/raylib.git
#     GIT_TAG ${RAYLIB_VERSION}
#   )
#   FetchContent_GetProperties(raylib)
#   if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
#     set(FETCHCONTENT_QUIET NO)
#     FetchContent_Populate(raylib)
#     add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
#   endif()
# endif()


# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 
# # ==== ==== ==== ====   Project creation    ==== ==== ==== ==== 
# # ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 

# #set(raylib_VERBOSE 1)
# # add in raylib libraries
# target_link_libraries(${PROJECT_NAME} raylib)

# # add personal libraries
# target_include_directories(${PROJECT_NAME} PUBLIC include)


# add_executable(${PROJECT_NAME} ${SOURCES})

# if(${USE_RAYGUI})
#   add_compile_definitions(USE_RAYGUI)
#   include(ExternalProject)

#   # if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/raygui")
#       ExternalProject_Add(raygui
#           GIT_REPOSITORY "https://github.com/raysan5/raygui.git"
#           SOURCE_DIR "${PROJECT_SOURCE_DIR}/external/raygui"
#           SOURCE_SUBDIR "projects/CMake"
#           CMAKE_ARGS
#               -DBUILD_RAYGUI_EXAMPLES=OFF
#               -DCMAKE_INSTALL_PREFIX=${PROJECT_SOURCE_DIR}
#       )
#   # endif()
# endif()



# # use this for web raylib stuffers
# # refer to: https://github.com/raysan5/raylib/tree/master/projects/CMake
# # # Web Configurations
# # if (${PLATFORM} STREQUAL "Web")
# #     # Tell Emscripten to build an example.html file.
# #     set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
# # endif()

# # Checks if OSX and links appropriate frameworks (Only required on MacOS)
# if (APPLE)
#     target_link_libraries(${PROJECT_NAME} "-framework IOKit")
#     target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
#     target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
# endif()


# ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 
# ==== ==== ==== ====     newer version     ==== ==== ==== ==== 
# ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ==== 

cmake_minimum_required(VERSION 3.5)
project(csv_handler)

# find_package(raylib 4.2.0 REQUIRED) # Requires at least version 3.0

set(CMAKE_C_STANDARD 11) # Requires C11 standard
set(CMAKE_CXX_STANDARD 20) # Requires C11 standard


# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -ggdb -std=c11 -Wdeprecated-enum-compare-conditional")
# set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -ggdb -std=c11 -Wdeprecated-enum-compare-conditional")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -ggdb -std=c++20 -Wdeprecated-enum-compare-conditional")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -ggdb -std=c++20 -Wdeprecated-enum-compare-conditional")

add_compile_definitions(USE_RAYGUI)

option(USE_RAYGUI "Download and include Raygui" ON)

# TODO: need to add some way to handle retreiving raylib/raygui

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
add_subdirectory(external/raylib-4.2.0 external/raylib-4.2.0/bin)
set(BUILD_RAYGUI_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build raygui examples
add_subdirectory(external/raygui-3.2/projects/CMake)






set(SOURCE_LIST
  Main.cpp
)

# add files
add_executable(${PROJECT_NAME} ${SOURCE_LIST})



target_compile_options(${PROJECT_NAME} PRIVATE -Wno-deprecated)





target_link_libraries(${PROJECT_NAME} raylib raygui)










# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()