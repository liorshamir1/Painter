#include "pch.h"
#include <iostream>
#include "Quad.h"
using namespace std;
IMPLEMENT_SERIAL(Quad, CObject, 1)

Quad::Quad() : Figure2D() {}
Quad::Quad(CPoint& start, CPoint& end, COLORREF fillColor, COLORREF borderColor, int BrushSize) : Figure2D(start, end, fillColor, borderColor, BrushSize) {}
void Quad::draw(CPaintDC& dc) {}
Quad::~Quad() {}
