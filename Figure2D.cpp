#include "pch.h"
#include <iostream>
#include "Figure2D.h"

IMPLEMENT_SERIAL(Figure2D, CObject, 1)
using namespace std;

Figure2D::Figure2D(CPoint &start, CPoint & end , COLORREF fillColor, COLORREF borderColor , int BrushSize) {
	this->start.x = start.x;
	this->start.y = start.y;
	this->end.x = end.x;
	this->end.y = end.y;
	this->brush.CreateSolidBrush(fillColor);
	this->pen.CreatePen(BS_SOLID, BrushSize, borderColor);
	this->brushColor = fillColor;
	this->penColor = borderColor;
}
Figure2D::Figure2D(Figure2D &f){
	this->start.x = f.start.x;
	this->start.y = f.start.y;
	this->end.x = f.end.x;
	this->end.y = f.end.y;
	this->brush.CreateSolidBrush(getColor(f));
	this->pen.CreatePen(BS_SOLID, f.GetPenSize(), getBorder(f));
	this->brushColor = getColor(f);
	this->penColor = getBorder(f);
}
Figure2D::Figure2D() {
	this->start.x = 0;
	this->start.y = 0;
	this->end.x = 0;
	this->end.y = 0;
	this->brushColor = RGB(0, 0, 0);
	this->penColor = RGB(0, 0, 0);
	this->brush.CreateSolidBrush(brushColor);
	this->pen.CreatePen(BS_SOLID, 3, penColor);
}
Figure2D::~Figure2D(){}
CPoint & Figure2D::GetStart(){
	return this->start; 
}
CPoint & Figure2D::GetEnd() {
	return this->end;
}
void Figure2D::SetStart(double x, double y) {
	this->start.x = x; 
	this->start.y = y; 
}
void Figure2D::SetEnd(double x, double y) {
	this->end.x = x;
	this->end.y = y;
}
COLORREF Figure2D::getColor(Figure2D &f) const{
	LOGBRUSH lb;
	f.brush.GetLogBrush(&lb);
	return lb.lbColor;
}
void Figure2D::setColor(COLORREF fillColor) {
	this->brush.DeleteObject();
	this->brush.CreateSolidBrush(fillColor);
	this->brushColor = fillColor;
}
COLORREF & Figure2D::MyColor() {
	return this->brushColor;
}
COLORREF & Figure2D::Myborder() {
	return this->penColor;
}
void Figure2D::setBorder(COLORREF BColor , int BrushSize) {
	this->pen.DeleteObject();
	this->pen.CreatePen(BS_SOLID, BrushSize, BColor);
	this->penColor = BColor;
}
COLORREF Figure2D::getBorder(Figure2D &f) const {
	LOGPEN lp;
	f.pen.GetLogPen(&lp);
	return lp.lopnColor;
}
CBrush & Figure2D::GetBrush(){
	return this->brush; 
}
CPen & Figure2D::GetPen() {
	return this->pen;
}
int Figure2D::GetPenSize() {
	EXTLOGPEN lp;
	this->pen.GetExtLogPen(&lp);
	return lp.elpWidth;
}
bool Figure2D::IsInside(CPoint point) {
	if (this->start.x <= this->end.x) {
		if ((point.x >= this->start.x && point.x <= this->end.x) &&
			(point.y >= this->start.y && point.y <= this->end.y))
			return true;
		else if ((point.x >= this->start.x && point.x <= this->end.x) &&
			(point.y <= this->start.y && point.y >= this->end.y))
			return true;
	}
	else if (this->start.x >= this->end.x) {
		if ((point.x <= this->start.x && point.x >= this->end.x) &&
			(point.y <= this->start.y && point.y >= this->end.y))
			return true;
		else if ((point.x <= this->start.x && point.x >= this->end.x) &&
			(point.y >= this->start.y && point.y <= this->end.y))
			return true;
	}
	return false;
}
void Figure2D::draw(CPaintDC& dc) {}
void Figure2D::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()){
		ar << this->start;
		ar << this->end;
		ar << this->brushColor;
		ar << this->penColor;
	}
	else {
		ar >> this->start;
		ar >> this->end;
		ar >> this->brushColor;
		ar >> this->penColor;
		this->setBorder(penColor, 2);
		this->setColor(brushColor);
	}
}

