#pragma once

#include "QuadUtilities.h"


namespace Quad {
	class QUAD_API KeyEvent {
	public:
		enum class KeyAction {
			Press, Release, Repeat
		};

		KeyEvent(int keyCode, KeyAction action = KeyAction::Press);
		
		int GetKeyCode() const;
		KeyAction GetKeyAction() const;

	private:
		int mKeyCode{ -1 };
		KeyAction mAction{ KeyAction::Press };
	};

	class QUAD_API WindowEvent {
	public:
		enum class WindowAction {
			Close, Minimize, Maximize, Resize
		};
		WindowEvent(WindowAction action);

		WindowAction GetWindowAction() const;

	private:
		WindowAction mAction{ WindowAction::Resize };


	};
}