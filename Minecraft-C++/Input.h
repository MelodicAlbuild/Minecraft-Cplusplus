#ifndef MINECRAFT_INPUT_H
#define MINECRAFT_INPUT_H
#include "core.h"

namespace Minecraft {
	namespace Input {
		extern bool keyPressedData[GLFW_KEY_LAST];
		extern bool mouseButtonPressedData[GLFW_MOUSE_BUTTON_LAST];
		extern float mouseX;
		extern float mouseY;
		extern float mouseScrollX;
		extern float mouseScrollY;

		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouseCallback(GLFWwindow* window, double xpos, double ypos);
		void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

		bool isKeyDown(int key);
		bool isMouseButtonDown(int mouseButton);
	}
}

#endif