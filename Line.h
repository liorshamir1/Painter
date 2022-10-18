#pragma once
#include <iostream>
#include "Figure2D.h"
using namespace std;

class Line : public Figure2D {
private:
	DECLARE_SERIAL(Line)
public:
	Line();
	Line(CPoint&, CPoint& , COLORREF, int);
	virtual void draw(CPaintDC&);
	~Line();
};