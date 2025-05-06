#include "ShapeService.h"
#include <algorithm>
#include "IShape.h"
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "CCanvas.h"
#include "ShapeCreator.h"
#include "ShapeDrawer.h"


void ShapeService::CreateShape(const std::string& line)
{
	IShape* shape = m_shapeCreator.CreateShape(line);
	if (shape == nullptr)
	{
		throw std::runtime_error("Unknown shape");
	}

	m_shapes.emplace_back(shape);
}

std::vector<IShape*> ShapeService::GetShapes()
{
	return m_shapes;
}

IShape* ShapeService::GetShapeMaxArea() const
{
	if (m_shapes.empty())
	{
		return nullptr;
	}

	auto result = *std::max_element(m_shapes.begin(), m_shapes.end(),
		[](const auto& first, const auto& second) {
			return first->GetArea() < second->GetArea();
		});

	return result;
}

IShape* ShapeService::GetShapeMinPerimeter() const
{
	if (m_shapes.empty())
	{
		return nullptr;
	}

	auto result = *std::min_element(m_shapes.begin(), m_shapes.end(),
		[](const auto& first, const auto& second) {
			return first->GetPerimeter() < second->GetPerimeter();
		});
	
	return result;
}

void ShapeService::RenderShapes()
{
	m_shapeDrawer.DrawShapes(m_shapes);
}
