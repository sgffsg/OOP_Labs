#define CATCH_CONFIG_MAIN
#include "../../../Catch/catch.hpp"

#include "../ShapeDrawer/CCircle.h"
#include "../ShapeDrawer/CLineSegment.h"
#include "../ShapeDrawer/CPoint.h"
#include "../ShapeDrawer/CRectangle.h"
#include "../ShapeDrawer/CTriangle.h"
#include "../ShapeDrawer/Shape.h"
#include "../ShapeDrawer/SolidShape.h"
#include "../ShapeDrawer/ShapeService.h"

const uint32_t OUTLINE_COLOR = 0xFFFFFF;
const uint32_t FILL_COLOR = 0x000000;

SCENARIO("Create Shapes")
{
	WHEN("Valid Create")
	{
		THEN("")
		{
			CPoint point(0, 0);

			REQUIRE(point.m_x == 0);
			REQUIRE(point.m_y == 0);
		}
	}
	
	WHEN("CLineSegment CreateTest")
	{
		THEN("Valid Create")
		{
			CPoint startPoint = { 0, 0 };
			CPoint endPoint = { 1, 1 };

			CLineSegment line(startPoint, endPoint, OUTLINE_COLOR);

			REQUIRE(line.GetStartPoint().m_x == startPoint.m_x);
			REQUIRE(line.GetStartPoint().m_y == startPoint.m_y);
			REQUIRE(line.GetEndPoint().m_x == endPoint.m_x);
			REQUIRE(line.GetEndPoint().m_y == endPoint.m_y);
			REQUIRE(line.GetOutlineColor() == OUTLINE_COLOR);
		}
	}

	WHEN("CCircle CreateTest")
	{
		THEN("Valid Create")
		{
			CPoint center = { 1, 1 };

			CCircle circle(center, 2, OUTLINE_COLOR, FILL_COLOR);
			REQUIRE(circle.GetCenter().m_y == center.m_y);
			REQUIRE(circle.GetRadius() == 2);

			REQUIRE(circle.GetOutlineColor() == OUTLINE_COLOR);
			REQUIRE(circle.GetFillColor() == FILL_COLOR);
		}

		THEN("Invalid Create")
		{
			CPoint center = { 1, 1 };
	
			REQUIRE_THROWS_AS(CCircle(center, 0, OUTLINE_COLOR, FILL_COLOR), std::invalid_argument);
			REQUIRE_THROWS_AS(CCircle(center, -10, OUTLINE_COLOR, FILL_COLOR), std::invalid_argument);
		}
	}

	WHEN("CRectangle CreateTest")
	{
		THEN("Valid Create")
		{
			CPoint leftTop = { 1, 1 };

			CRectangle rectangle(leftTop, 2, 2, OUTLINE_COLOR, FILL_COLOR);
			
			REQUIRE(rectangle.GetLeftTop().m_x == leftTop.m_x);
			REQUIRE(rectangle.GetLeftTop().m_y == leftTop.m_y);
			REQUIRE(rectangle.GetRightBottom().m_x == 3);
			REQUIRE(rectangle.GetRightBottom().m_y == 3);
			REQUIRE(rectangle.GetOutlineColor() == OUTLINE_COLOR);
			REQUIRE(rectangle.GetFillColor() == FILL_COLOR);
		}

		THEN("Invalid Create")
		{
			CPoint leftTop = { 3, 4 };

			REQUIRE_THROWS_AS(CRectangle(leftTop, -2,  2, OUTLINE_COLOR, FILL_COLOR), std::invalid_argument);
			REQUIRE_THROWS_AS(CRectangle(leftTop,  2, -2, OUTLINE_COLOR, FILL_COLOR), std::invalid_argument);
			REQUIRE_THROWS_AS(CRectangle(leftTop, -2, -2, OUTLINE_COLOR, FILL_COLOR), std::invalid_argument);
		}
	}

	WHEN("CTriangle CreateTest")
	{
		THEN("Valid Create")
		{
			CPoint vertex1 = { 2, 0 };
			CPoint vertex2 = { 0, 0 };
			CPoint vertex3 = { 0, 5 };

			CTriangle triangle(vertex1, vertex2, vertex3, OUTLINE_COLOR, FILL_COLOR);

			REQUIRE(triangle.GetVertex1().m_x == vertex1.m_x);
			REQUIRE(triangle.GetVertex1().m_y == vertex1.m_y);
			REQUIRE(triangle.GetVertex2().m_x == vertex2.m_x);
			REQUIRE(triangle.GetVertex2().m_y == vertex2.m_y);
			REQUIRE(triangle.GetVertex3().m_x == vertex3.m_x);
			REQUIRE(triangle.GetVertex3().m_y == vertex3.m_y);
			REQUIRE(triangle.GetOutlineColor() == OUTLINE_COLOR);
			REQUIRE(triangle.GetFillColor() == FILL_COLOR);
		}

		THEN("Invalid Create")
		{
			CPoint vertex1 = { 1, 1 };
			CPoint vertex2 = { 2, 2 };
			CPoint vertex3 = { 3, 3 };

			REQUIRE_THROWS_AS(CTriangle(vertex1, vertex2, vertex3, OUTLINE_COLOR, FILL_COLOR), std::invalid_argument);
		}
	}
}

SCENARIO("Shapes Service Test")
{
	WHEN("Create Shape")
	{
		ShapeService shapeService;
		THEN("Correct test")
		{
			shapeService.CreateShape("circle 0 0 3 0xFFFFFF 0x000000");
			shapeService.CreateShape("rectangle 3 4 2 1 0xFFFFFF 0x000000");
			shapeService.CreateShape("triangle 0 0 0 3 4 0 0xFFFFFF 0x000000");

			REQUIRE(shapeService.GetShapes().size() == 3);
		}

		THEN("Unknown figure test")
		{
			shapeService.CreateShape("octangle 0 0 0 3 4 0 0xFFFFFF 0x000000");
			REQUIRE(shapeService.GetShapes().size() == 0);
		}

		THEN("Mismatch params test")
		{
			shapeService.CreateShape("octangle");
			REQUIRE(shapeService.GetShapes().size() == 0);
		}

		THEN("Valid Create line test")
		{
			shapeService.CreateShape("line 0 0 1 1 0xFFFFFF 0x000000");
			REQUIRE(shapeService.GetShapes().size() == 1);
		}

		THEN("Invalid Create line tests")
		{
			REQUIRE_THROWS_AS(shapeService.CreateShape("line"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("line 0"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("line 0 1"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("line 0 0 2"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("line 0 0 3 3"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("line 0 0 4 4 GHIJKL"), std::invalid_argument);
		}

		THEN("Valid Create circle test")
		{
			shapeService.CreateShape("circle 0 0 3 0xFFFFFF 0x000000");
			REQUIRE(shapeService.GetShapes().size() == 1);
		}

		THEN("Invalid Create circle tests")
		{
			REQUIRE_THROWS_AS(shapeService.CreateShape("circle"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("circle 0"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("circle 0 1"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("circle 0 0 2"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("circle 0 0 3 GHIJKL"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("circle 0 0 3 0xFFFFFF GHIJKL"), std::invalid_argument);
		}

		THEN("Valid Create rectangle test")
		{
			shapeService.CreateShape("rectangle 3 4 2 1 0xFFFFFF 0x000000");
			REQUIRE(shapeService.GetShapes().size() == 1);
		}

		THEN("Invalid Create rectangle tests")
		{
			REQUIRE_THROWS_AS(shapeService.CreateShape("rectangle"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("rectangle 3"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("rectangle 3 4"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("rectangle 3 4 2"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("rectangle 3 4 2 1"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("rectangle 3 4 2 1 GHIJKL"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("rectangle 0 0 3 0xFFFFFF GHIJKL"), std::invalid_argument);
		}

		THEN("Valid Create triangle test")
		{
			shapeService.CreateShape("triangle 0 0 0 3 4 0 0xFFFFFF 0x000000");
			REQUIRE(shapeService.GetShapes().size() == 1);
		}

		THEN("Invalid Create triangle tests")
		{
			REQUIRE_THROWS_AS(shapeService.CreateShape("triangle"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("triangle 0"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("triangle 0 0"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("triangle 0 0 0"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("triangle 0 0 0 3"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("triangle 0 0 0 3 4"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("triangle 0 0 0 3 4 0"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("triangle 0 0 0 3 4 0 GHIJKL"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeService.CreateShape("triangle 0 0 3 0xFFFFFF GHIJKL"), std::invalid_argument);
		}
	}


	WHEN("Get Shape With Max Area")
	{
		ShapeService shapeService;
		THEN("Correct test")
		{
			shapeService.CreateShape("circle 0 0 3 0xFFFFFF 0x000000");
			shapeService.CreateShape("rectangle 3 4 2 1 0xFFFFFF 0x000000");
			shapeService.CreateShape("triangle 0 0 0 3 4 0 0xFFFFFF 0x000000");

			auto maxShape = shapeService.GetShapes()[0];
			REQUIRE(maxShape == shapeService.GetShapeWithMaxArea());
		}

		THEN("Null test")
		{
			REQUIRE(nullptr == shapeService.GetShapeWithMaxArea());
		}
	}

	WHEN("Get Shape With Min Perimeter")
	{
		ShapeService shapeService;
		THEN("Correct test")
		{
			shapeService.CreateShape("circle 0 0 3 0xFFFFFF 0x000000");
			shapeService.CreateShape("rectangle 3 4 2 1 0xFFFFFF 0x000000");
			shapeService.CreateShape("triangle 0 0 0 3 4 0 0xFFFFFF 0x000000");

			auto minShape = shapeService.GetShapes()[1];
			REQUIRE(minShape == shapeService.GetShapeWithMinPerimeter());
		}

		THEN("Null test")
		{
			REQUIRE(nullptr == shapeService.GetShapeWithMinPerimeter());
		}
	}
}