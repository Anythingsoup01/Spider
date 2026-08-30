add_library(spider STATIC)

set_property(TARGET spider PROPERTY CXX_STANDARD 23)
target_sources(spider PRIVATE
src/Spider/File/FileReader.cpp
src/Spider/Network/Request.cpp
src/Spider/Network/GenericRoutes.cpp
src/Spider/Network/Server.cpp
src/Spider/Format/Header.cpp
)

target_precompile_headers(spider PUBLIC src/spch.h)

target_include_directories(spider PRIVATE
src
)

target_compile_options(spider PRIVATE
-Wall
-Werror
)



