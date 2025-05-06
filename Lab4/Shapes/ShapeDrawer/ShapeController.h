#pragma once
#include <string>
#include <fstream>
#include "Shape.h"
#include "ShapeService.h"
#include <vector>
#include "ShapeDrawer.h"


class ShapeController
{
public:
	ShapeController(std::istream& input, std::ostream& output, ShapeService shapeService)
		: m_input(input)
		, m_output(output)
		, m_shapeService(shapeService)
	{
	}

	void ReadShapes();
	void PrintShapes();
	void PrintShapeWithMaxArea() const;
	void PrintShapeWithMinPerimeter() const;
	void DrawShapes();

private:
	std::istream& m_input;
	std::ostream& m_output;
	ShapeService m_shapeService;
};
