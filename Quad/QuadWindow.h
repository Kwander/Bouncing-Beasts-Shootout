#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "QuadUtilities.h"
#include "QuadEvents.h"

namespace Quad
{
	class QUAD_API QuadWindow
	{
	public:
		static void Init();
		static std::unique_ptr<QuadWindow> &GetWindow();

		void CreateWindow(int width, int height, std::string windowName);
		int GetWidth() const;
		int GetHeight() const;

		void SetKeyEventHandler(const std::function<void(const KeyEvent &)> &newHandler);
		void SetWindowEventHandler(std::function<void(const WindowEvent &)> newHandler);

		void SwapBuffers();
		void PollEvents();

		WindowImpl *GetImplementation() const { return implementation.get(); }

	private:
		std::unique_ptr<WindowImpl> implementation{nullptr};

		QuadWindow();

		inline static std::unique_ptr<QuadWindow> instance;
	};
}