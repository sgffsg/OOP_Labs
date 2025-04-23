#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "IShape.h"
#include "ShapeCreator.h"
#include "utils.h"

class ShapeManager
{
public:
	void ConstructShape(const std::string& line);

	std::shared_ptr<IShape> GetShapeWithMaxArea() const;

	std::shared_ptr<IShape> GetShapeWithMinPerimeter() const;

private:
	const int WIDTH_WINDOW = 1280;
	const int HEIGHT_WINDOW = 720;
	const std::string STANDARD_WINDOW_NAME = "Window";

	std::vector<std::shared_ptr<IShape>> m_shapes = {};
};