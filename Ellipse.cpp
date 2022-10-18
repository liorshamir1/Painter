#include "pch.h"
#include <iostream>
#include <math.h>
#include "Ellipse.h"
IMPLEMENT_SERIAL(EllipseShape, CObject, 1)
using namespace std;

EllipseShape::EllipseShape() : RectangleShape() {}
EllipseShape::EllipseShape(CPoint& start, CPoint& end, COLORREF fillColor, COLORREF borderColor, int BrushSize) : RectangleShape(start, end, fillColor, borderColor, BrushSize) {}
void EllipseShape::draw(CPaintDC& dc) {
	dc.SelectObject(this->GetPen());
	dc.SelectObject(this->GetBrush());
	dc.Ellipse(this->GetStart().x, this->GetStart().y, this->GetEnd().x, this->GetEnd().y);
}
bool EllipseShape::IsInside(CPoint point) {
	CPoint center; 
	float RadiosHigh, RadiosLng; 
	center.x = this->GetStart().x + (this->GetEnd().x - this->GetStart().x) / 2;
	center.y = this->GetStart().y + (this->GetEnd().y - this->GetStart().y) / 2;
	RadiosHigh = center.y - this->GetStart().y;
	RadiosLng = center.x - this->GetStart().x;
	float isInsideCalc = ((pow(point.x - center.x, 2)) / (pow(RadiosLng, 2))) + ((pow(point.y - center.y, 2)) / (pow(RadiosHigh, 2)));
	if (isInsideCalc <= 1)
		return true;
	return false; 
}
EllipseShape::~EllipseShape() {}

