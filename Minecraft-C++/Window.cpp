#include "Window.h"
#include "Input.h"

namespace Minecraft {

	static void resizeCallback(GLFWwindow* nativeWindow, int newWidth, int newHeight) {
		Window* window = (Window*)glfwGetWindowUserPointer(nativeWindow);
		window->windowHeight = newHeight;
		window->windowWidth = newWidth;
		glViewport(0, 0, newWidth, newHeight);
	}

	void Window::installMainCallbacks() {
		if (nativeWindow != nullptr) {
			glfwSetKeyCallback(nativeWindow, Input::keyCallback);
			glfwSetCursorPosCallback(nativeWindow, Input::mouseCallback);
			glfwSetMouseButtonCallback(nativeWindow, Input::mouseButtonCallback);
			glfwSetWindowSizeCallback(nativeWindow, resizeCallback);
		}
	}

	void Window::close() {
		if (nativeWindow != nullptr) {
			glfwSetWindowShouldClose(nativeWindow, GLFW_TRUE);
		}
	}

	Window* Window::createWindow(int width, int height, const char* title, bool fullScreenMode) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		Window* res = new Window();
		GLFWmonitor* primaryMonitor = fullScreenMode ? glfwGetPrimaryMonitor() : nullptr;
		res->nativeWindow = glfwCreateWindow(width, height, title, primaryMonitor, nullptr);
		if (res->nativeWindow == nullptr) {
			printf("Failed to create GLFW window\n");
			glfwTerminate();
			return nullptr;
		}
		glfwMakeContextCurrent(res->nativeWindow);
		glfwSetWindowUserPointer(res->nativeWindow, (void*)res);

		res->windowHeight = height;
		res->windowWidth = width;

		return res;
	}

	void Window::freeWindow(Window* window) {
		if (window) {
			glfwDestroyWindow(window->nativeWindow);
			delete window;
		}
	}
}