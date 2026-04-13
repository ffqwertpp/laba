set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD d0edc3af-4c50-42ea-a356-e2862fe7a444)
set(CMAKE_CXX_MODULE_STD ON)
set(LAB_NAME lab1)

add_executable("${LAB_NAME}")

target_compile_features("${LAB_NAME}" PUBLIC cxx_std_23)
target_compile_options("${LAB_NAME}" PRIVATE /utf-8)

target_sources("${LAB_NAME}" 
	PRIVATE 
	source/main.cpp
)