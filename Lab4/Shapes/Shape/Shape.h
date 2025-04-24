#pragma once

#include "IShape.h"

class Shape : public virtual IShape
{
public:
	Shape(std::string type, uint32_t outlineColor);

	std::string GetType() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;

private:
	std::string m_type;
	uint32_t m_outLineColor;
};
