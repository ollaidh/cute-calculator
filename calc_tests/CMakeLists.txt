project(Tests LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets Test QmlIntegration REQUIRED)


set(PROJECT_SOURCES
    main.cpp

    engine_tests.cpp
    engine_tests.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt::Core
    Qt::Test
    calc_lib
)
