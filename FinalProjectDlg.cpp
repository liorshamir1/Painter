
// FinalProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "FinalProject.h"
#include "FinalProjectDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
enum function {
	SLine = 1, SEllipse, SRectangles, SSquare, STriangle, SMagenDavid,
	SText, Spaint, TColor, Terase, Tmove, Tresize}function;

CFinalProjectDlg::CFinalProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECT_DIALOG, pParent)
	, inputText(_T(""))
	, StringSize(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, ColorD);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, ColorB);
	DDX_Control(pDX, IDC_EDIT2, TextFromUser);
	DDX_Control(pDX, IDC_EDIT3, CordinetBox);
	DDX_Text(pDX, IDC_EDIT2, inputText);
	DDX_Control(pDX, IDC_EDIT1, SizeBox);
	DDX_Text(pDX, IDC_EDIT1, StringSize);
	DDX_Control(pDX, IDC_BUTTON7, SizeCompare);
}

BEGIN_MESSAGE_MAP(CFinalProjectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON8, &CFinalProjectDlg::TextDrawFlag)
	ON_BN_CLICKED(IDOK, &CFinalProjectDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON9, &CFinalProjectDlg::ClearAllButton)
	ON_BN_CLICKED(IDC_BUTTON12, &CFinalProjectDlg::UndoShapeButton)
	ON_BN_CLICKED(UndoText, &CFinalProjectDlg::UndoTextButton)
	ON_BN_CLICKED(IDC_BUTTON7, &CFinalProjectDlg::PaintDrawFlag)
	ON_BN_CLICKED(IDC_BUTTON11, &CFinalProjectDlg::MoveShapeButton)
	ON_BN_CLICKED(IDC_BUTTON10, &CFinalProjectDlg::ChangeFillShapeButton)
	ON_BN_CLICKED(IDC_BUTTON13, &CFinalProjectDlg::EraseShapeButton)
	ON_BN_CLICKED(IDC_BUTTON15, &CFinalProjectDlg::ResizeButton)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, &CFinalProjectDlg::BrushSizeNumbers)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &CFinalProjectDlg::OnSaveButton)
	ON_BN_CLICKED(IDC_MFCBUTTON4, &CFinalProjectDlg::OnLoadButton)
	ON_BN_CLICKED(IDC_MFCBUTTON15, &CFinalProjectDlg::NewRectangleButton)
	ON_BN_CLICKED(IDC_MFCBUTTON7, &CFinalProjectDlg::NewLineButtom)
	ON_BN_CLICKED(IDC_MFCBUTTON17, &CFinalProjectDlg::NewMagenDavidButton)
	ON_BN_CLICKED(IDC_MFCBUTTON9, &CFinalProjectDlg::NewTriengleButton)
	ON_BN_CLICKED(IDC_MFCBUTTON16, &CFinalProjectDlg::NewSquareButton)
	ON_BN_CLICKED(IDC_MFCBUTTON8, &CFinalProjectDlg::NewEllipseButton)
END_MESSAGE_MAP()

BOOL CFinalProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	isMousePressed = false;
	functionType =0;
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	this->GetWindowRect(windowSize);
	SizeCompare.GetWindowRect(buttonLoc); 
	WindowForClient.SetRect(windowSize.TopLeft().x+10, buttonLoc.BottomRight().y , windowSize.BottomRight().x* 0.96 , windowSize.BottomRight().y *0.85);
	textFont.CreateFontW(24,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("Segoe UI"));
	this->SetBackgroundColor(RGB(235, 252, 255), 1);
	this->OnSetFont(&textFont);
	this->SetWindowTextW(_T("Paint program"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFinalProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = 100;//(rect.Width() - cxIcon + 1) / 2;
		int y = 100; //(rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		StringSize.Format(_T("%d"), BrushSize);
		SizeBox.SetWindowTextW(StringSize);
		dc.Rectangle(WindowForClient);
		for (int i = 0; i < figs.GetSize(); i++) {
			if (figs[i] != NULL)
				figs[i]->draw(dc);
		}
		for (int i = 0; i < textToDraw.GetSize(); i++) {
			if (textToDraw[i] != NULL) {
				textToDraw[i]->draw(dc);
			}
		}
		CDialogEx::OnPaint();
	}
}

HCURSOR CFinalProjectDlg::OnQueryDragIcon(){return static_cast<HCURSOR>(m_hIcon);}

void CFinalProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isMousePressed && figs.GetSize() > 0)
	{
		switch (functionType)
		{
		case SLine:
		case SEllipse:
		case SRectangles:
		case SSquare:
		case STriangle:
		case SMagenDavid:
		case Spaint:
			figs[figs.GetSize() - 1]->SetEnd(point.x, point.y);
			break;
		case Tresize:
			if (resize)
				figs[i]->SetEnd(point.x, point.y);
			break;
		case Tmove:
			if (move) {
				double changeX = point.x - movePoint.x;
				double changeY = point.y - movePoint.y;
				figs[i]->GetStart().SetPoint(moveStart.x + changeX, moveStart.y + changeY);
				figs[i]->GetEnd().SetPoint(moveEnd.x + changeX, moveEnd.y + changeY);
				break;
			}
		}
		InvalidateRect(WindowForClient);
	}
	CordinateString.Format(_T("x: %d , y: %d") , point.x, point.y);
	CordinetBox.SetWindowTextW(CordinateString);
	CDialogEx::OnMouseMove(nFlags, point);
}


void CFinalProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if ((point.x >= WindowForClient.TopLeft().x && point.x <= WindowForClient.BottomRight().x )&&
		point.y >= WindowForClient.TopLeft().y && point.y <= WindowForClient.BottomRight().y){
		isMousePressed = true;
		if (functionType != SText)
			TextFromUser.ShowWindow(SW_HIDE);
		switch (functionType)
		{
		case SLine:
			figs.Add(new Line(point, point, ColorB.GetColor(), BrushSize));
			break;
		case SEllipse:
			figs.Add(new EllipseShape(point, point, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
			break;
		case SRectangles:
			figs.Add(new RectangleShape(point, point, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
			break;
		case SSquare:
			figs.Add(new Square(point, point, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
			break;
		case STriangle:
			figs.Add(new Triangle(point, point, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
			break;
		case SMagenDavid:
			figs.Add(new MagenDavid(point, point, ColorD.GetColor(), ColorB.GetColor(), BrushSize));
			break;
		case Spaint:
			figs.Add(new FreePaint(point, ColorB.GetColor(), BrushSize));
			break;
		case SText:
			if (TextFromUser.IsWindowVisible()){
				TextFromUser.ShowWindow(SW_HIDE);
				UpdateData(true);
				textToDraw.Add(new Text(pointText, inputText , BrushSize));
			}
			else{
				inputText.SetString(_T(""));
				UpdateData(false);
				pointText.SetPoint(point.x, point.y);
				TextFromUser.SetFocus();
				TextFromUser.MoveWindow(CRect(point.x, point.y, point.x + 150, point.y + 30));
				TextFromUser.ShowWindow(SW_SHOW);
			}
			break;
		case Tmove:
			move = false;
			for (i = figs.GetSize() - 1; i >= 0; i--) {
				if (figs[i]->IsInside(point)) {
					move = true;
					movePoint.SetPoint(point.x, point.y);
					moveStart.SetPoint(figs[i]->GetStart().x, figs[i]->GetStart().y);
					moveEnd.SetPoint(figs[i]->GetEnd().x, figs[i]->GetEnd().y);
					break;
				}
			}
			break;
		case TColor:
			for (i = figs.GetSize() - 1; i >= 0; i--) {
				if (figs[i]->IsInside(point)) {
					figs[i]->setColor(ColorD.GetColor());
					figs[i]->setBorder(ColorB.GetColor(), BrushSize);
					break;
				}
			}
			break;
		case Terase:
			for (i = figs.GetSize() - 1; i >= 0; i--) {
				if (figs[i]->IsInside(point)) {
					figs.RemoveAt(i, 1);
					break;
				}
			}
			break;
		case Tresize:
			resize = false;
			for (i = figs.GetSize() - 1; i >= 0; i--) {
				if (figs[i]->IsInside(point)) {
					resize = true; 
					break;
				}
			}
			break;
		default:
			break;
		}
		InvalidateRect(WindowForClient);
		CDialogEx::OnLButtonDown(nFlags, point);
	}
}

void CFinalProjectDlg::OnLButtonUp(UINT nFlags, CPoint point){
	isMousePressed = false;
	CDialogEx::OnLButtonUp(nFlags, point);
}



void CFinalProjectDlg::NewRectangleButton(){functionType = SRectangles;}
void CFinalProjectDlg::NewLineButtom(){functionType = SLine;}
void CFinalProjectDlg::NewMagenDavidButton() { functionType = SMagenDavid; }
void CFinalProjectDlg::NewTriengleButton(){functionType = STriangle;}
void CFinalProjectDlg::NewSquareButton(){functionType = SSquare;}
void CFinalProjectDlg::NewEllipseButton(){functionType = SEllipse;}
void CFinalProjectDlg::TextDrawFlag(){functionType = SText;}
void CFinalProjectDlg::PaintDrawFlag(){functionType = Spaint;}
void CFinalProjectDlg::MoveShapeButton(){functionType = Tmove;}
void CFinalProjectDlg::ChangeFillShapeButton(){functionType = TColor;}
void CFinalProjectDlg::EraseShapeButton(){functionType = Terase;}
void CFinalProjectDlg::ResizeButton(){functionType = Tresize;}

void CFinalProjectDlg::OnBnClickedOk(){	CDialogEx::OnOK();}

void CFinalProjectDlg::ClearAllButton(){
	if (figs.GetSize() > 0)
		figs.RemoveAll();
	if (textToDraw.GetSize() > 0)
		textToDraw.RemoveAll();
	Invalidate();
}

void CFinalProjectDlg::UndoShapeButton(){
	if (figs.GetSize() >= 1)
		figs.RemoveAt(figs.GetSize() - 1, 1);
	Invalidate();
}

void CFinalProjectDlg::UndoTextButton(){
	if (textToDraw.GetSize() >= 1)
		textToDraw.RemoveAt(textToDraw.GetSize() - 1, 1);
	Invalidate();
}


void CFinalProjectDlg::BrushSizeNumbers(NMHDR *pNMHDR, LRESULT *pResult){
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if (pNMUpDown != nullptr)
	{
		if (pNMUpDown->iDelta > 0 && BrushSize > 0)
			BrushSize--;
		else if (pNMUpDown->iDelta < 0 && BrushSize < 5)
			BrushSize++;

	}
	Invalidate();
	*pResult = 0;
}

void CFinalProjectDlg::OnSaveButton()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		textToDraw.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CFinalProjectDlg::OnLoadButton()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		textToDraw.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


