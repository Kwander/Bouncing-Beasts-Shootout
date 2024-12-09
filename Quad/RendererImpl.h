#pragma once

#include "Shaders.h"
#include "Image.h"

namespace Quad {
	class RendererImpl {
	public:

		virtual void Draw(Image& pic, int xCoord, int yCoord) = 0;
		virtual void Draw(Image& pic, int xCoord, int yCoord, Shaders& shader) = 0;

		virtual void ClearScreen() = 0;

		virtual ~RendererImpl() {};
	};
}