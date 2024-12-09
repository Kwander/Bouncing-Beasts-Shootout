#pragma once

#include "../ShadersImpl.h"

namespace Quad {
	class OpenGLShaders : public ShadersImpl {
	public:
		OpenGLShaders();
		OpenGLShaders(const std::string& vertexSFile, const std::string& fragmentSFile);


		virtual void LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile) override;
		virtual void Bind() override;
		virtual void SetIntUniform(const std::string& uniformName, const std::vector<int>& values) override;
		virtual void SetIntUniform(const std::string& uniformName, int value) override;

		~OpenGLShaders();

	private:
		unsigned int mShaders{ 0 };

		std::string ReadFile(const std::string fileName) const;
	};
}