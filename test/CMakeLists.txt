add_executable(c-test)

set_property(TARGET c-test PROPERTY CXX_STANDARD 23)
target_sources(c-test PRIVATE
"main.cpp"
)

target_include_directories(c-test PRIVATE
${CMAKE_SOURCE_DIR}/Spider/src
)

target_link_libraries(c-test
spider
)

target_compile_options(c-test PRIVATE
-Wall
-Werror
)



