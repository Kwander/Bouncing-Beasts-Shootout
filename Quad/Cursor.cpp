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

    void Cursor::GetPosition(int &x, int &y) const
    {
        double xPos, yPos;
        mImplementation->GetPosition(xPos, yPos);
        x = static_cast<int>(xPos);
        y = static_cast<int>(yPos);
    }

    bool Cursor::IsClickingOn(const Unit &unit) const
    {
        return mImplementation->IsClickingOn(unit);
    }

    void Cursor::SetCursorMode(int mode)
    {
        mImplementation->SetCursorMode(mode);
    }

    bool Cursor::IsClicking() const
    {
        return mImplementation->IsClicking();
    }
}