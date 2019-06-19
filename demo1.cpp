#include <GLFW/glfw3.h>

int main()
{
	GLFWwindow * win = nullptr;
	glfwInit();

	glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	win = glfwCreateWindow(1024, 800, "OpenGL", nullptr, nullptr);

	glfwMakeContextCurrent(win);

	while (!glfwWindowShouldClose(win))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(win);
	}

	glfwTerminate();
}