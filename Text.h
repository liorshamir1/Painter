#pragma once
#include <iostream>
#include "framework.h"
using namespace std;

class Text : public CObject {
private:
	DECLARE_SERIAL(Text)
	CFont textFont;
	int size;
	CPoint location;
	CString UserString;
public:
	Text();
	Text(CPoint& , CString , int);
	virtual void draw(CPaintDC&);
	void Text::SetSize(int Size);
	void Serialize(CArchive& ar);
	~Text();
};