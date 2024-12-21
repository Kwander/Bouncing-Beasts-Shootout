#include "pch.h"
#include "Unit.h"

namespace Quad {
	bool Unit::IsVisible() const
	{
		return mIsVisible;
	}
	void Unit::SetVisibility(bool visibility)
	{
		mIsVisible = visibility;
	}
	Unit::Unit(const std::string& fileName, int xCoord, int yCoord, bool visible) : mImage(fileName), mXCoord(xCoord), mYCoord(yCoord), mIsVisible(visible)
	{
	}
	int Unit::GetWidth() const
	{
		return mImage.GetWidth();
	}
	int Unit::GetHeight() const
	{
		return mImage.GetHeight();
	}
	int Unit::GetXCoord() const
	{
		return mXCoord;
	}
	int Unit::GetYCoord() const
	{
		return mYCoord;
	}
	void Unit::SetCoords(int x, int y)
	{
		mXCoord = x;
		mYCoord = y;
	}
	void Unit::UpdateXCoord(int amount)
	{
		mXCoord += amount;
	}
	void Unit::UpdateYCoord(int amount)
	{
		mYCoord += amount;
	}
	bool QUAD_API UnitsOverlap(const Unit& a, const Unit& b)
	{
		int left_a{ a.mXCoord };
		int right_a{ a.mXCoord + a.mImage.GetWidth() };
		int left_b{ b.mXCoord };
		int right_b{ b.mXCoord + b.mImage.GetWidth() };

		bool x_intersetcion{ (left_a <= left_b and left_b <= right_a) or (left_b <= left_a and left_a <= right_b) };

		int bot_a{ a.mYCoord };
		int top_a{ a.mYCoord + a.mImage.GetHeight() };
		int bot_b{ b.mYCoord };
		int top_b{ b.mYCoord + b.mImage.GetHeight() };

		bool y_intersection{ (bot_a <= bot_b and bot_b <= top_a) or (bot_b <= bot_a and bot_a <= top_b) };

		return y_intersection and x_intersetcion;
	}
}
