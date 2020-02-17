project(opengl-demos)

if (UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

find_package(OpenGL)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(3rdparty)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glfw-3.3/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glew-2.1.0/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

add_definitions(-DARCBALL_CAMERA_IMPLEMENTATION)

function(set_app name src)
	add_executable(${name} ${src})
	add_dependencies(${name} glfw-3.3 glew-2.1.0)
	if (WIN32)
		target_link_libraries(${name} glfw-3.3 glew-2.1.0 ${OPENGL_LIBRARIES})
	else()
		target_link_libraries(${name} glfw-3.3 glew-2.1.0 ${OPENGL_LIBRARIES} X11 pthread)
	endif()
endfunction()

set(
	DEMO1_SRC
	demo1.cpp
)
set_app(demo1 ${DEMO1_SRC})

set(
	DEMO2_SRC
	demo2.cpp
)
set_app(demo2 ${DEMO1_SRC})