#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdio>

#define _width 1024
#define _height 768

void init(void);
void processInput(GLFWwindow*);
void draw(GLFWwindow*);

int main(int argc, char const* argv[])
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	init();

	// Open a window and create its OpenGL context
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* window;
	window = glfwCreateWindow(_width, _height, "Project 01: Hello World", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental = true; // Needed in core profile

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		processInput(window);
		draw(window);
	} while (!glfwWindowShouldClose(window));

	glfwDestroyWindow(window);

	return 0;
}

void init(void)
{
	// require at least OpenGL 3.2
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for OGL3.0+
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);

	// 4x antialiasing
	glfwWindowHint(GLFW_SAMPLES, 4);
	glEnable(GL_MULTISAMPLE);

	// glfwCreateWindow resets the viewport
	// glViewport(0, 0, _width, _height);
}

void draw(GLFWwindow* window)
{
	// Clear the screen.
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(.0f, 1.0f, .0f, .1f);

	// Swap buffers
	glfwSwapBuffers(window);
}

void processInput(GLFWwindow* window)
{
	glfwPollEvents();

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
		return;
	}
}
