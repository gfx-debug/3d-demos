include_directories("${CMAKE_CURRENT_SOURCE_DIR}/glew-2.1.0/include")
set(GLEW_SRC
          ${CMAKE_CURRENT_SOURCE_DIR}/glew-2.1.0/include/GL/glew.h
          ${CMAKE_CURRENT_SOURCE_DIR}/glew-2.1.0/src/glew.c
    )

if (UNIX)
    set(GLEW_SRC ${GLEW_SRC}
             ${CMAKE_CURRENT_SOURCE_DIR}/glew-2.1.0/include/GL/glxew.h
       )
else()
    add_definitions(-DGLEW_BUILD)
    set(GLEW_SRC ${GLEW_SRC}
             ${CMAKE_CURRENT_SOURCE_DIR}/glew-2.1.0/include/GL/wglew.h
       )
endif()

add_library(glew-2.1.0 SHARED ${GLEW_SRC})

target_link_libraries(glew-2.1.0  ${OPENGL_LIBRARIES})
set(GLFW_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/internal.h
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/glfw_config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/include/GLFW/glfw3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/include/GLFW/glfw3native.h

    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/context.c
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/input.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/monitor.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/vulkan.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/window.c
)

if (UNIX)
        add_definitions(-D_GLFW_X11)
    set(GLFW_SRC 
            ${GLFW_SRC}
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/x11_platform.h 
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/xkb_unicode.h 
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/posix_time.h
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/posix_thread.h
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/glx_context.h 
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/egl_context.h 
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/osmesa_context.h
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/linux_joystick.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/linux_joystick.h
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/x11_init.c 
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/x11_monitor.c 
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/x11_window.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/xkb_unicode.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/posix_time.c 
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/posix_thread.c 
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/glx_context.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/egl_context.c

            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/osmesa_context.c)
else()
    add_definitions(-D_GLFW_WIN32)
  
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    set(GLFW_SRC
            ${GLFW_SRC}
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/win32_platform.h
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/win32_joystick.h
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/wgl_context.h
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/egl_context.h
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/osmesa_context.h


            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/win32_init.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/win32_joystick.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/win32_monitor.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/win32_time.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/win32_thread.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/win32_window.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/wgl_context.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/egl_context.c
            ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3/src/osmesa_context.c)
endif()


add_library(glfw-3.3  ${GLFW_SRC})