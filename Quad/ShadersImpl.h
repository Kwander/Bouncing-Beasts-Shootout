#pragma once

#include "pch.h"

namespace Quad {
	class ShadersImpl {
	public:
		virtual void LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile) = 0;
		virtual void Bind() = 0;
		virtual void SetIntUniform(const std::string& uniformName, const std::vector<int>& values) = 0;
		virtual void SetIntUniform(const std::string& uniformName, int value)  = 0;

		virtual ~ShadersImpl() {};
	};
}