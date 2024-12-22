#include "pch.h"
#include "GLFWCursor.h"
#include "WindowGLFW.h"

namespace Quad
{
    GLFWCursor::GLFWCursor()
    {
    }

    void GLFWCursor::GetPosition(double &x, double &y) const
    {
        glfwGetCursorPos(GetCurrentWindow(), &x, &y);
    }

    bool GLFWCursor::IsClickingOn(const Unit &unit) const
    {
        double mouseX, mouseY;
        GetPosition(mouseX, mouseY);

        int windowHeight = QuadWindow::GetWindow()->GetHeight();
        mouseY = windowHeight - mouseY;

        bool withinX = mouseX >= unit.GetXCoord() &&
                       mouseX <= (unit.GetXCoord() + unit.GetWidth());
        bool withinY = mouseY >= unit.GetYCoord() &&
                       mouseY <= (unit.GetYCoord() + unit.GetHeight());

        bool isClicking = glfwGetMouseButton(GetCurrentWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

        return withinX && withinY && isClicking;
    }

    void GLFWCursor::SetCursorMode(int mode)
    {
        glfwSetInputMode(GetCurrentWindow(), GLFW_CURSOR, mode);
    }

    GLFWwindow *GLFWCursor::GetCurrentWindow() const
    {
        return static_cast<GLFWwindow *>(QuadWindow::GetWindow()->GetImplementation()->GetNativeWindow());
    }
}