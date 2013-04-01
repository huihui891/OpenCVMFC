
// OpenCVMFCView.h : interface of the COpenCVMFCView class
//

#pragma once


class COpenCVMFCView : public CScrollView
{
protected: // create from serialization only
	COpenCVMFCView();
	DECLARE_DYNCREATE(COpenCVMFCView)

// Attributes
public:
	COpenCVMFCDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~COpenCVMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	IplImage* saveImg;
	IplImage* workImg;

	LPBITMAPINFO m_lpBmi;

	int     m_CaptFlag;
	int     m_dibFlag;
	int     m_SaveFlag;
	int     m_ImageType;

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUpdateFileOpen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRefresh(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFileClose(CCmdUI *pCmdUI);
	afx_msg void OnUpdateConservationImage(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorImageRefresh(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFileSaveAs(CCmdUI *pCmdUI);
	afx_msg void OnRefresh();
	afx_msg void OnConservationImage();
	afx_msg void OnFileSaveAs();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in OpenCVMFCView.cpp
inline COpenCVMFCDoc* COpenCVMFCView::GetDocument() const
   { return reinterpret_cast<COpenCVMFCDoc*>(m_pDocument); }
#endif

