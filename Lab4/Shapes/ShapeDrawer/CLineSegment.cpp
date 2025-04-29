#include "CLineSegment.h"

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor)
	: Shape("line", outlineColor)
	, m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
}

double CLineSegment::GetArea() const
{
	return DEFAULT_AREA;
}

double CLineSegment::GetPerimeter() const
{
	double dx = m_startPoint.m_x - m_endPoint.m_x;
	double dy = m_startPoint.m_y - m_endPoint.m_y;

	return std::sqrt(dx * dx + dy * dy);
}

std::string CLineSegment::ToString() const
{
	std::stringstream result;
	result << Shape::ToString();
	result << "StartPoint: (" << m_startPoint.m_x << ", " << m_startPoint.m_y << ")" << std::endl;
	result << "EndPoint: (" << m_endPoint.m_x << ", " << m_endPoint.m_y << ")" << std::endl;
	result << "Perimeter: " << GetPerimeter() << std::endl;
	result << "Area: " << GetArea() << std::endl;

	return result.str();
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

void CLineSegment::Draw(ICanvas* canvas)
{
	canvas->DrawLine(m_startPoint, m_endPoint, GetOutlineColor());
}
