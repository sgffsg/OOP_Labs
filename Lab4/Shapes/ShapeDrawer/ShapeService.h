#pragma once

#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "IShape.h"
#include <vector>
#include "CCanvas.h"

class ShapeService
{
public:
	void CreateShape(const std::string& line);
	std::vector<IShape*> GetShapes();

	IShape* GetShapeWithMaxArea() const;
	IShape* GetShapeWithMinPerimeter() const;

	void RenderShapes();

private:
	std::vector<IShape*> m_shapes = {};
	CCanvas* m_canvas;

	void CreateLine(std::istringstream& iss);
	void CreateCircle(std::istringstream& iss);
	void CreateTriangle(std::istringstream& iss);
	void CreateRectangle(std::istringstream& iss);
};
