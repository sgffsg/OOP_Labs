#pragma once
#include "Shape.h"
#include "ISolidShape.h"
#include <string>
#include <sstream>

class SolidShape : public ISolidShape, public Shape
{
public:
	SolidShape(std::string type, uint32_t outlineColor, uint32_t fillColor);
	uint32_t GetFillColor() const override;
	std::string ToString() const override;

private:
	uint32_t m_fillColor;
};
