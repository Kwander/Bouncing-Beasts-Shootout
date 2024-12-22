#include "pch.h"
#include "Cursor.h"
#include "codeGLFW/GLFWCursor.h"

namespace Quad
{
    Cursor::Cursor()
    {
#ifdef QUAD_GLFW
        mImplementation = std::unique_ptr<CursorImpl>{new GLFWCursor()};
#else
#only_glfw_is_supported_so_far
#endif
    }

    void Cursor::GetPosition(double &x, double &y) const
    {
        mImplementation->GetPosition(x, y);
    }

    bool Cursor::IsClickingOn(const Unit &unit) const
    {
        return mImplementation->IsClickingOn(unit);
    }

    void Cursor::SetCursorMode(int mode)
    {
        mImplementation->SetCursorMode(mode);
    }
}