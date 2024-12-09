#pragma once
#include "pch.h"
#include "QuadUtilities.h"
#include "ImageImpl.h"

namespace Quad {
	class QUAD_API Image {
	public:
		Image();
		Image(const std::string& filePath);
		void LoadImage(const std::string& filePath);

		bool HasImage() const;
		int GetWidth() const;
		int GetHeight() const;

		void Bind();
	private:
		std::unique_ptr<ImageImpl> implementation;

		friend class Renderer;
	};
}