
#include "Figure2D.h"

class MagenDavid : public Figure2D {
private:
	CPoint vertices[12];
	CPoint center;
	DECLARE_SERIAL(MagenDavid)
public:
	MagenDavid();
	MagenDavid(CPoint&, CPoint&, COLORREF, COLORREF, int);
	virtual void draw(CPaintDC&);
	virtual void Serialize(CArchive& ar);
	~MagenDavid();
};