#pragma once
#include <iostream>
#include "Quad.h"
using namespace std;

class Square : public Quad {
private:
	DECLARE_SERIAL(Square)
public:
	Square();
	Square(CPoint&, CPoint&, COLORREF, COLORREF, int);
	virtual void draw(CPaintDC&);
	~Square();
};
