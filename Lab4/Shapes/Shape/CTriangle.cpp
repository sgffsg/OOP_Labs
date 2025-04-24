#include "CTriangle.h"

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillColor)
	: SolidShape("triangle", outlineColor, fillColor), 
	m_vertex1(vertex1),
	m_vertex2(vertex2),
	m_vertex3(vertex3)
{
	double sideLineTriange1 = GetTriangleSideLength(m_vertex2, m_vertex1);
	double sideLineTriange2 = GetTriangleSideLength(m_vertex3, m_vertex2);
	double sideLineTriange3 = GetTriangleSideLength(m_vertex1, m_vertex3);

	if ((sideLineTriange1 + sideLineTriange2 <= sideLineTriange3)
		|| (sideLineTriange1 + sideLineTriange3 <= sideLineTriange2)
		|| (sideLineTriange2 + sideLineTriange3 <= sideLineTriange1))
	{
		throw std::invalid_argument("Triangle is not valid");
	}
}

double CTriangle::GetArea() const
{
	return 0.5 * fabs((m_vertex1.m_x - m_vertex3.m_x) * (m_vertex2.m_y - m_vertex3.m_y) - (m_vertex2.m_x - m_vertex3.m_x) * (m_vertex1.m_y - m_vertex3.m_y));
}

double CTriangle::GetPerimeter() const
{
	double sideLineTriange1 = std::pow(m_vertex2.m_x - m_vertex1.m_x, 2) + std::pow(m_vertex2.m_y - m_vertex1.m_y, 2);
	double sideLineTriange2 = std::pow(m_vertex3.m_x - m_vertex2.m_x, 2) + std::pow(m_vertex3.m_y - m_vertex2.m_y, 2);
	double sideLineTriange3 = std::pow(m_vertex1.m_x - m_vertex3.m_x, 2) + std::pow(m_vertex1.m_y - m_vertex3.m_y, 2);

	double perimeter = sideLineTriange1 + sideLineTriange2 + sideLineTriange3;
	return perimeter;
}

std::string CTriangle::ToString() const
{
	std::stringstream result;
	result << SolidShape::ToString();
	result << "Vertex1: (" << m_vertex1.m_x << ", " << m_vertex1.m_y << ")" << std::endl;
	result << "Vertex2: (" << m_vertex2.m_x << ", " << m_vertex2.m_y << ")" << std::endl;
	result << "Vertex3: (" << m_vertex3.m_x << ", " << m_vertex3.m_y << ")" << std::endl;
	result << "Perimeter: " << GetPerimeter() << std::endl;
	result << "Area: " << GetArea() << std::endl;
	
	return result.str();
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