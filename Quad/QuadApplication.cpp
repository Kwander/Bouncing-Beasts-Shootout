#include "pch.h"

#include "QuadApplication.h"
#include "QuadWindow.h"
#include "Image.h"
#include "Shaders.h"
#include "Renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace Quad
{
	QuadApplication::QuadApplication()
	{
		Quad::QuadWindow::Init();
		Quad::QuadWindow::GetWindow()->CreateWindow(1000, 800, "test");

		Renderer::Init();

		SetWindowEventHandler(
			[this](const WindowEvent &event)
			{ DefaultWindowEventHandler(event); });
	}
	void Quad::QuadApplication::Run()
	{

		Initialize(); // defined by game creators
		int x{100};

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		// Quad::Image pic("../Quad/QuadAssets/Images/cookie.jpg");

		while (mShouldContinue)
		{
			Renderer::ClearScreen();

			Update();

			// Renderer::Draw(pic, x, 100);
			// x += 2;

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			Quad::QuadWindow::GetWindow()->SwapBuffers();
			Quad::QuadWindow::GetWindow()->PollEvents();
		}

		Shutdown();
	}
	void QuadApplication::Initialize()
	{
	}
	void QuadApplication::Update()
	{
	}
	void QuadApplication::Shutdown()
	{
	}

	void QuadApplication::SetKeyEventHandler(const std::function<void(const KeyEvent &)> &newHandler)
	{
		Quad::QuadWindow::GetWindow()->SetKeyEventHandler(newHandler);
	}

	void QuadApplication::SetWindowEventHandler(std::function<void(const WindowEvent &)> newHandler)
	{
		Quad::QuadWindow::GetWindow()->SetWindowEventHandler(newHandler);
	}

	void QuadApplication::DefaultWindowEventHandler(const WindowEvent &event)
	{
		if (event.GetWindowAction() == WindowEvent::WindowAction::Close)
			mShouldContinue = false;
	}

}

/*
Quad::Image pic("Assets/image1.png"};
Quad::Shader shader{"vert.glsl", "frag.glsl"};   Textures prob not used
Quad::Renderer::Get()->Draw(pic, 100, 200, shader);

*/