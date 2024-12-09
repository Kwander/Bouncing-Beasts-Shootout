#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform ivec2 ScreenDim;

void main(){
	gl_Position = vec4(2*aPos.x/ScreenDim.x -1, 2*aPos.y/ScreenDim.y - 1, 0.0, 1.0);
	TexCoord = aTexCoord;
}