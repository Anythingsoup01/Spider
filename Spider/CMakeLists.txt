set(SRCS
    "src/Spider/Network/Server.cpp"
    "src/Spider/Network/Request.cpp"
)
add_library(spider STATIC ${SRCS})
set_property(TARGET spider PROPERTY CXX_STANDARD 23)

target_precompile_headers(spider PUBLIC src/spch.h)
target_include_directories(spider PRIVATE
    "src"
)

target_compile_options(spider PRIVATE
    -Wall
    -Werror
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
target_compile_options(spider PRIVATE
    -O0
    -g
)

endif(CMAKE_BUILD_TYPE STREQUAL Debug)
if(CMAKE_BUILD_TYPE STREQUAL Release)
target_compile_options(spider PRIVATE
    -O2
)

endif(CMAKE_BUILD_TYPE STREQUAL Release)
