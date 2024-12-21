#include "pch.h"
#include "QuadWindow.h"
#include"codeGLFW/WindowGLFW.h"

namespace Quad {
	QuadWindow::QuadWindow()
	{
#ifdef QUAD_GLFW
		implementation = std::unique_ptr < WindowImpl > { new WindowGLFW };
#else
	#windowimplementation_isnt_chosen
#endif


	}
	void QuadWindow::Init()
	{
		if(instance==nullptr)
			instance = std::unique_ptr<QuadWindow>{ new QuadWindow };
	}
	std::unique_ptr<QuadWindow>& QuadWindow::GetWindow()
	{
		return instance;
		// TODO: insert return statement here
	}
	void QuadWindow::CreateWindow(int width, int height, std::string windowName)
	{
		implementation->Create(width, height, windowName);
	}
	int QuadWindow::GetWidth() const
	{
		return implementation->GetWidth();
	}
	int QuadWindow::GetHeight() const
	{
		return implementation->GetHeight();
	}
	void QuadWindow::SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler)
	{
		implementation->SetKeyEventHandler(newHandler);
	}
	void QuadWindow::SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler)
	{
		implementation->SetWindowEventHandler(newHandler);
	}
	void QuadWindow::SwapBuffers()
	{
		implementation->SwapBuffers();
	}
	void QuadWindow::PollEvents()
	{
		implementation->PollEvents();
	}
}

