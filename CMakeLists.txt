project(BodyIndex)
cmake_minimum_required(VERSION 2.8)

# Look for OpenCVConfig.cmake
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})
    message( STATUS "use OpenCV " ${OpenCV_VERSION_MAJOR} "." ${OpenCV_VERSION_MINOR} "." ${OpenCV_VERSION_PATCH})

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME}  ${OpenCV_LIBS})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

