#pragma once
#include <sstream>
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "IShape.h"
#include <vector>


class ShapeCreator
{
public:
	IShape* CreateShape(const std::string& line);

private:
	IShape* CreateLine(std::istringstream& iss);
	IShape* CreateCircle(std::istringstream& iss);
	IShape* CreateTriangle(std::istringstream& iss);
	IShape* CreateRectangle(std::istringstream& iss);
};
