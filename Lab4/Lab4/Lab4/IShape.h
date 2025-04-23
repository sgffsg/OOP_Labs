#include <cstdint>
#include <string>
#include "utils.h"

class IShape
{
public:
	virtual uint32_t GetOutlineColor() const = 0;

	virtual ~IShape() = default;

	virtual double GetArea() const = 0;

	virtual double GetPerimeter() const = 0;

	virtual std::string ToString() const
	{
		std::stringstream ss;
		ss << "Perimeter: " << GetPerimeter() << std::endl;
		ss << "Area: " << GetArea() << std::endl;
		ss << "OutlineColor: " << std::hex << std::setw(6) << std::setfill('0') << GetOutlineColor() << std::endl;
		return ss.str();
	};
};
