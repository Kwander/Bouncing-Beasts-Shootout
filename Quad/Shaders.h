#pragma once

#include "QuadUtilities.h"
#include "ShadersImpl.h"

namespace Quad {
	class QUAD_API Shaders {
	public:
		Shaders();
		Shaders(const std::string& vertexSFile, const std::string& fragmentSFile);
		void LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile);

		void Bind();
		void SetIntUniform(const std::string& uniformName, const std::vector<int>& values);
		void SetIntUniform(const std::string& uniformName, int value);

	private:
		std::unique_ptr<ShadersImpl> implementation;
		std::string ReadFile(const std::string fileName) const;

	};
}