#pragma once

#include "ICanvas.h"
#include "SFML/Graphics.hpp"

class CCanvas : public ICanvas
{
public:
    CCanvas(sf::RenderTarget* window) : m_window(std::move(window)) {};

    void DrawLine(CPoint from, CPoint to, uint32_t lineColor);

    void FillPolygon(std::vector<CPoint>, uint32_t lineColor, uint32_t fillColor);

    void DrawCircle(CPoint center, double radius, uint32_t lineColor);

    void FillCircle(CPoint center, double radius, uint32_t fillColor);
private:
	sf::RenderTarget* m_window;
};