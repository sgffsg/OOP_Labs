#pragma once

#include "CCanvas.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "IShape.h"
#include <vector>

class ShapeDrawer
{
public:
	void DrawShapes(std::vector<IShape*> m_shapes);

private:
	CCanvas* m_canvas;
};
