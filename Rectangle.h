#pragma once
#include <iostream>
#include "Quad.h"
using namespace std;

class RectangleShape : public Quad {
private:
	DECLARE_SERIAL(RectangleShape)
public:
	RectangleShape();
	RectangleShape(CPoint&, CPoint&, COLORREF, COLORREF, int);
	virtual void draw(CPaintDC&);
	~RectangleShape();
};