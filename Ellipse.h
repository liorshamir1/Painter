#pragma once
#include <iostream>
#include "Rectangle.h"

using namespace std;


class EllipseShape : public RectangleShape {
private:
	DECLARE_SERIAL(EllipseShape)
public:
	EllipseShape();
	EllipseShape(CPoint&, CPoint&, COLORREF, COLORREF, int);
	virtual void draw(CPaintDC&);
	virtual bool IsInside(CPoint);
	~EllipseShape();
};