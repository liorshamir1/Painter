#pragma once
#include <iostream>
#include "framework.h"

using namespace std;

class Figure2D : public CObject {
private:
	CPoint start, end;
	COLORREF brushColor , penColor;
	CPen pen;
	CBrush brush;
	DECLARE_SERIAL(Figure2D)
public:
	Figure2D(CPoint&, CPoint& , COLORREF, COLORREF, int);
	Figure2D(Figure2D &f);
	Figure2D();
	virtual ~Figure2D();
	CPoint & GetStart();
	CPoint & GetEnd();
	void SetStart(double x, double y);
	virtual void SetEnd(double x, double y);
	CBrush & GetBrush();
	CPen & GetPen(); 
	int GetPenSize();
	COLORREF getColor(Figure2D &f) const;
	virtual void setColor(COLORREF);
	COLORREF & MyColor() ;
	COLORREF & Myborder() ;
	void setBorder(COLORREF fillColor , int);
	COLORREF getBorder(Figure2D &f) const;
	virtual bool IsInside(CPoint);
	virtual void draw(CPaintDC&);
	virtual void Serialize(CArchive& ar);
};