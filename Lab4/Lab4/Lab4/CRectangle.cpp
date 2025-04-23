#include "CRectangle.h"

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
	std::stringstream ss;
	ss << "Name: " << NAME << std::endl;
	ss << IShape::ToString();
	ss << "FillColor: " << std::hex << std::setw(6) << std::setfill('0') << GetFillColor() << std::endl;
	ss << "LeftTop: (" << m_leftTopPoint.m_x << ", " << m_leftTopPoint.m_y << ")" << std::endl;
	ss << "RightBottom: (" << CRectangle::GetRightBottom().m_x << ", " << CRectangle::GetRightBottom().m_y << ")" << std::endl;
	ss << "Height: " << m_height << std::endl;
	ss << "Width: " << m_width << std::endl;
	return ss.str();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTopPoint;
}

CPoint CRectangle::GetRightBottom() const
{
	return { m_leftTopPoint.m_x + m_width, m_leftTopPoint.m_y + m_height };
}

double CRectangle::GetHeight() const
{
	return m_height;
}

double CRectangle::GetWidth() const
{
	return m_width;
}