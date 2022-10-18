#include "pch.h"
#include <iostream>
#include <cmath>
#include "Line.h"
using namespace std;
IMPLEMENT_SERIAL(Line, CObject, 1)

Line::Line() : Figure2D () {}
Line::Line(CPoint& start , CPoint& end, COLORREF color , int BrushSize): Figure2D(start, end, color, color, BrushSize) {}
void Line::draw(CPaintDC& dc){
	dc.SelectObject(this->GetPen());
	dc.MoveTo(this->GetStart());
	dc.LineTo(this->GetEnd());
}
Line::~Line(){}