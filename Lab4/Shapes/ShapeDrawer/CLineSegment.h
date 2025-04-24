#pragma once

#include "CPoint.h"
#include "Shape.h"

class CLineSegment : public Shape
{
public:
	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

	void Draw(std::shared_ptr<ICanvas> canvas) override;

private:
	CPoint m_startPoint, m_endPoint;
	const double DEFAULT_AREA = 0;
};
