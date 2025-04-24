#include "ShapeService.h"

void ShapeService::CreateShape(const std::string& line)
{
	IShape* shape;
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

IShape* ShapeService::GetShapeWithMaxArea() const
{
	return nullptr;
}

IShape* ShapeService::GetShapeWithMinPerimeter() const
{
	return nullptr;
}

std::vector<IShape> ShapeService::GetShapes()
{
	return std::vector<IShape>();
}

void ShapeService::RenderShapes()
{
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

	m_shapes.emplace_back(CLineSegment(startPoint, endPoint, outlineColor));
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

	m_shapes.emplace_back(CCircle(centerPoint, radius, outlineColor, fillColor));
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

	m_shapes.emplace_back(CTriangle(vertex1, vertex2, vertex3, outlineColor, fillColor));
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

	m_shapes.emplace_back(CRectangle(leftTopPoint, height, width, outlineColor, fillColor));
}