#pragma once

namespace Quad {
	class QuadApplication {
	public:
		void Run();
		virtual void Initialize();
		virtual void Update();
		virtual void Shutdown();
	private:
		bool ShouldContinue{ true };
	};
}