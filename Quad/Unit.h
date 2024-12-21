#pragma once

#include "QuadUtilities.h"
#include "Image.h"
#include "pch.h"

namespace Quad {
	class QUAD_API Unit {
	public:
		Unit(const std::string& fileName, int xCoord, int yCoord, bool visible=true);

		int GetWidth() const;
		int GetHeight() const;

		int GetXCoord() const;
		int GetYCoord() const;
		void SetCoords(int x, int y);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);
		bool IsVisible() const;
		void SetVisibility(bool visibility);

	private:
		Image mImage;
		int mXCoord{ 0 };
		int mYCoord{ 0 };
		bool mIsVisible{ true };

		friend bool QUAD_API UnitsOverlap(const Unit& a, const Unit& b);
		friend class Renderer;
	};
	bool QUAD_API UnitsOverlap(const Unit& a, const Unit& b);
}

