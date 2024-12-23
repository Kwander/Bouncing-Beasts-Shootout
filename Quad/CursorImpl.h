#pragma once
#include "Unit.h"

namespace Quad
{
    class CursorImpl
    {
    public:
        virtual ~CursorImpl() = default;

        virtual void GetPosition(double &x, double &y) const = 0;
        virtual bool IsClickingOn(const Unit &unit) const = 0;
        virtual bool IsClicking() const = 0;
        virtual void SetCursorMode(int mode) = 0;
    };
}