#include "QuadApplication.h"

namespace Quad {
	void Quad::QuadApplication::Run()
	{
		Initialize();

		while (ShouldContinue) {
			Update();
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
}