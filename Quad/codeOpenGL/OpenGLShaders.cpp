#include "pch.h"
#include "OpenGLShaders.h"
#include "glad/glad.h"
#include "QuadUtilities.h"

namespace Quad {
	OpenGLShaders::OpenGLShaders()
	{
	}
	OpenGLShaders::OpenGLShaders(const std::string& vertexSFile, const std::string& fragmentSFile)
	{
		std::string vertexSCode{ ReadFile(vertexSFile) };
		const char* cVertCode{ vertexSCode.c_str() };
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &cVertCode, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			QUAD_ERROR("ERROR::SHader::vertex::compilation_failed\n" << infoLog);
		}

		std::string fragmentSCode{ ReadFile(fragmentSFile) };
		const char* cFragCode{ fragmentSCode.c_str() };
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &cFragCode, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			QUAD_ERROR("ERROR SHADER FRAGMENT COMPILATION FAILED\n" << infoLog);
		}



		mShaders = glCreateProgram();
		glAttachShader(mShaders, vertexShader);
		glAttachShader(mShaders, fragmentShader);
		glLinkProgram(mShaders);

		glGetProgramiv(mShaders, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaders, 512, NULL, infoLog);
			QUAD_ERROR("ERROR SHADER PROGRAM LINKING FAILED\n" << infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLShaders::LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile)
	{
		if (mShaders != 0)
			glDeleteProgram(mShaders);

		std::string vertexSCode{ ReadFile(vertexSFile) };
		const char* cVertCode{ vertexSCode.c_str() };
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &cVertCode, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			QUAD_ERROR("ERROR::SHader::vertex::compilation_failed\n" << infoLog);
		}

		std::string fragmentSCode{ ReadFile(fragmentSFile) };
		const char* cFragCode{ fragmentSCode.c_str() };
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &cFragCode, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			QUAD_ERROR("ERROR SHADER FRAGMENT COMPILATION FAILED\n" << infoLog);
		}



		mShaders = glCreateProgram();
		glAttachShader(mShaders, vertexShader);
		glAttachShader(mShaders, fragmentShader);
		glLinkProgram(mShaders);

		glGetProgramiv(mShaders, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaders, 512, NULL, infoLog);
			QUAD_ERROR("ERROR SHADER PROGRAM LINKING FAILED\n" << infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	void OpenGLShaders::Bind()
	{
		glUseProgram(mShaders);
	}

	void OpenGLShaders::SetIntUniform(const std::string& uniformName, const std::vector<int>& values)
	{
		glUseProgram(mShaders);
		int location{ glGetUniformLocation(mShaders, uniformName.c_str()) };
		switch (values.size()) {
		case 1:
			glUniform1i(location, values[0]);
			break;
		case 2:
			glUniform2i(location, values[0], values[1]);
			break;
		case 3:
			glUniform3i(location, values[0], values[1], values[2]);
			break;
		case 4:
			glUniform4i(location, values[0], values[1], values[2], values[3]);
			break;
		default:
			QUAD_ERROR("Cannot set integer uniforms of that size");
		}
	}
	void OpenGLShaders::SetIntUniform(const std::string& uniformName, int value)
	{
		glUseProgram(mShaders);
		int location{ glGetUniformLocation(mShaders, uniformName.c_str()) };
		glUniform1i(location, value);
	}
	OpenGLShaders::~OpenGLShaders()
	{
		if (mShaders != 0)
			glDeleteProgram(mShaders);
	}
	std::string OpenGLShaders::ReadFile(const std::string fileName) const
	{
		std::ifstream input{ fileName };

		assert(input);
		 
		std::string result;
		std::string line;

		while (input) {
			line.clear();
			getline(input, line);
			result += line;
			result += "\n";
		}

		input.close();

		return result;
	}
}