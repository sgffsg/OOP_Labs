#include "IShape.h"

class ISolidShape : public IShape
{
	virtual uint32_t GetFillColor() const = 0;
};
