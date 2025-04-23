#include "CLineSegment.h"

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
	std::stringstream ss;
	ss << "Name: " << NAME << std::endl;
	ss << IShape::ToString();
	ss << "StartPoint: (" << m_startPoint.m_x << ", " << m_startPoint.m_y << ")" << std::endl;
	ss << "EndPoint: (" << m_endPoint.m_x << ", " << m_endPoint.m_y << ")" << std::endl;
	return ss.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}