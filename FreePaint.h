#pragma once
#include <iostream>
#include <vector>
#include "Line.h"

using namespace std;

class FreePaint  : public Line{
private:
	CTypedPtrArray< CPtrArray, CPoint*> points;
public:
	FreePaint();
	FreePaint(CPoint& ,COLORREF , int);
	virtual void SetEnd(double x, double y);
	virtual void draw(CPaintDC&);
	~FreePaint();
};
