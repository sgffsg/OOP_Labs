#include "CCircle.h"
#include <numbers>

CCircle::CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor)
	: SolidShape("circle", outlineColor, fillColor), 
	m_center(center), 
	m_radius(radius)
{
	if (radius <= 0)
	{
		throw std::invalid_argument("Invalid radius");
	}
}

std::string CCircle::ToString() const
{
	std::stringstream result;
	result << SolidShape::ToString();
	result << "Center: (" << m_center.m_x << ", " << m_center.m_y << ")" << std::endl;
	result << "Radius: " << m_radius << std::endl;
	result << "Perimeter: " << GetPerimeter() << std::endl;
	result << "Area: " << GetArea() << std::endl;

	return result.str();
}

double CCircle::GetArea() const
{
	return std::numbers::pi * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * std::numbers::pi * m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}