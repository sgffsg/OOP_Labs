#include "ShapeService.h"
#include <algorithm>
#include "IShape.h"
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "CCanvas.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

void ShapeService::CreateShape(const std::string& line)
{
	std::istringstream iss(line);
	std::string shapeName;
	iss >> shapeName;

	if (shapeName == "line")
	{
		CreateLine(iss);
	}
	if (shapeName == "circle")
	{
		CreateCircle(iss);
	}
	if (shapeName == "triangle")
	{
		CreateTriangle(iss);
	}
	if (shapeName == "rectangle")
	{
		CreateRectangle(iss);
	}
}

std::vector<IShape*> ShapeService::GetShapes()
{
	return m_shapes;
}

IShape* ShapeService::GetShapeWithMaxArea() const
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

IShape* ShapeService::GetShapeWithMinPerimeter() const
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
	auto window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),"DRAWER");
	m_canvas = new CCanvas(window);

	while (window->isOpen())
	{
		sf::Event event{};
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window->close();
			}
		}
		window->clear(sf::Color::White);

		for (auto const& shape : m_shapes)
		{
			shape->Draw(m_canvas);
		}
		window->display();
	}
}

void ShapeService::CreateLine(std::istringstream& iss)
{
	double startX, startY, endX, endY;

	if (!(iss >> startX >> endX >> startY >> endY))
	{
		throw std::invalid_argument("Invalid line segment coordinates");
	}
	CPoint startPoint = { startX, endX };
	CPoint endPoint = { startY, endY };

	uint32_t outlineColor;
	if (!(iss >> std::hex >> outlineColor))
	{
		throw std::invalid_argument("Invalid color values");
	}

	m_shapes.emplace_back(new CLineSegment(startPoint, endPoint, outlineColor));
}

void ShapeService::CreateCircle(std::istringstream& iss)
{
	double centerX, centerY, radius;

	if (!(iss >> centerX >> centerY >> radius))
	{
		throw std::invalid_argument("Invalid circle parameters");
	}
	CPoint centerPoint = { centerX, centerY };

	uint32_t outlineColor, fillColor;
	if (!(iss >> std::hex >> outlineColor >> fillColor))
	{
		throw std::invalid_argument("Invalid color values");
	}

	m_shapes.emplace_back(new CCircle(centerPoint, radius, outlineColor, fillColor));
}

void ShapeService::CreateTriangle(std::istringstream& iss)
{
	double vertex1X, vertex1Y, vertex2X, vertex2Y, vertex3X, vertex3Y;

	if (!(iss >> vertex1X >> vertex1Y >> vertex2X >> vertex2Y >> vertex3X >> vertex3Y))
	{
		throw std::invalid_argument("Invalid number of triangle coordinates");
	}

	CPoint vertex1(vertex1X, vertex1Y);
	CPoint vertex2 = CPoint(vertex2X, vertex2Y);
	CPoint vertex3 = CPoint(vertex3X, vertex3Y);

	uint32_t outlineColor, fillColor;
	if (!(iss >> std::hex >> outlineColor >> fillColor))
	{
		throw std::invalid_argument("Invalid color values");
	}

	m_shapes.emplace_back(new CTriangle(vertex1, vertex2, vertex3, outlineColor, fillColor));
}

void ShapeService::CreateRectangle(std::istringstream& iss)
{
	double leftTopX, leftTopY, height, width;

	if (!(iss >> leftTopX >> leftTopY >> height >> width))
	{
		throw std::invalid_argument("Invalid rectangle coordinates");
	}
	CPoint leftTopPoint = CPoint(leftTopX, leftTopY);

	uint32_t outlineColor, fillColor;
	if (!(iss >> std::hex >> outlineColor >> fillColor))
	{
		throw std::invalid_argument("Invalid color values");
	}

	m_shapes.emplace_back(new CRectangle(leftTopPoint, height, width, outlineColor, fillColor));
}