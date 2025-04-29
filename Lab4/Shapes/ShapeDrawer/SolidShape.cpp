#include "SolidShape.h"

SolidShape::SolidShape(std::string type, uint32_t outlineColor, uint32_t fillColor)
	: Shape(type, outlineColor), 
	m_fillColor(fillColor)
{
}

uint32_t SolidShape::GetFillColor() const
{
	return m_fillColor;
}

std::string SolidShape::ToString() const
{
	std::stringstream result;
	result << Shape::ToString();
	result << "FillColor: " << std::hex << std::setw(6) << std::setfill('0') << m_fillColor << std::endl;

	return result.str();
}
