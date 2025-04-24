#pragma once
#include <cstdint>
#include "IShape.h"

class ISolidShape : public virtual IShape
{
	virtual uint32_t GetFillColor() const = 0;
};
