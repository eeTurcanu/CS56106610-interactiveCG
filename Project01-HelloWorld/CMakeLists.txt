cmake_minimum_required (VERSION 3.8)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

add_definitions(-DGLFW_DLL)
add_definitions(-DGLEW_STATIC)

add_definitions(-D_WIN32)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs/x86)

link_directories(${LIB_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

project(${ProjectId})

find_package(OpenGL REQUIRED)

# Add source to this project's executable.
add_executable(${ProjectId} "main.cpp")

target_link_libraries(${ProjectId} glew32s)
target_link_libraries(${ProjectId} glfw3dll)
target_link_libraries(${ProjectId} OpenGL::GL)

add_custom_command(
	TARGET ${ProjectId} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"${LIB_DIR}/glew32.dll"
			"${LIB_DIR}/glfw3.dll"
			$<TARGET_FILE_DIR:Project01-HelloWorld>
)
