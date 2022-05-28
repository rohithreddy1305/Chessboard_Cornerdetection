cmake_minimum_required(VERSION 3.4...3.18)
project(chessboard)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")

include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/src
)

add_library(${PROJECT_NAME} SHARED
    src/Chessboard.cpp
    src/Chessboard.h
    src/ChessboardCorner.h
    src/ChessboardQuad.h
    src/Spline.h
)

add_executable(test_chessboard src/test_chessboard.cpp)
target_link_libraries(test_chessboard ${PROJECT_NAME})
target_link_libraries(test_chessboard ${OpenCV_LIBS})
