#pragma once
#include <iostream>
#include "Figure2D.h"

using namespace std;

class Quad : public Figure2D {
private:
	DECLARE_SERIAL(Quad)
public:
	Quad();
	Quad(CPoint&, CPoint&, COLORREF, COLORREF, int);
	virtual void draw(CPaintDC&);
	~Quad();
};