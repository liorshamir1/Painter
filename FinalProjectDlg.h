
// FinalProjectDlg.h : header file
//

#pragma once
#include "Rectangle.h"
#include "Figure2D.h"
#include "Line.h"
#include "Ellipse.h"
#include "Square.h"
#include "Triangle.h"
#include "Text.h"
#include "FreePaint.h"
#include "MagenDavid.h"
#include "Quad.h"


// CFinalProjectDlg dialog
class CFinalProjectDlg : public CDialogEx
{
// Construction
public:
	CFinalProjectDlg(CWnd* pParent = nullptr);	// standard constructor
	CTypedPtrArray< CObArray, Figure2D*> figs;
	CTypedPtrArray< CObArray, Text*> textToDraw;
	//CTypedPtrArray< CObArray, FreePaint*> paint;


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
	afx_msg void TextDrawFlag();
	afx_msg void PaintDrawFlag();
	afx_msg void ClearAllButton();
	afx_msg void UndoShapeButton();
	afx_msg void UndoTextButton();
	afx_msg void MoveShapeButton();
	afx_msg void ChangeFillShapeButton();
	afx_msg void EraseShapeButton();
	afx_msg void ResizeButton();
	afx_msg void BrushSizeNumbers(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSaveButton();
	afx_msg void OnLoadButton();
	afx_msg void NewRectangleButton();
	afx_msg void NewLineButtom();
	afx_msg void NewMagenDavidButton();
	afx_msg void NewTriengleButton();
	afx_msg void NewSquareButton();
	afx_msg void NewEllipseButton();
	int i; 
	bool isMousePressed , move , resize;
	int functionType;
	int BrushSize =3;
	CMFCColorButton ColorD, ColorB;
	CStatic TextBox;
	CString CordinateString, inputText;
	CEdit TextFromUser, CordinetBox;
	CPoint pointText , movePoint , moveStart, moveEnd;
	CRect WindowForClient,windowSize, buttonLoc;
	CFont textFont;	
	CEdit SizeBox;
	CString StringSize;
	CButton SizeCompare;

};

