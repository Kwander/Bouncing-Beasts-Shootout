#pragma once

#include "QuadUtilities.h"
#include "Unit.h"
#include "pch.h"
#include "CursorImpl.h"

namespace Quad
{
    class QUAD_API Cursor
    {
    public:
        Cursor();

        void GetPosition(int &x, int &y) const;
        bool IsClickingOn(const Unit &unit) const;
        bool IsClicking() const;
        void SetCursorMode(int mode);

    private:
        std::unique_ptr<CursorImpl> mImplementation;
    };
}