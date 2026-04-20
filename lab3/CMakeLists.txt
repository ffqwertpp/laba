set(LAB_NAME lab3)

add_executable("${LAB_NAME}")

target_sources("${LAB_NAME}"
    PRIVATE
        source/main.cpp
    PRIVATE FILE_SET cxx_modules
        TYPE CXX_MODULES
        FILES
            source/pawn.cppm
            source/menus.cppm
)