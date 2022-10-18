#include "pch.h"
#include <iostream>
#include <cmath>
#include "FreePaint.h"

using namespace std;
FreePaint::FreePaint()  : Line (){}
FreePaint::FreePaint(CPoint& point, COLORREF color , int brushSize) : Line (point, point, color, brushSize){
	points.Add(new CPoint (point));
}
void FreePaint::SetEnd(double x, double y){
	points.Add(new CPoint(x, y));
}
void FreePaint::draw(CPaintDC& dc) {
	int i; 
	dc.SelectObject(this->GetPen());
	for (i = 1; i <= points.GetSize() - 1; i++) {
		dc.MoveTo(points[i-1]->x, points[i-1]->y);
		dc.LineTo(points[i]->x, points[i]->y);
	}
}
FreePaint::~FreePaint() {}