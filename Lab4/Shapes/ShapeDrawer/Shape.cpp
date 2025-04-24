#include "Shape.h"

Shape::Shape(std::string type, uint32_t outlineColor)
	: m_type(type),
	m_outLineColor(outlineColor)
{
}

std::string Shape::GetType() const
{
	return m_type;
}

std::string Shape::ToString() const
{
	std::stringstream result;
	result << "Type: " << m_type << std::endl;
	result << "OutlineColor: " << std::hex << std::setw(6) << std::setfill('0') << m_outLineColor << std::endl;

	return result.str();
}

uint32_t Shape::GetOutlineColor() const
{
	return m_outLineColor;
}
