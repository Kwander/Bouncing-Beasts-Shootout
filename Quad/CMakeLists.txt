set (SOURCE_FILES
	EntryPoint.h
	include/Quad.h
	QuadApplication.h
	QuadApplication.cpp
	Image.h
	Image.cpp
	ImageImpl.h
	codeOpenGL/OpenGLImage.h
	codeOpenGL/OpenGLImage.cpp
	Shaders.h
	Shaders.cpp
	ShadersImpl.h
	codeOpenGL/OpenGLShaders.h
	codeOpenGL/OpenGLShaders.cpp
	Renderer.h
	Renderer.cpp
	RendererImpl.h
	codeOpenGL/OpenGLRenderer.h
	codeOpenGL/OpenGLRenderer.cpp
	QuadWindow.h
	QuadWindow.cpp
	WindowImpl.h
	codeGLFW/WindowGLFW.h
	codeGLFW/WindowGLFW.cpp
	KeyCodes.h
	QuadEvents.h
	QuadEvents.cpp
	QuadUtilities.h
	Unit.h
	Unit.cpp
	Cursor.h
	Cursor.cpp
	CursorImpl.h
	codeGLFW/GLFWCursor.h
	codeGLFW/GLFWCursor.cpp
)

add_library(Quad SHARED ${SOURCE_FILES})

target_compile_definitions(Quad
		PRIVATE
			QUAD_LIB
		PUBLIC
			$<$<CONFIG:Debug>:QUAD_DEBUG=2>
			$<$<CONFIG:RelWithDebInfo>:QUAD_DEBUG=1>
			QUAD_OPENGL_STBI
			QUAD_GLFW
)

if(MSVC)
	target_compile_definitions(Quad PUBLIC QUAD_MS_COMPILER)
endif()

target_precompile_headers(Quad PRIVATE pch.h)

target_link_libraries(Quad glfw glad stbi)

include_directories("../glad/include/")
include_directories("../glfw/include/")
include_directories("../stbi")
include_directories("../Quad/")