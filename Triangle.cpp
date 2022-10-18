#include "pch.h"
#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;
IMPLEMENT_SERIAL(Triangle, CObject, 1)

Triangle::Triangle() : Figure2D() {
}
Triangle::Triangle(CPoint& start, CPoint& end, COLORREF fillColor, COLORREF borderColor, int BrushSize) : Figure2D(start, end, fillColor, borderColor, BrushSize) {
}	
CPoint & Triangle::GetPoint(int num) {
	return this->pointArr[num-1]; 
}
void Triangle::draw(CPaintDC& dc) {
	dc.SelectObject(this->GetPen());
	dc.SelectObject(this->GetBrush());
	this->pointArr[0].SetPoint(this->GetStart().x, this->GetEnd().y);
	this->pointArr[1].SetPoint(this->GetEnd().x, this->GetEnd().y);
	this->pointArr[2].SetPoint((this->GetStart().x + this->GetEnd().x)/2, this->GetStart().y);
	dc.Polygon(this->pointArr, 3);
}
float Triangle::area(CPoint point1, CPoint point2, CPoint point3) {
	return abs(((point1.x*(point2.y - point3.y)) + (point2.x * (point3.y - point1.y)) + (point3.x * (point1.y - point2.y))) / 2.0);
}
bool Triangle::IsInside(CPoint point) {
	double tArea, pArea1, pArea2, pArea3; 
	tArea = area(this->pointArr[0], this->pointArr[1], this->pointArr[2]); 
	pArea1 = area(point, this->pointArr[1], this->pointArr[2]);
	pArea2 = area(this->pointArr[0], point, this->pointArr[2]);
	pArea3 = area(this->pointArr[0], this->pointArr[1], point);
	if (tArea == pArea1 + pArea2 + pArea3)
		return true;
	return false; 
}
void Triangle::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << this->GetStart();
		ar << this->GetEnd();
		ar << this->pointArr[0];
		ar << this->pointArr[1];
		ar << this->pointArr[2];
		ar << this->MyColor();
		ar << this->Myborder();
	}
	else // Loading, not storing
	{
		ar >> this->GetStart();
		ar >> this->GetEnd();
		ar >> this->pointArr[0];
		ar >> this->pointArr[1];
		ar >> this->pointArr[2];
		ar >> this->MyColor();
		ar >> this->Myborder();
		this->setBorder(Myborder(), 2);
		this->setColor(this->MyColor());
	}
}
Triangle::~Triangle() {}

