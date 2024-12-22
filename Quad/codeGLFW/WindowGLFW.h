#pragma once

#include "../WindowImpl.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "pch.h"
#include "QuadEvents.h"

namespace Quad
{
	class WindowGLFW : public WindowImpl
	{
	public:
		WindowGLFW();
		virtual void Create(int width, int height, std::string windowName) override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		virtual void SetKeyEventHandler(const std::function<void(const KeyEvent &)> &newHandler) override;
		virtual void SetWindowEventHandler(std::function<void(const WindowEvent &)> newHandler) override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual void *GetNativeWindow() const override { return mWindowPtr; }

	private:
		GLFWwindow *mWindowPtr{nullptr};

		struct Callbacks
		{
			std::function<void(const KeyEvent &)> KeyEventHandler{[](const KeyEvent &) {}};
			std::function<void(const WindowEvent &)> WindowEventHandler{[](const WindowEvent &) {}};
		} mCallbacks;
	};
}