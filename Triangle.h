#pragma once
#include "Figure2D.h"


class Triangle : public Figure2D {
private:
	CPoint pointArr[3];
	DECLARE_SERIAL(Triangle)
public:
	Triangle();
	Triangle(CPoint&, CPoint&, COLORREF, COLORREF, int);
	CPoint & GetPoint(int);
	virtual void draw(CPaintDC&);
	virtual bool IsInside(CPoint);
	float area(CPoint , CPoint, CPoint);
	virtual void Serialize(CArchive& ar);
	~Triangle();
};