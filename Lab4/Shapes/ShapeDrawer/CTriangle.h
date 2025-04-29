#pragma once

#include "CPoint.h"
#include "SolidShape.h"

class CTriangle : public SolidShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillColor);
	
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

	void Draw(ICanvas* canvas) override;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;

	double GetTriangleSideLength(const CPoint& vertex1, const CPoint& vertex2);
};
