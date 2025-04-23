#include "CTriangle.h"

double CTriangle::GetArea() const
{
	return 0.5 * fabs((m_vertex1.m_x - m_vertex3.m_x) * (m_vertex2.m_y - m_vertex3.m_y) - (m_vertex2.m_x - m_vertex3.m_x) * (m_vertex1.m_y - m_vertex3.m_y));
}

double CTriangle::GetPerimeter() const
{
	double sideLineTriange1 = GetTriangleSideLength(m_vertex2, m_vertex1);
	double sideLineTriange2 = GetTriangleSideLength(m_vertex3, m_vertex2);
	double sideLineTriange3 = GetTriangleSideLength(m_vertex1, m_vertex3);

	double perimeter = sideLineTriange1 + sideLineTriange2 + sideLineTriange3;
	return perimeter;
}

std::string CTriangle::ToString() const
{
	std::stringstream ss;
	ss << "Name: " << NAME << std::endl;
	ss << IShape::ToString();
	ss << "FillColor: " << std::hex << std::setw(6) << std::setfill('0') << GetFillColor() << std::endl;
	ss << "Vertex1: (" << m_vertex1.m_x << ", " << m_vertex1.m_y << ")" << std::endl;
	ss << "Vertex2: (" << m_vertex2.m_x << ", " << m_vertex2.m_y << ")" << std::endl;
	ss << "Vertex3: (" << m_vertex3.m_x << ", " << m_vertex3.m_y << ")" << std::endl;
	return ss.str();
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

double CTriangle::GetTriangleSideLength(const CPoint& vertex1, const CPoint& vertex2)
{
	return std::sqrt(std::pow(vertex1.m_x - vertex2.m_x, 2) + std::pow(vertex1.m_y - vertex2.m_y, 2));
}
