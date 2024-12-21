#pragma once

#include "../RendererImpl.h"
#include "Shaders.h"

namespace Quad {
	class OpenGLRenderer : public RendererImpl {
	public:
		OpenGLRenderer();

		virtual void Draw(Image& pic, int xCoord, int yCoord) override;
		virtual void Draw(Image& pic, int xCoord, int yCoord, Shaders& shader) override;

		virtual void ClearScreen() override;


	private:
		Shaders mDefaultShaders;
		unsigned int mVBO{ 0 };
		unsigned int mVAO{ 0 };
		unsigned int mEBO{ 0 };

	};
}