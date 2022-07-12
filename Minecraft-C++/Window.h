#ifndef MINECRAFT_WINDOW_H
#define MINECRAFT_WINDOW_H
#include "core.h"

namespace Minecraft{
	struct Window {
		GLFWwindow* nativeWindow;
		int windowWidth;
		int windowHeight;

		void installMainCallbacks();

		void close();

		static Window* createWindow(int width, int height, const char* title, bool fullScreenMode = false);
		static void freeWindow(Window* window);
	};
}

#endif