#include "pch.h"
#include <iostream>
#include "Rectangle.h"
using namespace std;
IMPLEMENT_SERIAL(RectangleShape, CObject, 1)



RectangleShape::RectangleShape() : Quad() {}
RectangleShape::RectangleShape(CPoint& start, CPoint& end, COLORREF fillColor, COLORREF borderColor, int BrushSize) : Quad(start, end, fillColor, borderColor, BrushSize) {}
void RectangleShape::draw(CPaintDC& dc) {
	dc.SelectObject(this->GetPen());
	dc.SelectObject(this->GetBrush());
	dc.Rectangle(this->GetStart().x, this->GetStart().y, this->GetEnd().x, this->GetEnd().y);
}
RectangleShape::~RectangleShape() {}
