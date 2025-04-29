#include "CRectangle.h"

CRectangle::CRectangle(CPoint leftTopPoint, double height, double width, uint32_t outlineColor, uint32_t fillColor)
	: SolidShape("rectangle", outlineColor, fillColor),
	m_leftTopPoint(leftTopPoint), 
	m_height(height), 
	m_width(width)
{
	if (height <= 0 || width <= 0)
	{
		throw std::invalid_argument("Invalid rectangle sizes");
	}
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return 2 * m_width + 2 * m_height;
}

std::string CRectangle::ToString() const
{
	std::stringstream result;
	result << SolidShape::ToString();
	result << "LeftTop point: (" << m_leftTopPoint.m_x << ", " << m_leftTopPoint.m_y << ")" << std::endl;
	result << "RightBottom point: (" << CRectangle::GetRightBottom().m_x << ", " << CRectangle::GetRightBottom().m_y << ")" << std::endl;
	result << "Height: " << m_height << std::endl;
	result << "Width: " << m_width << std::endl;
	result << "Perimeter: " << GetPerimeter() << std::endl;
	result << "Area: " << GetArea() << std::endl;

	return result.str();
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTopPoint;
}

CPoint CRectangle::GetRightBottom() const
{
	return { m_leftTopPoint.m_x + m_width, m_leftTopPoint.m_y + m_height };
}

void CRectangle::Draw(ICanvas* canvas)
{
	CPoint rightTop(GetRightBottom().m_x, m_leftTopPoint.m_y);
	CPoint leftBottom(m_leftTopPoint.m_x, GetRightBottom().m_y);

	canvas->FillPolygon({ m_leftTopPoint, rightTop, GetRightBottom(), leftBottom }, GetOutlineColor(), GetFillColor());

	canvas->DrawLine(m_leftTopPoint, rightTop, GetOutlineColor());
	canvas->DrawLine(rightTop, GetRightBottom(), GetOutlineColor());
	canvas->DrawLine(GetRightBottom(), leftBottom, GetOutlineColor());
	canvas->DrawLine(leftBottom, m_leftTopPoint, GetOutlineColor());
}

double CRectangle::GetHeight() const
{
	return m_height;
}

double CRectangle::GetWidth() const
{
	return m_width;
}