#include "pch.h"

#include "WindowGLFW.h"
#include "QuadUtilities.h"

namespace Quad {
	WindowGLFW::WindowGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	void WindowGLFW::Create(int width, int height, std::string windowName)
	{
		mWindowPtr = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		if (!mWindowPtr) {
			QUAD_ERROR("shidd no Window pointer available")
		}

		glfwMakeContextCurrent(mWindowPtr);

		glfwSetKeyCallback(mWindowPtr, 
			[](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS) {
					KeyEvent event{ key, KeyEvent::KeyAction::Press };
					mCallbacks.KeyEventHandler(event);
				}
			});
	}
	int WindowGLFW::GetWidth() const
	{
		int width{ 0 }; int height{ 0 };
		glfwGetWindowSize(mWindowPtr, &width, &height);

		return width;
	}
	int WindowGLFW::GetHeight() const
	{
		int width{ 0 }; int height{ 0 };
		glfwGetWindowSize(mWindowPtr, &width, &height);

		return height;
	}
	void WindowGLFW::SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler)
	{
		mCallbacks.KeyEventHandler = newHandler;
	}
	void WindowGLFW::SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler)
	{
		mCallbacks.WindowEventHandler = newHandler;
	}
	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindowPtr);
	}
	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}
}