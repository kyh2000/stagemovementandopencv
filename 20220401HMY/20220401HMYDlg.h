
// 20220401HMYDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


#define TM_DISPLAY 100
#define TM_X_HOME_INFO 101
#define TM_Y_HOME_INFO 102
#define DEFAULT_VEL 100
#define DEFAULT_ACC 400
#define DEFAULT_DEC 400
#define DEFAULT_HOME_VEL_FIRST 10
#define DEFAULT_HOME_ACC_FIRST 40
#define DEFAULT_AXIS_NUMBER_X 0
#define DEFAULT_AXIS_NUMBER_Y 1
#define MARGIN 30
#define GAIN_MAIN_ADDRESS_P 0x3100
#define GAIN_MAIN_ADDRESS_D 0x3101
#define GAIN_MAIN_ADDRESS_I 0x3102
#define GAIN_SUB_ADDRESS 0
#define DEFAULT_UNIT 10
#define DEFAULT_PULSE 1048576
#define DEFAULT_REVISION_X 199.1
#define DEFAULT_REVISION_Y 194.7

#define PTP_MAX 2	//PTP 최대 클릭 수
#define REC_MAX 4
#define PEN_MAX 5
// CMy20220401HMYDlg 대화 상자
class CMy20220401HMYDlg : public CDialogEx
{
	// 생성입니다.
public:
	CMy20220401HMYDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_MY20220401HMY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_sliX;
	CSliderCtrl m_sliY;
	CEdit m_edtXInputVel;
	CEdit m_edtXInputAcc;
	CEdit m_edtXInputDec;
	CEdit m_stcXCommPos;
	CEdit m_stcXFeedPos;
	CEdit m_stcXFeedVel;
	CButton m_chkXServoOn;
	CButton m_chkXInMotion;
	CButton m_chkXAlarm;
	CButton m_chkXHomeSignal;
	CButton m_chkXInPosition;
	CButton m_chkXLimitP;
	CButton m_chkXLimitN;
	CButton m_chkXEmg;
	CProgressCtrl m_prgXHomeRate;
	CEdit m_stcXP;
	CEdit m_stcXI;
	CEdit m_stcXD;
	CEdit m_edtYInputVel;
	CEdit m_edtYInputAcc;
	CEdit m_edtYInputDec;
	CEdit m_stcYCommPos;
	CEdit m_stcYFeedPos;
	CEdit m_stcYFeedVel;
	CButton m_chkYServoOn;
	CButton m_chkYInMotion;
	CButton m_chkYAlarm;
	CButton m_chkYHomeSignal;
	CButton m_chkYInPosition;
	CButton m_chkYLimitP;
	CButton m_chkYLimitN;
	CButton m_chkYEmg;
	CProgressCtrl m_prgYHomeRate;
	CEdit m_stcYP;
	CEdit m_stcYI;
	CEdit m_stcYD;
	CEdit m_edtXMovePos;
	CEdit m_editYMovePos;
	CButton m_btnXAlarmClear;
	CButton m_btnXHomeSearch;
	CButton m_btnXPosClear;
	CButton m_btnXSStop;
	CButton m_btnXEStop;
	CButton m_btnYAlarmClear;
	CButton m_btnYHomeSearch;
	CButton m_btnYPosClear;
	CButton m_btnYSStop;
	CButton m_btnYEStop;
	CButton m_btnLoadFile;
	CButton m_btnBothHomeSearch;
	CButton m_btnMoveZeroPos;
	CButton m_btnBothStop;
	CStatic m_pcstage;
	afx_msg void OnBnClickedChkXServoOn();
	afx_msg void OnBnClickedBtnXAlarmClear();
	afx_msg void OnBnClickedBtnXHomeSearch();
	afx_msg void OnBnClickedBtnXPosClear();
	afx_msg void OnBnClickedBtnXSstop();
	afx_msg void OnBnClickedBtnXEstop();
	afx_msg void OnBnClickedChkYServoOn();
	afx_msg void OnBnClickedBtnYAlarmClear();
	afx_msg void OnBnClickedBtnYHomeSearch();
	afx_msg void OnBnClickedBtnYPosClear();
	afx_msg void OnBnClickedBtnYSstop();
	afx_msg void OnBnClickedBtnYEstop();
	afx_msg void OnBnClickedBtnLoadFile();
	afx_msg void OnBnClickedBtnBothHomeSearch();
	afx_msg void OnBnClickedBtnMoveZeroPos();
	afx_msg void OnBnClickedBtnBothEstop();
	afx_msg void OnBnClickedBtnPosMove();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL PreTranslateMessage(MSG* pMsg);


public:
	double m_dXOldCommPos, m_dYOldCommPos;
	double m_dXOldFeedPos, m_dYOldFeedPos;
	double m_dXOldFeedVel, m_dYOldFeedVel;
	long m_lAxisNoX, m_lAxisNoY;
	BOOL m_bXIsMoving, m_bYIsMoving, m_bXStop, m_bYStop;
	int m_pointX, m_pointY, m_realPointX, m_realPointY;
	int Set_Cursor;
	CRect m_rectStage;
	double m_posRevisionX, m_posRevisionY; 

	BOOL InitState();
	BOOL UpdateState();
	void SetDlgItemDouble(int nID, double value, int nPoint = 1);
	double GetDlgItemDouble(int nID);
	CString TranslateAxmResult(DWORD dwAxmResult);
	CButton m_btnPosMove;


	//PTP
	afx_msg void OnBnClickedRadioPtp();		//PTP 클릭 함수
	afx_msg void OnBnClickedRadioCp();		//CP  클릭 함수
	bool btn_ptp;							//PTP 버튼 변수
	bool btn_rec;
	bool btn_cp;	
	bool btn_pen;
	bool btn_vision;
	int rec_points[REC_MAX][4];//CP  버튼 변수
	int rec_click_count;
	int pen_points[PEN_MAX][5];
	int pen_click_count;
	int ptp_points[PTP_MAX][2];				//PTP 위치 저장
	int ptp_click_count;					//PTP 클릭수 저장
	
	long lAxis[2], lPosSize, lCoordinate;	//MouseLbtndown용 변수들
	double dPos[2];							//MouseLbtndown용 변수들
	static UINT ThreadStart(LPVOID pParam);	//Thread 함수
	static UINT VisionThreadStart(LPVOID pParam);

	int cp_radious;
	int cp_dispos[2];
	double cp_start[2];
	afx_msg void OnBnClickedRadioRec();
	afx_msg void OnBnClickedRadioPen();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnBnClickedRadioVision();
};
