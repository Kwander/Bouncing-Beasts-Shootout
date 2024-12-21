#pragma once
#include "pch.h"
#include "QuadUtilities.h"
#include "QuadEvents.h"

constexpr int FPS_RATE{ 60 };

namespace Quad {
	class QUAD_API QuadApplication {
	public:
		QuadApplication();

		void Run();
		virtual void Initialize();
		virtual void Update();
		virtual void Shutdown();

		void SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler);
		void SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler);

		void DefaultWindowEventHandler(const WindowEvent& event);

	private:
		bool mShouldContinue{ true };

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS_RATE };
	};
}