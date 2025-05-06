#include "ShapeController.h"
#include <algorithm>

void ShapeController::ReadShapes()
{
	std::string line;
	while (std::getline(m_input, line))
	{
		if (line.empty())
		{
			break;
		}

		m_shapeService.CreateShape(line);
	}
}

void ShapeController::PrintShapes()
{
	std::vector<IShape*> shapes = m_shapeService.GetShapes();
	for (int i = 0; i < shapes.size(); i++)
		m_output << shapes[i]->ToString() << std::endl;
}

void ShapeController::PrintShapeWithMaxArea() const
{
	IShape* shape = m_shapeService.GetShapeMaxArea();

	if (shape != nullptr)
	{
		m_output << "Shape with max area:\n" << shape->ToString() << std::endl;
	}
}

void ShapeController::PrintShapeWithMinPerimeter() const
{
	IShape* shape = m_shapeService.GetShapeMinPerimeter();

	if (shape != nullptr)
	{
		m_output << "Shape with min perimeter:\n" << shape->ToString() << std::endl;
	}
}

void ShapeController::DrawShapes()
{
	m_shapeService.RenderShapes();
}