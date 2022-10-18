#include "pch.h"
#include <iostream>
#include <cmath>
#include "Text.h"
using namespace std;
IMPLEMENT_SERIAL(Text, CObject, 1)

Text::Text() {
	this->location.x = 0;
	this->location.y = 0;
	this->UserString.SetString(_T(""));
	this->size = 4; 
	this->SetSize(size);
}
Text::Text(CPoint& point, CString UserString, int size) {
	this->location.x = point.x;
	this->location.y = point.y;
	this->UserString.SetString(UserString);
	this->size = size; 
	this->SetSize(size);
}
void Text::draw(CPaintDC& dc) {
	dc.SelectObject(textFont);
	dc.DrawText(this->UserString, CRect(location.x, location.y, location.x + 150, location.y + 30), DT_LEFT);
}
void Text::SetSize(int size) {
	textFont.CreateFontW(20 + (size*3), 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Segoe UI"));
}

void Text::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << this->UserString;
		ar << this->location;
		ar << this->size;
	}
	else // Loading, not storing
	{
		ar >> this->UserString;
		ar >> this->location;
		ar >> this->size;
	}
}
Text::~Text() {}