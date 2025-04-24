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
	PrintShapes();
}

void ShapeController::PrintShapes()
{
	std::vector<IShape*> shapes = m_shapeService.GetShapes();
	for (int i = 0; i < shapes.size(); i++)
		m_output << shapes[i]->ToString() << std::endl;
}

static bool PerimeterComparer(Shape* a, Shape* b)
{
	return a->GetPerimeter() < b->GetPerimeter();
}

static bool AreaComparer(Shape* a, Shape* b)
{
	return a->GetArea() < b->GetArea();
}

void ShapeController::GetShapeMaxArea() const
{
	IShape* shape = m_shapeService.GetShapeWithMaxArea();

	if (shape != nullptr)
	{
		m_output << "Shape with max area:\n" << shape->ToString() << std::endl;
	}
}

void ShapeController::GetShapeMinPerimeter() const
{
	IShape* shape = m_shapeService.GetShapeWithMinPerimeter();

	if (shape != nullptr)
	{
		m_output << "Shape with min perimeter:\n" << shape->ToString() << std::endl;
	}
}

void ShapeController::DrawShapes()
{
}