#pragma once

#include <vector>
#include "IShape.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "ShapeCreator.h"
#include "CCanvas.h"

class ShapeService
{
public:
	void CreateShape(const std::string& line);
	IShape* GetShapeWithMaxArea() const;
	IShape* GetShapeWithMinPerimeter() const;
	std::vector<IShape> GetShapes();
	void RenderShapes();

private:
	std::vector<std::shared_ptr<IShape>> m_shapes = {};
	void CreateLine(std::istringstream& iss);
	void CreateCircle(std::istringstream& iss);
	void CreateTriangle(std::istringstream& iss);
	void CreateRectangle(std::istringstream& iss);
};
