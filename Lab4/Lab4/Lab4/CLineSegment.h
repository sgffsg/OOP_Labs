
#include "CPoint.h"
#include "IShape.h"

class CLineSegment : public IShape
{
public:
	static constexpr const char* NAME = "line";

	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor)
		: m_startPoint(startPoint)
		, m_endPoint(endPoint)
		, m_outlineColor(outlineColor)
	{
	}

	double GetArea() const override;

	double GetPerimeter() const override;

	std::string ToString() const override;

	uint32_t GetOutlineColor() const override;

	CPoint GetStartPoint() const;

	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint, m_endPoint;
	uint32_t m_outlineColor;

	const double DEFAULT_AREA = 0;
};