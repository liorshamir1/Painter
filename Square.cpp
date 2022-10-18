#include "pch.h"
#include <iostream>
#include "Square.h"
using namespace std;
IMPLEMENT_SERIAL(Square, CObject, 1)


Square::Square() : Quad() {}
Square::Square(CPoint& start, CPoint& end, COLORREF fillColor, COLORREF borderColor, int BrushSize) : Quad(start, end, fillColor, borderColor, BrushSize) {}
void Square::draw(CPaintDC& dc) {
	unsigned int length;
	dc.SelectObject(this->GetPen());
	dc.SelectObject(this->GetBrush());
	if ((this->GetEnd().x > this->GetStart().x )&& (this->GetEnd().y > this->GetStart().y)) {
		length = this->GetEnd().x - this->GetStart().x;
		dc.Rectangle(this->GetStart().x, this->GetStart().y, this->GetStart().x + length, this->GetStart().y + length);
	}
	else if ((this->GetEnd().x < this->GetStart().x) && (this->GetEnd().y > this->GetStart().y)) {
		length = this->GetEnd().x - this->GetStart().x;
		dc.Rectangle(this->GetStart().x, this->GetStart().y, this->GetStart().x + length, this->GetStart().y - length);
	}
	else if ((this->GetEnd().x > this->GetStart().x) &&( this->GetEnd().y < this->GetStart().y)) {
		length = this->GetEnd().x - this->GetStart().x;
		dc.Rectangle(this->GetStart().x, this->GetStart().y, this->GetStart().x + length, this->GetStart().y - length);
	}
	else {
		length = this->GetStart().x - this->GetEnd().x;
		dc.Rectangle(this->GetStart().x, this->GetStart().y, this->GetStart().x - length, this->GetStart().y - length);
	}
	
}
Square::~Square() {}
