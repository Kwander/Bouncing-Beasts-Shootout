#include "pch.h"
#include "QuadEvents.h"

namespace Quad {
	KeyEvent::KeyEvent(int keyCode, KeyEvent::KeyAction action) : mKeyCode(keyCode), mAction()
	{ 
	}
	int KeyEvent::GetKeyCode() const
	{
		return mKeyCode;
	}
	KeyEvent::KeyAction KeyEvent::GetKeyAction() const
	{
		return mAction;
	}
	WindowEvent::WindowEvent(WindowAction action) :mAction(action)
	{
	}
	WindowEvent::WindowAction WindowEvent::GetWindowAction() const
	{
		return mAction;
	}
}