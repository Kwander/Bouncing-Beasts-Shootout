#pragma once
#include "pch.h"
#include "QuadUtilities.h"
#include "Image.h"
#include "Shaders.h"
#include "RendererImpl.h"

namespace Quad {
	class QUAD_API Renderer {
	public:
		static void Init();
		

		static void Draw(Image& pic, int xCoord, int yCoord);
		static void Draw(Image& pic, int xCoord, int yCoord, Shaders shaders);


		static void ClearScreen();
	private:
		std::unique_ptr<RendererImpl> mImplementation;
		inline static std::unique_ptr<Renderer> mInstance;
		Renderer();
	};
}