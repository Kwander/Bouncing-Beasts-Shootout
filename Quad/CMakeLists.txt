set (SOURCE_FILES
	EntryPoint.h
	include/Quad.h
	QuadApplication.h
	QuadApplication.cpp
)

add_library(Quad STATIC ${SOURCE_FILES})

target_compile_definitions(Quad
		PRIVATE
			QUAD_LIB
		PUBLIC
			$<$<CONFIG:Debug>:QUAD_DEBUG=2>
			$<$<CONFIG:RelWithDebInfo>:QUAD_DEBUG=1>
			QUAD_OPENGL_STBI
)

if(MSVC)
	target_compile_definitions(Quad PUBLIC QUAD_MS_COMPILER)
endif()

target_precompile_headers(Quad PRIVATE pch.h)

target_link_libraries(Quad glfw)