set(SRCS
    "main.cpp"
)
add_executable(c-test ${SRCS})
set_property(TARGET c-test PROPERTY CXX_STANDARD 23)

target_include_directories(c-test PRIVATE
    "${CMAKE_SOURCE_DIR}/Spider/src"
)

target_link_libraries(c-test
    spider
)

target_compile_options(c-test PRIVATE
    -Wall
    -Werror
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
target_compile_options(c-test PRIVATE
    -O0
    -g
)

endif(CMAKE_BUILD_TYPE STREQUAL Debug)
if(CMAKE_BUILD_TYPE STREQUAL Release)
target_compile_options(c-test PRIVATE
    -O2
)

endif(CMAKE_BUILD_TYPE STREQUAL Release)
