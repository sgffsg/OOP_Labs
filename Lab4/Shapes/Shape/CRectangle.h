#pragma once

#include "CPoint.h"
#include "SolidShape.h"

class CRectangle : public SolidShape
{
public:
	CRectangle(CPoint leftTopPoint, double height, double width, uint32_t outlineColor, uint32_t fillColor);
	
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	double GetHeight() const;
	double GetWidth() const;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	
private:
	CPoint m_leftTopPoint;
	double m_height;
	double m_width;
};
