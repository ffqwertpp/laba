set(LAB_NAME lab2)

add_executable("${LAB_NAME}")

target_sources("${LAB_NAME}" 
    PRIVATE
    source/main.cpp
    PRIVATE FILE_SET CXX_MODULES
    TYPE CXX_MODULES
    FILES
    source/funcs.cppm
)