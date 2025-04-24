#include <iostream>
#include <Windows.h>
#include "CCircle.h"
#include "ShapeController.h"
#include "ShapeService.h"

int main()
{
	try
	{
		ShapeService shapeService;
		ShapeController shapeController(std::cin, std::cout, shapeService);
	
		shapeController.ReadShapes();
		shapeController.GetShapeMaxArea();
		shapeController.GetShapeMinPerimeter();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}


