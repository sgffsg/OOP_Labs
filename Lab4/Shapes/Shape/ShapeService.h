#pragma once

#include "CCanvas.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "IShape.h"
#include <vector>

class ShapeService
{
public:
	void CreateShape(const std::string& line);
	std::vector<IShape*> GetShapes();

	IShape* GetShapeWithMaxArea() const;
	IShape* GetShapeWithMinPerimeter() const;

private:
	std::vector<IShape*> m_shapes = {};

	void CreateLine(std::istringstream& iss);
	void CreateCircle(std::istringstream& iss);
	void CreateTriangle(std::istringstream& iss);
	void CreateRectangle(std::istringstream& iss);
};
