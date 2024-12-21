#include "pch.h"

#include "OpenGLRenderer.h"
#include "glad/glad.h"
#include "QuadWindow.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace Quad {
	OpenGLRenderer::OpenGLRenderer()
	{
		// start glad
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			QUAD_ERROR("Failed to initialize GLAD");
		}

		mDefaultShaders.LoadShaders("../Quad/QuadAssets/Shaders/defaultVertexShader.glsl", "../Quad/QuadAssets/Shaders/defaultFragmentShader.glsl");


		//create opengl objects
		glGenVertexArrays(1, &mVAO);
		glBindVertexArray(mVAO);

		glGenBuffers(1, &mVBO);
		glBindBuffer(GL_ARRAY_BUFFER, mVBO);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float))); // possibly WRONG it's out of the screen hes recording in tooo zoomed in.
		glEnableVertexAttribArray(1);

		glGenBuffers(1, &mEBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);

		//enable transparency
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	void OpenGLRenderer::Draw(Image& pic, int xCoord, int yCoord)
	{
		float vertices[] = {
			xCoord, yCoord , 0.0f, 0.0f, 
			xCoord, yCoord + pic.GetHeight() , 0.0f, 1.0f, 
			xCoord + pic.GetWidth(), yCoord + pic.GetHeight() , 1.0f, 1.0f, 
			xCoord + pic.GetWidth(), 100.0f , 1.0f, 0.0f
		};

		unsigned int indices[] = {
			0, 1, 2, //first triangle
			0, 2, 3 //second triangle
		};

		
		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


		mDefaultShaders.Bind();
		mDefaultShaders.SetIntUniform("ScreenDim", {QuadWindow::GetWindow()->GetWidth(), QuadWindow::GetWindow()->GetHeight() });
		glBindVertexArray(mVAO);
		pic.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		
	}
	void OpenGLRenderer::Draw(Image& pic, int xCoord, int yCoord, Shaders& shader)
	{
		float vertices[] = {
	xCoord, yCoord , 0.0f, 0.0f,
	xCoord, yCoord + pic.GetHeight() , 0.0f, 1.0f,
	xCoord + pic.GetWidth(), yCoord + pic.GetHeight() , 1.0f, 1.0f,
	xCoord + pic.GetWidth(), 100.0f , 1.0f, 0.0f
		};

		unsigned int indices[] = {
			0, 1, 2, //first triangle
			0, 2, 3 //second triangle
		};


		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


		shader.Bind();
		glBindVertexArray(mVAO);
		pic.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	}
	void OpenGLRenderer::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}