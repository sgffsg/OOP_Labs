#pragma once

#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "IShape.h"
#include <vector>
#include "CCanvas.h"
#include "ShapeDrawer.h"
#include "ShapeCreator.h"

class ShapeService
{
public:
	void CreateShape(const std::string& line);
	std::vector<IShape*> GetShapes();

	IShape* GetShapeMaxArea() const;
	IShape* GetShapeMinPerimeter() const;

	void RenderShapes();

private:
	ShapeDrawer m_shapeDrawer;
	ShapeCreator m_shapeCreator;
	std::vector<IShape*> m_shapes = {};
};

// TODO: Вынести реализацию отрисовки, чтобы сервис не знал об окне