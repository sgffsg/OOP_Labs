#include "ShapeController.h"
#include "ShapeService.h"
#include <iostream>

int main(int argc, char* argv[])
{
    try
    {
        ShapeService shapeService;
		ShapeController shapeController(std::cin, std::cout, shapeService);
		

        shapeController.ReadShapes();
        shapeController.GetShapeMaxArea();
        shapeController.GetShapeMinPerimeter();
        shapeController.DrawShapes();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}