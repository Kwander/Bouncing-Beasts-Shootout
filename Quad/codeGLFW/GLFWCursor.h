#pragma once

#include "../CursorImpl.h"
#include "../QuadWindow.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace Quad
{
    class GLFWCursor : public CursorImpl
    {
    public:
        GLFWCursor();

        virtual void GetPosition(double &x, double &y) const override;
        virtual bool IsClickingOn(const Unit &unit) const override;
        virtual bool IsClicking() const override;
        virtual void SetCursorMode(int mode) override;

    private:
        GLFWwindow *GetCurrentWindow() const;
    };
}