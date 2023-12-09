project(calc_lib)

add_library(calc_lib
    engine.cpp
    engine.h
)


target_include_directories(calc_lib PUBLIC .)
target_compile_definitions(calc_lib PUBLIC _USE_MATH_DEFINES)
