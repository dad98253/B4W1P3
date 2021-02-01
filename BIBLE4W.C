#pragma message( "Compiling " __FILE__ " on " __DATE__ " at " __TIME__ )
#pragma message( "File last modified on " __TIMESTAMP__ )
#pragma message( "  ")
#pragma title( "Bible4W version 3.0" )
#pragma comment( compiler )
#pragma comment( user, "Compiled on " __DATE__ " at " __TIME__ ".  Last modified on " __TIMESTAMP__ )

/***************************************************************************
 *									   *
 *  PROGRAM	: bible4w.c						   *
 *									   *
 *  PURPOSE	: To provide a user friendly interface for accessing bible *
 *		  verses from a Microsoft Windows environment.		   *
 *									   *
 *  FUNCTIONS	: WinMain()	      - Calls the initialization function  *
 *					and enters the message loop.	   *
 *									   *
 *		  Bible4wInit()       - Registers the app. window class.   *
 *									   *
 *		  About()	      - Dialog function for the About..    *
 *					dialog. 			   *
 *									   *
 *		  FindDlg()	      - Dialog function for the Find	   *
 *					dialog. 			   *
 *									   *
 *		  GoToDlg()	      - Dialog function for the Go To	   *
 *					dialog. 			   *
 *									   *
 *		  Bible4wPaint()      - Handles repainting the app's client*
 *					area				   *
 *									   *
 *		  Bible4WndProc()     - Window function for the app.	   *
 *									   *
 *		  MakeHelpPathName()  - Derives path name of help file.    *
 *									   *
 ***************************************************************************/

		  /*  + + + + +  Includes  + + + + +  */

#include <windows.h>
#include <windowsx.h>
//#include <penwin.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include <search.h>
#include <fcntl.h>
#include <io.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <ctype.h>
#define NEAR
#define FAR
#define PASCAL
#include "bible4w.h"
#include "wprintf.h"



		   /*  + + + + +  Macros  + + + + +  */

		  /*  + + + + +  Functions  + + + + +  */

BOOL FAR PASCAL Bible4wInit(HINSTANCE, HINSTANCE);
BOOL FAR PASCAL Bible4wPaint ( HWND );
void NEAR GETOC ( long int LOCTC);
void NEAR GETWL ( long int );
void FAR FNDWRD ( int FAR * );
BOOL FAR OpenBible ( HWND );
void NEAR LLConnect ( int , int );
int  NEAR LLBreak   ( int );
int  NEAR LLDist    ( int , int );
BOOL NEAR GetNextLine ( int , int );
void NEAR MakeBufValid ( void );
BOOL FAR MoveToClipBoard ( void );
BOOL FAR CheckPickList ( int Vnum );
void FAR MakeHelpPathName(char*);  /* Function deriving help file path */
void FAR OutOfMem ( void );
short FAR BWError(HWND hwnd, WORD bFlags, WORD quit, WORD id, ...);
BOOL FAR PASCAL fLookUp ( LPSTR szLookUpWord , int iWordLength );
VOID (FAR PASCAL *RegPenApp)(WORD, BOOL) = NULL;
BOOL FAR PASCAL bValidateBookItem ( HWND hDlg , LPINT ibook );
VOID FAR wexit ( int );
VOID NEAR PaintTheDlg ( HWND hDlg );
BOOL FAR OPEN_KJB ( HFILE FAR *pFile, LPSTR szFileName, WORD szMode );
BOOL FAR OPEN_CLIP ( HFILE FAR *pFile, LPSTR szFileName, WORD szMode );
void FAR DisplayKJBError ( void );
VOID FAR PaintWindow(HWND hWnd, int nColor);
HPALETTE NEAR CreateColorScalePalette(HWND hDC, int nColor);
VOID FAR WinPrintfJK ( LPSTR a , ... );
BOOL FAR LockRes (void);
BOOL FAR UnLockRes (void);
int fCompareWords1( unsigned FAR *elem1, unsigned FAR *elem2 );
int fCompareWords2( unsigned FAR *elem1, unsigned FAR *elem2 );
int FAR * jkbsearch(const void FAR * dumarg, int FAR * lpSearchArray,
	size_t nArraySize, size_t nElementSize, int fCompare(
	const void FAR *, const void FAR * ) );
BOOL FAR PASCAL DrawEntireItem(LPDRAWITEMSTRUCT lpdis, int inflate);
void FAR PASCAL HandleSelectionState(LPDRAWITEMSTRUCT lpdis, int inflate);
void FAR PASCAL HandleFocusState(LPDRAWITEMSTRUCT lpdis, int inflate);
VOID FAR PASCAL Index2Word (int i, LPSTR szAword , long int FAR * nLAWORD);


		/*  + + + + +  Static Globals  + + + + +  */

char    szDatabaseName[120];
char *	szCustomDictLib	= "custdict.dll";
char *	szCustomDictProc = "DictionaryProc";
HANDLE 	hCustomDictLib;
//LPDF	lpdfCustomDictProc;
//FARPROC lpfnLookUp;
extern	lpdfCustomDictProc();
extern lpfnLookUp();
BOOL	bBookDict=FALSE;
BOOL	fDebug = FALSE;


HANDLE	 hInst;
HWND	 hWnd;
char	 szAppName[] = "Bible4W ver 3.0";
char	 szClassName[] = "Bib3p0";
HANDLE	 hPenWin;
HANDLE	 hVertChapMS;
HANDLE	 hVertVerMS;
HANDLE	 hCombo;
short	 cxChar = 9;
short	 cxCaps;
short	 cyChar = 9;
int	 nNumChars;
long int ID;
short glocxChar , glocyChar;
int nGotoFocus;

OFSTRUCT ofKJB;
OFSTRUCT ofCLIP;
BOOL bFirstOpenKJB = TRUE;
BOOL bFirstOpenCLIP = TRUE;
WORD wKJBDriveType;
WORD wCLIPDriveType;
BOOL bCriticalSection1 = FALSE;

unsigned char IWLT;
//char a[maxlin_dim];		  what was this used for ????
char AWORD[133];
//char ALN[82]; 		  what was this used for ????
//char huge (*hpWORDS)[ndimw_dim][nlenw_dim];
char FAR *lpWords1;
char FAR *lpWords2;
GLOBALHANDLE hWords1;
GLOBALHANDLE hWords2;
char FAR *lpListSizes;
GLOBALHANDLE hListSizes;
long int iFirstd;
char szFirstChar[]="k";  // k is the default... read in in GETWL
UINT iSizeWord1, iSizeWord2, iSizeWordp1, iSizeWordp2;
BOOL bShowNumRefs=FALSE;
//char FNAME[11];		  what was this used for ????
HFILE IUNIT10;
HFILE IUNIT11;
int I2WRD ;
int IBSHI , IBSLOW;
//long int LWS[257];		  what was this used for ????
//long int huge (*hpIWS)[maxwrd_dim];
int FAR *lpPoWords1;
int FAR *lpPoWords2;
GLOBALHANDLE hPoWords1;
GLOBALHANDLE hPoWords2;
BOOL bDoListAtoK;
BOOL bCaseSensitive;
int ITVERS , IVERS , ICHAP;
// unsigned char LWL[257] , NWL;  what was this used for ????

long int IR,IVSG,IVS,IVE,IVW;
unsigned char ICAP;
unsigned char GOODNA;

long int LAWORD , LASTWD , LASTSB , NHASH;
long int IER;
int I2ZERO;
long int LASTAD , IRECIN , IRMOD;
int I2IX[257];		      // buffer used by getwrd routines

// int IADVER[501] , LASTVR;	 what was this used for ????
long int IBASVR;
short cxClient;
short cyClient;
int   cxScreen;
int   cyScreen;
int   cxDlgFrame;
int   cyDlgFrame;
int   cyCaption;
GLOBALHANDLE hDCBuffer	   = NULL;
typedef struct tagVERSEREFS
 {
	     long int VerseStart;
	     long int VerseEnd;
	     int  VerseNum;
	     BOOL picked;
 } VERSEREFS;
VERSEREFS VerseRefs[VerseRefBufSize];
BOOL isPicked;
int nVerseRefTop = 0;
int nNumLinesInBuffer;
int nNumColsInBuffer;
int nTOS = -1;
int nTOB = 0;
int nBOB = 0;
int nTBOB = 0;
typedef struct tagBUFPOINT
 {
	     int  refnum;
    unsigned char length;
    unsigned char line;
    unsigned char forward;
    unsigned char backward;
	     BOOL picked;
 } BUFPOINT;
BUFPOINT BufPoint[VerseRefBufSize];
BOOL bValidBuffer;
int nTopIRRef;
unsigned char nRefLine;
HDC hdc;
RECT rc;
LPSTR lpBuffer;
int nGoToRef;
unsigned char ucGoToLine;

union chps
{
    int I2AC[2402];
    long int IADCHP[1201];
}  chap;
union bks
{
    int I2BK[136];
    long int IADBOK[68];
}  book;
unsigned int unBook2Chap[68];

long int LASTCH;

long int IADIN , IADOFF, IADSOV;
int I2WORD;
int I2REF;
int I2WOLD;
int I2NREF;

//  unsigned char LV[2401];	  what was this for ???????

int I2VER;
union ptts
{
    int I2POI[2];
    long int IPOINT;
}  ipoint;

union lohi
{
    int I2HILO[2];
    long int I4HILO;
}  hilo;

union Word__Byte
{
    WORD Word;
    char Byte[2];
} Word_Byte;

char books[67][3] =
{
    "   ",
    "GEN",
    "EXO",
    "LEV",
    "NUM",
    "DEU",
    "JOS",
    "JDG",
    "RTH",
    "SA1",
    "SA2",
    "KI1",
    "KI2",
    "CH1",
    "CH2",
    "EZR",
    "NEH",
    "EST",
    "JOB",
    "PSA",
    "PRO",
    "ECC",
    "SON",
    "ISA",
    "JER",
    "LAM",
    "EZE",
    "DAN",
    "HOS",
    "JOE",
    "AMO",
    "OBA",
    "JON",
    "MIC",
    "NAH",
    "HAB",
    "ZEP",
    "HAG",
    "ZEC",
    "MAL",
    "MAT",
    "MAR",
    "LUK",
    "JOH",
    "ACT",
    "ROM",
    "CO1",
    "CO2",
    "GAL",
    "EPH",
    "PHI",
    "COL",
    "TH1",
    "TH2",
    "TI1",
    "TI2",
    "TIT",
    "PHM",
    "HEB",
    "JAM",
    "PE1",
    "PE2",
    "JO1",
    "JO2",
    "JO3",
    "JUD",
    "REV"
};
int nPickList[PICKLISTSIZE];
int nNumPicks = 0;
char szHelpFileName[EXE_NAME_MAX_SIZE+1];    /* Help file name*/
int DebugFlag;


/****************************************************************************
 *									    *
 *  FUNCTION   : WinMain(HANDLE, HANDLE, LPSTR, int)			    *
 *									    *
 *  PURPOSE    : Creates the main app. window, calls an initialization	    *
 *		 function and enters the message loop.			    *
 *									    *
 ****************************************************************************/
int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR  lpCmdLine, int nCmdShow)
{
    MSG   msg;
    HANDLE hAccel;

/* Save the Instance handel */

    hInst = hInstance;

#ifdef DEBUG
    fDebug = TRUE;
    dprintf("%C");
#endif

/* Register main window class if this is the first instance of the app. */

    if ( !Bible4wInit (hInstance,hPrevInstance ) ) return NULL;

    ShowWindow (hWnd, nCmdShow);
    UpdateWindow (hWnd);

    hAccel = LoadAccelerators ( hInstance , szAppName );

    while (GetMessage (&msg, NULL, NULL, NULL))
    {
	if ( !TranslateAccelerator ( hWnd , hAccel , &msg ) )
	{
	    TranslateMessage (&msg);
	    DispatchMessage (&msg);
	}
    }
    return((int)msg.wParam);
}

#pragma  alloc_text( SEG2, About )

/****************************************************************************
 *									    *
 *  FUNCTION   : About (hDlg, message, wParam, lParam)			    *
 *									    *
 *  PURPOSE    : Dialog function for the About Bible4w... dialog.	    *
 *									    *
 ****************************************************************************/
BOOL CALLBACK  About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_INITDIALOG:
            SetFocus(GetDlgItem(hDlg,IDOK));
	    return(TRUE);
	    break;

	case WM_COMMAND:
	    switch (wParam)
	    {
	    case IDOK:
	    case IDCANCEL:
		EndDialog(hDlg,NULL);
		return(TRUE);
		break;

            default:
                return(FALSE);
	    }
	    break;

    // Wash the background of the aboutbox to give it a nice blue-scaling
    // effect.  Invalidate the OK button to force it to the top.  This
    // seems to be necessary since the OK button gets overwritten during
    // the washing.
    case WM_PAINT:
        PaintWindow(hDlg,COLOR_SCALE_BLUE);
        InvalidateRect(GetDlgItem(hDlg,IDOK),NULL,TRUE);

    case WM_CTLCOLOR:
	if ( HIWORD (lParam) == CTLCOLOR_STATIC )
	{
	   SetBkMode((HDC)wParam,TRANSPARENT);
	   SetTextColor((HDC)wParam,GetSysColor(COLOR_GRAYTEXT));
	   return ((int)(HBRUSH) GetStockObject ( NULL_BRUSH ));
	}
        break;

    }

  //	  default:
  //	      return ( DefDlgProc ( hDlg, message, wParam, lParam ) );
  //	      return(TRUE);
  //	      break;
    return(FALSE);
}

#pragma  alloc_text( SEG2, About )
//
//  FUNCTION: PaintWindow()
//
//  PURPOSE: This routine is used to wash the background of a window.
//

VOID FAR PaintWindow(HWND hWnd, int nColor)
{
    HDC         hDC;
    int         nMapMode,idx,nSize,nReserved,nLoop;
    RECT        rect;
    HBRUSH      hBrush;
    PAINTSTRUCT ps;
    HPALETTE    hPal;

    if (hDC = BeginPaint(hWnd,&ps)) {
        GetClientRect(hWnd,&rect);
        nMapMode = SetMapMode(hDC,MM_ANISOTROPIC);

        if (GetDeviceCaps(hDC,RASTERCAPS) & RC_PALETTE) {
            nReserved = GetDeviceCaps(hDC,NUMRESERVED);
            nSize     = GetDeviceCaps(hDC,SIZEPALETTE) - nReserved;

            if (hPal = CreateColorScalePalette(hDC,nColor))
            {
                hPal = SelectPalette(hDC,hPal,FALSE);
                RealizePalette(hDC);

#ifdef WIN16
                SetWindowExtEx(hDC,nSize,nSize);
                SetViewportExtEx(hDC,rect.right,-rect.bottom);
                SetViewportOrgEx(hDC,0,rect.bottom);
#else
                SetWindowExtEx(hDC,nSize,nSize,NULL);
                SetViewportExtEx(hDC,rect.right,-rect.bottom,NULL);
                SetViewportOrgEx(hDC,0,rect.bottom,NULL);
#endif

                nLoop = nSize >> 1;
                for (idx=0; idx < nLoop; idx++) {
                    hBrush = CreateSolidBrush(PALETTEINDEX(idx+nLoop));
                    SetRect(&rect,idx,idx,nSize-idx,nSize-idx);
                    FillRect(hDC,&rect,hBrush);
                    DeleteObject(hBrush);
                }
                DeleteObject(SelectPalette(hDC,hPal,FALSE));
                RealizePalette(hDC);
            }
        }
        else
        {

#ifdef WIN16
            SetWindowExtEx(hDC,512,512);
            SetViewportExtEx(hDC,rect.right,-rect.bottom);
            SetViewportOrgEx(hDC,0,rect.bottom);
#else
            SetWindowExtEx(hDC,512,512,NULL);
            SetViewportExtEx(hDC,rect.right,-rect.bottom,NULL);
            SetViewportOrgEx(hDC,0,rect.bottom,NULL);
#endif
            for (idx=0; idx < 256; idx++) {
                hBrush = CreateSolidBrush(RGB(0,0,idx));
                SetRect(&rect,idx,idx,512-idx,512-idx);
                FillRect(hDC,&rect,hBrush);
                DeleteObject(hBrush);
            }
        }

        SetMapMode(hDC,nMapMode);

        EndPaint(hWnd,&ps);
    }
    return;
}


#pragma  alloc_text( SEG2, About )
//
//  FUNCTION: CreateColorScalePalette()
//
//  PURPOSE: This routine creates a palette representing the scale values of a
//           particular RGB color.  A gray-scale palette can also be created.
//

HPALETTE NEAR CreateColorScalePalette(HWND hDC, int nColor)
{
    HPALETTE     hPalette;
    GLOBALHANDLE hMem;
    LPLOGPALETTE lpMem;
    int          idx,nReserved,nSize;

    hPalette = NULL;
    if (GetDeviceCaps(hDC,RASTERCAPS) & RC_PALETTE) {
        nReserved = GetDeviceCaps(hDC,NUMRESERVED);
        nSize     = GetDeviceCaps(hDC,SIZEPALETTE) - nReserved;

        if (hMem = GlobalAlloc(GHND,(DWORD)sizeof(LOGPALETTE)+(sizeof(PALETTEENTRY)*nSize))) {
            if(lpMem = (LPLOGPALETTE)GlobalLock(hMem)) {
                lpMem->palNumEntries = (WORD)nSize;
                lpMem->palVersion    = (WORD)0x0300;

                switch(nColor) {
                case COLOR_SCALE_RED:
                    for (idx=0; idx < nSize; idx++) {
                        lpMem->palPalEntry[idx].peRed   = (BYTE)idx;
                        lpMem->palPalEntry[idx].peGreen = 0;
                        lpMem->palPalEntry[idx].peBlue  = 0;
                        lpMem->palPalEntry[idx].peFlags = PC_RESERVED;
                    }
                    break;

                case COLOR_SCALE_GREEN:
                    for (idx=0; idx < nSize; idx++) {
                        lpMem->palPalEntry[idx].peRed   = 0;
                        lpMem->palPalEntry[idx].peGreen = (BYTE)idx;
                        lpMem->palPalEntry[idx].peBlue  = 0;
                        lpMem->palPalEntry[idx].peFlags = PC_RESERVED;
                    }
                    break;

                case COLOR_SCALE_BLUE:
                    for (idx=0; idx < nSize; idx++) {
                        lpMem->palPalEntry[idx].peRed   = 0;
                        lpMem->palPalEntry[idx].peGreen = 0;
                        lpMem->palPalEntry[idx].peBlue  = (BYTE)idx;
                        lpMem->palPalEntry[idx].peFlags = PC_RESERVED;
                    }
                    break;

                default:
                case COLOR_SCALE_GRAY:
                    for (idx=0; idx < nSize; idx++) {
                        lpMem->palPalEntry[idx].peRed   = (BYTE)idx;
                        lpMem->palPalEntry[idx].peGreen = (BYTE)idx;
                        lpMem->palPalEntry[idx].peBlue  = (BYTE)idx;
                        lpMem->palPalEntry[idx].peFlags = PC_RESERVED;
                    }
                    break;
                }

                hPalette = CreatePalette(lpMem);

                GlobalUnlock(hMem);
            }
            GlobalFree(hMem);
        }
    }
    return(hPalette);
}


#pragma  alloc_text( SEG3, FindDlg )
/****************************************************************************
 *									    *
 *  FUNCTION   : FindDlg (hDlg, message, wParam, lParam)		    *
 *									    *
 *  PURPOSE    : Dialog function for the Find dialog box.		    *
 *									    *
 ****************************************************************************/
BOOL CALLBACK  FindDlg(hDlg, message, wParam, lParam)

HWND hDlg;
unsigned message;
WORD wParam;
LONG lParam;

{
    int I;
    HANDLE hDlgItem;
    RC rcin;
    int nOldI2NREF;
    DLGPROC lpProc;
    UINT uWordIndex;
    static int nNextChar;

    switch (message){
	case WM_INITDIALOG:
	    if ( hPenWin )
	    {
		/* Create Hedit window. */
		/* If running on a Pen Windows system, this app will have
			been registered, so all EDIT controls will be changed to
			HEDIT controls */

		hDlgItem = GetDlgItem (hDlg , DLGFINDEDITBOX );

		/* Set RC preferences for this edit control */

		if (SendMessage(hDlgItem, WM_HEDITCTL, HE_GETRC,
						      (LONG)((LPRC)&rcin)))
		{
		   rcin.dwDictParam = (DWORD)lpfnLookUp;
		   bBookDict=FALSE;
		   rcin.alc = ALC_ALPHA | ALC_GESTURE ;
     // 	     rcin.lRcOptions = rcin.lRcOptions | RCO_SUGGEST ;
		   rcin.rglpdf[0] = lpdfCustomDictProc;
		   rcin.rglpdf[1] = NULL;
		   if ( SendMessage(hDlgItem, WM_HEDITCTL, HE_SETRC,
					     (LONG)((LPRC)&rcin)) != TRUE )
		   {
		      (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CANTRECOGNIZE );
		   }
		}
	    }
	    return(TRUE);

	case WM_COMMAND:
	    switch (wParam)
	    {

	    case DLGFINDOK:
		for ( I = 1 ; I <= 32 ; I++ ) AWORD[I] = '\0';
		GetDlgItemText (hDlg , DLGFINDEDITBOX , &AWORD[1], 30 );
		EndDialog(hDlg,NULL);
		if ( AWORD[1] != ' '  )
		{
		    LAWORD = 0;
		    for ( I = 1 ; I <= min ( 32 , _fstrlen ( &AWORD[1] ) ) ; I++ )
		    {
			if ( AWORD[I] != ' ' ) LAWORD = I;
		    }
		    if ( LAWORD == 0 ) return(TRUE);
		    nOldI2NREF = I2NREF;
		    FNDWRD ( &I2NREF );
		    if ( (LONG)I2NREF > NPUN && I2NREF != 0 )
		    {
			ID = (LONG)I2NREF;
			I2NREF = 0;
			ICAP = FALSE;
                        if ( OPEN_KJB ( &IUNIT10 , szDatabaseName ,
				      OF_READ | OF_REOPEN
				     | OF_SHARE_DENY_WRITE ) ) return (TRUE);
			GETWRD ( &ipoint.I2POI[0] , IADOFF + ID * 2 - 2 );
			GETWRD ( &ipoint.I2POI[1] , IADOFF + ID * 2 - 1 );
			GETWRD ( &I2NREF , ipoint.IPOINT );
			_lclose ( IUNIT10 );
			IR = IVSG = IVS = IVE = IVW = 0;
			nGoToRef = 1;
			nTopIRRef = 3 * VerseRefBufSize;
			ucGoToLine = 1;
			nTOS = -1;
			bValidBuffer = FALSE;
			nNumPicks = 0;

			SetScrollRange ( hWnd , SB_VERT , 1 , I2NREF , FALSE );
			SetScrollPos   ( hWnd , SB_VERT , 1 , TRUE );
			InvalidateRect ( hWnd, NULL, TRUE);
			UpdateWindow (hWnd);
		    }
		    else
		    {
		       I2NREF = nOldI2NREF;
		       (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_NOFINDWRD );
		    }
		}
		return(TRUE);

	    case DLGFINDCANCEL:
		EndDialog(hDlg,NULL);
		return(TRUE);
		break;

	    case IDCANCEL:
		EndDialog(hDlg,NULL);
		return(TRUE);
		break;

	    case DLGFINDWORDLIST1:
		// Bring up the word list dialog box
		lpProc = (DLGPROC)MakeProcInstance ((FARPROC)WordListDlg,
								      hInst);
		bDoListAtoK = TRUE;
		uWordIndex = (UINT)DialogBox (hInst, "DlgWordList", hWnd,
								     lpProc);
		FreeProcInstance ((FARPROC)lpProc);
		SetFocus ( hDlg );
		nNextChar = GetDlgItemText (hDlg , DLGFINDEDITBOX , &AWORD[1] ,
							sizeof(AWORD)-1 ) + 1;
		if ( nNextChar != 1 )
		{
		   AWORD[nNextChar] = ' ';
		   nNextChar++;
		   AWORD[nNextChar] = '+';
		   nNextChar++;
		   AWORD[nNextChar] = ' ';
		   nNextChar++;
		}
		Index2Word ( (int)uWordIndex, &AWORD[nNextChar] , &LAWORD );
		nNextChar += LAWORD;
		SetDlgItemText (hDlg , DLGFINDEDITBOX , &AWORD[1] );
		return(TRUE);
		break;

	    case DLGFINDWORDLIST2:
		// Bring up the word list dialog box
		lpProc = (DLGPROC)MakeProcInstance ((FARPROC)WordListDlg,
								      hInst);
		bDoListAtoK = FALSE;
		uWordIndex = (UINT)DialogBox (hInst, "DlgWordList", hWnd,
								     lpProc);
		FreeProcInstance ((FARPROC)lpProc);
		SetFocus ( hDlg );
		nNextChar = GetDlgItemText (hDlg , DLGFINDEDITBOX , &AWORD[1] ,
							sizeof(AWORD)-1 ) + 1;
		if ( nNextChar != 1 )
		{
		   AWORD[nNextChar] = ' ';
		   nNextChar++;
		   AWORD[nNextChar] = '+';
		   nNextChar++;
		   AWORD[nNextChar] = ' ';
		   nNextChar++;
		}
		Index2Word ( (int)uWordIndex, &AWORD[nNextChar] , &LAWORD );
		nNextChar += LAWORD;
		SetDlgItemText (hDlg , DLGFINDEDITBOX , &AWORD[1] );
		return(TRUE);
		break;

	    case DLGFINDADVANCED:
		break;

	//    case DLGFINDWORDLB:
		// Process the Word List listbox control messages
	//	switch ( HIWORD(lParam) )
	//	{
	//	case (WORD)CBN_ERRSPACE:
	//	    break;
	//	}
	//	return(TRUE);
	//	break;

	    }
	    break;
    }
    return(FALSE);
}


/****************************************************************************
 *									    *
 *  FUNCTION   : Index2Word (INT i, LPSTR szAword, *long INT nLAWORD)	    *
 *									    *
 *  PURPOSE    : Convert a dictionary index number to a string.		    *
 *									    *
 ****************************************************************************/
VOID FAR PASCAL Index2Word (int i, LPSTR szAword , long int FAR * nLAWORD)
{
int IS2, IS3, IWLT2;

   if ( i < iFirstd )
   {
      IS2 = *(lpPoWords1 + i );
      IS3 = *(lpPoWords1 + i + 1 );
      IWLT2 = IS3 - IS2;
      _fstrncpy( szAword, lpWords1+IS2, (size_t)IWLT2 );
   }
   else
   {
      IS2 = *(lpPoWords2 + i - iFirstd );
      IS3 = *(lpPoWords2 + i + 1 - iFirstd );
      IWLT2 = IS3 - IS2;
      _fstrncpy( szAword, lpWords2+IS2, (size_t)IWLT2 );
   }
   szAword[IWLT2] = '\000';
   *nLAWORD = (long int)IWLT2;
   return;
}


#pragma  alloc_text( SEG3, WordListDlg )
/****************************************************************************
 *									    *
 *  FUNCTION   : WordListDlg (hDlg, message, wParam, lParam)		    *
 *									    *
 *  PURPOSE    : Dialog function for the WordList dialog box.		    *
 *									    *
 ****************************************************************************/
BOOL CALLBACK  WordListDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
int i;
LPDRAWITEMSTRUCT	lpdis;
LPMEASUREITEMSTRUCT	lpmis;
DWORD dwIndex;
int IS1, IS2, IS3, IWLT1, IWLT2;
BOOL bFirstError=FALSE;
int nListStart, nListEnd;

    switch (message)
	{
	case WM_INITDIALOG:
	    if ( bDoListAtoK )
	    {
	       nListStart = 17;
	       nListEnd = ( iSizeWordp1 >> 1 ) - 1;
	    }
	    else
	    {
	       nListStart = ( iSizeWordp1 >> 1 ) - 1;
	       nListEnd = ( iSizeWordp1 >> 1 ) + ( iSizeWordp2 >> 1 ) - 2; // 13856
	    }
	    for ( i = nListStart ; i < nListEnd	; i++ )
	    {
//	       if ( i < iFirstd )
//	       {
//		  IS1 = *(lpPoWords1 + i - 1 );
//		  IS2 = *(lpPoWords1 + i     );
//		  IS3 = *(lpPoWords1 + i + 1 );
//		  IWLT1 = IS2 - IS1;
//		  IWLT2 = IS3 - IS2;
//		  if ( IWLT1 == IWLT2 )
//		  {
//		     if ( _fstrnicmp( lpWords1+IS1 , lpWords1+IS2 ,
//				      (size_t)IWLT1 ) == 0 ) continue;
//		  }
//	       }
//	       else
//	       {
//		  if ( i != iFirstd )
//		  {
//		     IS1 = *(lpPoWords2 + i - 1 - iFirstd );
//		     IS2 = *(lpPoWords2 + i - iFirstd );
//		     IS3 = *(lpPoWords2 + i + 1 - iFirstd );
//		     IWLT1 = IS2 - IS1;
//		     IWLT2 = IS3 - IS2;
//		     if ( IWLT1 == IWLT2 )
//		     {
//			if ( _fstrnicmp( lpWords2+IS1 , lpWords2+IS2 ,
//					 (size_t)IWLT1 ) == 0 ) continue;
//		     }
//		  }
//	       }
	       dwIndex = SendDlgItemMessage ( hDlg, DLGWORDLISTLB,
						LB_ADDSTRING, 0, (DWORD)i );
	       if ( ( dwIndex == LB_ERR || dwIndex == LB_ERRSPACE ) &&
		      bFirstError )
	       {
		  (void)BWError ( hWnd,
		    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
		    , 0 , IDS_OWNERLISTBOX , i );
	      //	  EndDialog(hDlg,NULL);
		  bFirstError = FALSE;
		  break;
	       }
	    }
	    break;

	case WM_COMMAND:
	    switch (wParam)
	    {

	    case DLGWORDLISTOK:
		dwIndex = SendDlgItemMessage ( hDlg, DLGWORDLISTLB,
						LB_GETCURSEL, 0, 0 );
		if ( dwIndex != LB_ERR )
		{
		   EndDialog ( hDlg, (int)SendDlgItemMessage ( hDlg,
		      DLGWORDLISTLB, LB_GETITEMDATA, (WPARAM)dwIndex, 0L ) );
		}
		else
		{
		   EndDialog(hDlg,NULL);
		}
		break;

	    case DLGWORDLISTCANCEL:
		EndDialog(hDlg,NULL);
		break;

	    }
	    break;

	case WM_DRAWITEM:
	    /* Get pointer to the DRAWITEMSTRUCT */
	    lpdis = (LPDRAWITEMSTRUCT)lParam;

	    if (lpdis->itemID == -1)
	    {
		/* We have a request to draw an item in the list box, yet there
		 * are no list box items. This is sent when the user TABS into
		 * an empty list box or an empty list box gets the focus. We
		 * have to indicate (somehow) that this owner-draw list box has
		 * the focus. We do it in response to this message. Note that
		 * lpdis->itemData field would be invalid in this instance so
		 * we can't allow it to fall into our standard routines.
		 */
		HandleFocusState(lpdis, -5);
	    }
	    else
	    {
		switch (lpdis->itemAction)
		{
			case ODA_DRAWENTIRE:
			    // -7 -3 -5
				if ( DrawEntireItem(lpdis, -1) )
				{
				   EndDialog(hDlg,NULL);
				}
				break;

			case ODA_SELECT:
				HandleSelectionState(lpdis, 1);
				break;

			case ODA_FOCUS:
				HandleFocusState(lpdis, 0);
				break;
		}
	    }

	    /* Return TRUE meaning that we processed this message. */
	    break;

	case WM_MEASUREITEM:
	    lpmis = (LPMEASUREITEMSTRUCT)lParam;

	    /* All the items are the same height since the list box style is
	     * LBS_OWNERDRAWFIXED
	     */
	    lpmis->itemHeight = 15;
	    break;

	case WM_CLOSE:
	    EndDialog(hDlg, NULL);
	    break;

	default:
	    return(FALSE);

	}
    return(TRUE);
}


/****************************************************************************
 *                                                                          *
 *  FUNCTION   : HandleSelectionState(LPDRAWITEMSTRUCT, int)                *
 *                                                                          *
 *  PURPOSE    : Handles a change in an item selection state. If an item is *
 *               selected, a black rectangular frame is drawn around that   *
 *               item; if an item is de-selected, the frame is removed.     *
 *                                                                          *
 *  COMMENT    : The black selection frame is slightly larger than the gray *
 *               focus frame so they won't paint over each other.           *
 *                                                                          *
 ****************************************************************************/
#pragma  alloc_text( SEG3, HandleSelectionState )
void FAR PASCAL HandleSelectionState(LPDRAWITEMSTRUCT lpdis, int inflate)
{
	RECT	rc;
	HBRUSH	hbr;

	/* Resize rectangle to place selection frame outside of the focus
	 * frame and the item.
	 */
	CopyRect ((LPRECT)&rc, (LPRECT)&lpdis->rcItem);
	InflateRect ((LPRECT)&rc, inflate, inflate);

	if (lpdis->itemState & ODS_SELECTED)
	{
		/* selecting item -- paint a black frame */
		FrameRect(lpdis->hDC, (LPRECT)&rc, GetStockObject(BLACK_BRUSH));
	}
	else
	{
		/* de-selecting item -- remove frame */
		hbr = CreateSolidBrush(GetSysColor(COLOR_WINDOW));
		FrameRect(lpdis->hDC, (LPRECT)&rc, hbr);
		DeleteObject (hbr);
	}

}

/****************************************************************************
 *                                                                          *
 *  FUNCTION   : HandleFocusState(LPDRAWITEMSTRUCT, int)                    *
 *                                                                          *
 *  PURPOSE    : Handle a change in item focus state. If an item gains the  *
 *               input focus, a gray rectangular frame is drawn around that *
 *               item; if an item loses the input focus, the gray frame is  *
 *               removed.                                                   *
 *                                                                          *
 *  COMMENT    : The gray focus frame is slightly smaller than the black    *
 *               selection frame so they won't paint over each other.       *
 *                                                                          *
 ****************************************************************************/
#pragma  alloc_text( SEG3, HandleFocusState )
void FAR PASCAL HandleFocusState(LPDRAWITEMSTRUCT lpdis, int inflate)
{
	RECT	rc;
	HBRUSH	hbr;

	/* Resize rectangle to place focus frame between the selection
	 * frame and the item.
	 */
	CopyRect ((LPRECT)&rc, (LPRECT)&lpdis->rcItem);
	InflateRect ((LPRECT)&rc, inflate, inflate);

	if (lpdis->itemState & ODS_FOCUS)
	{
		/* gaining input focus -- paint a gray frame */
		FrameRect(lpdis->hDC, (LPRECT)&rc, GetStockObject(GRAY_BRUSH));
	}
	else
	{
		/* losing input focus -- remove (paint over) frame */
		hbr = CreateSolidBrush(GetSysColor(COLOR_WINDOW));
		FrameRect(lpdis->hDC, (LPRECT)&rc, hbr);
		DeleteObject (hbr);
	}
}

/****************************************************************************
 *                                                                          *
 *  FUNCTION   : DrawEntireItem(LPDRAWITEMSTRUCT, int)                      *
 *                                                                          *
 *  PURPOSE    : Draws an item and frames it with a selection frame and/or  *
 *               a focus frame when appropriate.                            *
 *                                                                          *
 ****************************************************************************/
#pragma  alloc_text( SEG3, DrawEntireItem )
BOOL FAR PASCAL DrawEntireItem(LPDRAWITEMSTRUCT lpdis, int inflate)
{
RECT	rc;
char szWord[33];
int IS1,IS2,IWLT,i;

	/* Resize rectangle to leave space for frames */
	CopyRect ((LPRECT)&rc, (LPRECT)&lpdis->rcItem);
	InflateRect ((LPRECT)&rc, inflate, inflate);

	if ( LockRes () ) return ( TRUE );

	if ( lpdis->itemData < iFirstd )
	{
	   IS1 = *(lpPoWords1 + lpdis->itemData );
	   IS2 = *(lpPoWords1 + lpdis->itemData + 1 );
	   IWLT = IS2 - IS1;
	   _fstrncpy( szWord , lpWords1+IS1 , (size_t)IWLT );
	}
	else
	{
	   IS1 = *(lpPoWords2 + lpdis->itemData - iFirstd );
	   IS2 = *(lpPoWords2 + lpdis->itemData - iFirstd + 1 );
	   IWLT = IS2 - IS1;
	   _fstrncpy( szWord , lpWords2+IS1 , (size_t)IWLT );
	}
	szWord[IWLT] = '\000' ;
	if ( bShowNumRefs )
	{
	   for ( i = IWLT ; i < 33 ; i++ ) szWord[i] = ' ';
	   if ( UnLockRes () ) return ( TRUE );
	   ID = (LONG)lpdis->itemData + 1;
	   I2NREF = 0;
	   if ( OPEN_KJB ( &IUNIT10 , szDatabaseName , OF_READ | OF_REOPEN
				     | OF_SHARE_DENY_WRITE ) ) return (TRUE);
	   GETWRD ( &ipoint.I2POI[0] , IADOFF + ID * 2 - 2 );
	   GETWRD ( &ipoint.I2POI[1] , IADOFF + ID * 2 - 1 );
	   GETWRD ( &I2NREF , ipoint.IPOINT );
	   _lclose ( IUNIT10 );
	   wvsprintf ( &szWord[25], "%5u", &I2NREF );
	   szWord[32] = '\000' ;

	   TextOut ( lpdis->hDC, rc.right -
		     LOWORD( GetTextExtent ( lpdis->hDC, &szWord[25], 5 ) ),
						    rc.top, &szWord[25], 5 );
	}

	TextOut ( lpdis->hDC, rc.left, rc.top, szWord, IWLT );
 //	TextOut ( lpdis->hDC, rc.left, rc.top-15, szWord, IWLT );

	/* Draw or erase appropriate frames */
	HandleSelectionState(lpdis, inflate + 2);
	HandleFocusState(lpdis, inflate + 1);
	return ( FALSE );
}



#pragma  alloc_text( SEG4, GoToDlg )
/****************************************************************************
 *									    *
 *  FUNCTION   : GoToDlg (hDlg, message, wParam, lParam)		    *
 *									    *
 *  PURPOSE    : Dialog function for the Go To dialog box.		    *
 *									    *
 ****************************************************************************/
BOOL CALLBACK _export GoToDlg(hDlg, message, wParam, lParam)

HWND hDlg;
unsigned message;
WORD wParam;
LONG lParam;

{
    int ibook , ichap , iver, itmp;
    BOOL bTrans, bFrom;
    HANDLE hDlgItem;
    RC rcin;
    DLGPROC lpProc;
    char szTemp[20];
    char szFmt1[]="(%i)";
    int nReturnValue, iIDEdit, iJCK;
    WORD wMax, wMin, wPos, wNum;
    HANDLE hVertEdit;
    DWORD dwRange, dwIndex;

    switch (message)
    {
	case WM_INITDIALOG:
	    nGotoFocus=0;
	    hVertChapMS= GetDlgItem (hDlg , DLGGOTOCHAPSPIN );
	    hVertVerMS= GetDlgItem (hDlg , DLGGOTOVERSPIN );
	    if ( hPenWin )
	    {
		/* Create Hedit window. */
		/* If running on a Pen Windows system, this app will have
			been registered, so all EDIT controls will be changed to
			HEDIT controls */
/*  p

		hDlgItem = GetDlgItem (hDlg , DLGGOTOBOOKCOMBO );

		// set RC preferences for this edit control

		if (SendMessage(hDlgItem, WM_HEDITCTL, HE_GETRC,
						      (LONG)((LPRC)&rcin)))
		{
		   rcin.dwDictParam = (DWORD)lpfnLookUp;
		   bBookDict=TRUE;
		   rcin.alc = ALC_ALPHA | ALC_NUMERIC | ALC_GESTURE ;
	  //	     rcin.lRcOptions = rcin.lRcOptions | RCO_SUGGEST ;
		   rcin.rglpdf[0] = lpdfCustomDictProc;
		   rcin.rglpdf[1] = NULL;
		   if ( SendMessage(hDlgItem, WM_HEDITCTL, HE_SETRC,
					     (LONG)((LPRC)&rcin)) != TRUE )
		   {
		      (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CANTRECOGBOOK );
		   }
		}
p */
		hDlgItem = GetDlgItem (hDlg , DLGGOTOCHAPEDIT );

		/* Set RC preferences for this edit control */

		if (SendMessage(hDlgItem, WM_HEDITCTL, HE_GETRC,
						      (LONG)((LPRC)&rcin)))
		{
		   rcin.alc = ALC_NUMERIC | ALC_GESTURE ;
	//	     rcin.lRcOptions = rcin.lRcOptions | RCO_SUGGEST ;
		   if ( SendMessage(hDlgItem, WM_HEDITCTL, HE_SETRC,
					     (LONG)((LPRC)&rcin)) != TRUE )
		   {
		    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CANTRECOGCHAPT );
		   }
		}
		hDlgItem = GetDlgItem (hDlg , DLGGOTOVEREDIT );

		/* Set RC preferences for this edit control */

		if (SendMessage(hDlgItem, WM_HEDITCTL, HE_GETRC,
						      (LONG)((LPRC)&rcin)))
		{
		   rcin.alc = ALC_NUMERIC | ALC_GESTURE ;
	  //	     rcin.lRcOptions = rcin.lRcOptions | RCO_SUGGEST ;
		   if ( SendMessage(hDlgItem, WM_HEDITCTL, HE_SETRC,
					     (LONG)((LPRC)&rcin)) != TRUE )
		   {
		      (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CANTRECOGVER );
		   }
		}
	    }
//  p	    else
//  p	    {
		hCombo= GetDlgItem (hDlg , DLGGOTOBOOKCOMBO );
		for ( ibook = 1 ; ibook < 67 ; ibook++ )
		{
		    for ( itmp = 0 ; itmp < 3 ; itmp++ ) szTemp[itmp] =
							  books[ibook][itmp];
		    szTemp[3] = '\0';
		    SendMessage ( hCombo, CB_ADDSTRING, 0,
						    (LONG)((LPSTR)szTemp) );
		}
//  p	    }
	    if ( nNumPicks > 0 )
	    {
	       if ( ID == 0 )
	       {
		   I2VER = nPickList[0];
	       }
	       else
	       {
                       if ( OPEN_KJB ( &IUNIT10 , szDatabaseName , OF_READ |
			 OF_REOPEN | OF_SHARE_DENY_WRITE ) ) return ( TRUE );
		       GETWRD ( &I2VER , ipoint.IPOINT + nPickList[0] );
		       _lclose ( IUNIT10 );
	       }
	       for ( ichap = 1 ; chap.IADCHP[ichap] < I2VER ; ichap++ );
	       for ( ibook = 1 ; book.IADBOK[ibook] <= ichap ; ibook++ );
	       iver = I2VER - (int)chap.IADCHP[ichap-1];
	       ichap = ichap - (int)book.IADBOK[ibook-1] + 1;
	       ibook--;
/* p
	       if ( hPenWin )
	       {
		  for(iJCK=0;iJCK<3;iJCK++)szTemp[iJCK]=books[ibook][iJCK];
		  szTemp[3]='\0';
		  SetDlgItemText ( hDlg , DLGGOTOBOOKCOMBO , szTemp );
	       }
	       else
	       {
p */
		  SendMessage ( hCombo, CB_SETCURSEL, (WPARAM)(ibook-1), 0L );
//  p	       }
	       SetDlgItemInt ( hDlg , DLGGOTOCHAPEDIT , ichap , FALSE );
	       SetDlgItemInt ( hDlg , DLGGOTOVEREDIT , iver , FALSE );
	    }
	    else
	    {
/*  p
		if ( hPenWin )
		{
		   SetDlgItemText ( hDlg , DLGGOTOBOOKCOMBO , "JOH" );
		}
		else
		{
p  */
		   MSDwRangeSet ( hVertChapMS, (WORD)1, (WORD)21 );
		   MSWCurrentPosSet ( hVertChapMS, (WORD)1 );
		   MSDwRangeSet ( hVertVerMS, (WORD)1, (WORD)51 );
		   MSWCurrentPosSet ( hVertVerMS, (WORD)1 );
		   SendMessage ( hCombo, CB_SETCURSEL, (WPARAM)42, 0L );
//  p		}
		SetDlgItemInt ( hDlg , DLGGOTOCHAPEDIT , 1 , FALSE );
		SetDlgItemInt ( hDlg , DLGGOTOVEREDIT , 1 , FALSE );
	    }
	    SetFocus(hCombo);
	    bFrom = TRUE;
	    goto SetAllDlgFields;

        case WM_VSCROLL:
            //For vertical scrolling we implement a spin button.

            //Ignore what comes from MSM_WCURRENTPOSSET
	    if (wParam==SB_THUMBTRACK)
	    {
		break;
	    }

	    if ( HIWORD(lParam) == hVertChapMS )
	    {
		iIDEdit = DLGGOTOCHAPEDIT;
	    }
		else
	    {
		iIDEdit = DLGGOTOVEREDIT;
	    }
	    hVertEdit = GetDlgItem (hDlg , iIDEdit );
	    SetFocus(hVertEdit);
	    wPos=LOWORD(lParam);

	    /*
	     * The code between here and the wsprintf case where
	     * we change the edit control's text is entirely to
	     * support the case where the user might have typed a
	     * different value into the edit control.
	     */

	    dwRange=SendMessage(HIWORD(lParam), MSM_DWRANGEGET, 0, 0L);
	    wMax=HIWORD(dwRange);
	    wMin=LOWORD(dwRange);

	    //Get the number in the control.
	    wNum=GetDlgItemInt(hDlg, iIDEdit, &bTrans, TRUE);

	    /*
	     * Check if we got a valid value from the control. Otherwise
	     * use the current position.
	     */
	    if (bTrans && wNum >= 1)
	    {
		/*
		 * If we are decrementing the value and wNum-1==wPos,
		 * then we don't need to modify anything.  Otherwise,
		 * wPos must become wNum-1 if that is >= minimum.
		 */
		if (SB_LINEDOWN==wParam && wNum-1!=wPos)
		{
		    if (wNum > wMin)
		    {
			wPos=wNum-1;
		    }
		    else if (wNum > wMax)
		    {
			wPos = wMax;
		    }
		    else
		    {
			wPos = wMin;
		    }
		}

		if (SB_LINEUP==wParam && wNum+1!=wPos)
		{
		    if (wNum < wMax)
		    {
			wPos=wNum+1;
		    }
		    else if (wNum < wMin)
		    {
			wPos = wMin;
		    }
		    else
		    {
			wPos = wMax;
		    }
		}
	    }


	    //Only change the control if we have to.
	    if (wPos!=wNum)
	    {
		//Convert the value and put it in the control.
		SetDlgItemInt(hDlg, iIDEdit, wPos, FALSE);
	    }

	    //Update the current position if it changed.
	    if (wPos!=(short)LOWORD(lParam))
		SendMessage(HIWORD(lParam), MSM_WCURRENTPOSSET, wPos, 0L);


	    /*
	     * We always want to do this in case the user typed something but we
	     * could not scroll (like they typed in the max), in which case the
	     * selection went away.
	     */
	    SendMessage(hVertEdit, EM_SETSEL, 0, MAKELONG(0, 32767));
	    if ( ( wPos != (short)LOWORD(lParam) ) &&
		 ( iIDEdit == DLGGOTOCHAPEDIT	 ) ) goto LabChangeChap;
	    break;

	case WM_COMMAND:
	    switch (wParam)
	    {

	    case IDOK:
		/*  process book field	*/
LabIDOK:
		if ( !bValidateBookItem ( hDlg , (LPINT)&ibook ) )
		{
		   // error !
		   (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_BADBOOK );
		   return TRUE;
		}

		/*  process chapter field  */
		ichap = GetDlgItemInt (hDlg , DLGGOTOCHAPEDIT , &bTrans ,
								     FALSE );
                if ( !bTrans )
                {
                    // error !
		    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_BADCHAPT );
                    return TRUE;
                }

                if ( ichap == 0 )
                {
                    // error !
		    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CHAPT0 );
                    return TRUE;
                }

		if ( ichap > ( (int)book.IADBOK[ibook+1] -
                               (int)book.IADBOK[ibook] ) )
                {
                    // error !
		    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CHAPT2BIG );
                    return TRUE;
                }

		/*  process verse field  */
		iver = GetDlgItemInt (hDlg , DLGGOTOVEREDIT , &bTrans ,
								     FALSE );
                if ( !bTrans )
                {
                    // error !
		    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_BADVERSE );
                    return TRUE;
                }

                if ( iver == 0 )
                {
                    // error !
		    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_VERSE0 );
                    return TRUE;
                }

		if ( iver >
		      ( (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-1] -
			(int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-2] ) )
                {
                    // error !
		    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_VERSE2BIG );
                    return TRUE;
                }

		nGoToRef = iver +
			   (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-2];
		if ( nGoToRef > 4 * VerseRefBufSize )
		{
		    nTopIRRef = nGoToRef - 3 * VerseRefBufSize;
		}
		else
		{
		    nTopIRRef = nGoToRef + 3 * VerseRefBufSize;
		}
		ID = 0;
		I2NREF = (int)chap.IADCHP[(int)book.IADBOK[67]-1];
		ICAP = FALSE;
		IR = IVSG = IVS = IVE = IVW = 0;
		ucGoToLine = 1;
		nTOS = -3;
		bValidBuffer = FALSE;
		nNumPicks = 0;

		SetScrollRange ( hWnd , SB_VERT , 1 , I2NREF , FALSE );
		SetScrollPos   ( hWnd , SB_VERT , nGoToRef , TRUE );
		InvalidateRect ( hWnd, NULL, TRUE);
		UpdateWindow (hWnd);

		EndDialog(hDlg,NULL);
		return(TRUE);

	    case DLGGOTOBOOKCOMBO:
		switch ( HIWORD(lParam) )
		{
		case (WORD)CBN_ERRSPACE:
		    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_OUTOFCBSPACE );
		    break;

		case CBN_SELCHANGE:
		       bFrom = FALSE;
SetAllDlgFields:
		       dwIndex = SendMessage ( hCombo, CB_GETCURSEL, 0, 0L );
		       if ( dwIndex != CB_ERR ) ibook = (int)dwIndex + 1;
IsValidBook:
		       hDlgItem = GetDlgItem (hDlg , DLGGOTOKEYPAD );
		       EnableWindow ( hDlgItem , TRUE );

		       wsprintf ( szTemp , szFmt1 ,
					     ( (int)book.IADBOK[ibook+1] -
					       (int)book.IADBOK[ibook] ) );
		       SetDlgItemText ( hDlg , DLGGOTOCHAPMAX ,
							    (LPSTR)szTemp );
		       ichap = GetDlgItemInt (hDlg , DLGGOTOCHAPEDIT ,
							  &bTrans , FALSE );
		       MSDwRangeSet ( hVertChapMS, (WORD)1, (WORD)(
						 (int)book.IADBOK[ibook+1] -
						 (int)book.IADBOK[ibook] ) );
		       if ( MSWCurrentPosSet ( hVertChapMS, (WORD)ichap ) == -1 )
				      MSWCurrentPosSet ( hVertChapMS, (WORD)1 );

		       if ( !bTrans || ichap <= 0 ||
				    ( ichap > ( (int)book.IADBOK[ibook+1] -
						(int)book.IADBOK[ibook] ) ) )
		       {
			   SetDlgItemInt ( hDlg , DLGGOTOCHAPEDIT , 1, FALSE);
			   ichap = 1;
		       }

		       // we have a valid chapter! set the max verse field...
		       wsprintf ( szTemp , szFmt1 ,
		       ( (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-1] -
			 (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-2] ) );
		       SetDlgItemText ( hDlg , DLGGOTOVERMAX ,
							    (LPSTR)szTemp );
		       iver = GetDlgItemInt (hDlg , DLGGOTOVEREDIT ,
							   &bTrans , FALSE );
		       MSDwRangeSet ( hVertVerMS, (WORD)1, (WORD)
		       ( (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-1] -
			 (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-2] ) );
		       if ( MSWCurrentPosSet ( hVertVerMS, (WORD)iver ) == -1 )
				    MSWCurrentPosSet ( hVertVerMS, (WORD)1 );

		       if ( !bTrans || iver <= 0 || iver >
		       ( (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-1] -
			 (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-2] ) )
		       {
			   SetDlgItemInt ( hDlg , DLGGOTOVEREDIT , 1, FALSE );
		       }
		    if ( bFrom ) return(TRUE);
		    if ( wParam == DLGGOTOBOOKBTN ) return(TRUE);
		    break;

		case CBN_SETFOCUS:
		    nGotoFocus=DLGGOTOBOOKCOMBO;
		    break;

		default:
		    break;
		}
		break;

	    case DLGGOTOCHAPEDIT:
		switch ( HIWORD(lParam) )
		{
		case EN_CHANGE:
		    // enable keypad
		    hDlgItem = GetDlgItem (hDlg , DLGGOTOKEYPAD );
		    EnableWindow ( hDlgItem , TRUE );

LabChangeChap:

		    dwIndex = SendMessage ( hCombo, CB_GETCURSEL, 0, 0L );
		    if ( dwIndex != CB_ERR ) ibook = (int)dwIndex + 1;
		    ichap = GetDlgItemInt (hDlg , DLGGOTOCHAPEDIT ,
						       &bTrans , FALSE );
		    if ( !bTrans || ichap <= 0 ||
				 ( ichap > ( (int)book.IADBOK[ibook+1] -
					     (int)book.IADBOK[ibook] ) ) )
		    {
			if ( GetDlgItemText (hDlg , DLGGOTOCHAPEDIT ,
						       &AWORD[1], 30 ) != 0 )
			{
			    SetDlgItemInt ( hDlg , DLGGOTOCHAPEDIT , 1,
								     FALSE );
			ichap = 1;
			}
			else
			{
			    SetDlgItemText ( hDlg , DLGGOTOVERMAX ,
							     (LPSTR)"" );
			    MSDwRangeSet ( hVertVerMS, (WORD)1, (WORD)250 );
			    break;
			}
		    }

		    // we have a valid chapter! set the max verse field...
		    wsprintf ( szTemp , szFmt1 ,
		    ( (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-1] -
		      (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-2] ) );
		    SetDlgItemText ( hDlg , DLGGOTOVERMAX ,
							 (LPSTR)szTemp );
		    iver = GetDlgItemInt (hDlg , DLGGOTOVEREDIT ,
							&bTrans , FALSE );
		    MSDwRangeSet ( hVertVerMS, (WORD)1, (WORD)
		    ( (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-1] -
		      (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-2] ) );
		    if ( MSWCurrentPosSet ( hVertVerMS, (WORD)iver ) == -1 )
				   MSWCurrentPosSet ( hVertVerMS, (WORD)1 );

		    if ( !bTrans || iver <= 0 || iver >
		    ( (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-1] -
		      (int)chap.IADCHP[(int)book.IADBOK[ibook]+ichap-2] ) )
		    {
			if ( GetDlgItemText (hDlg , DLGGOTOVEREDIT ,
						       &AWORD[1], 30 ) != 0 )
			{
			SetDlgItemInt ( hDlg , DLGGOTOVEREDIT , 1, FALSE );
			}
			iver = 1;
			break;
		    }
		    break;

		case EN_SETFOCUS:
		    nGotoFocus=DLGGOTOCHAPEDIT;
		    break;

		default:
		    break;
		}
		break;

	    case DLGGOTOVEREDIT:
		switch ( HIWORD(lParam) )
		{
		case EN_SETFOCUS:
		    nGotoFocus=DLGGOTOVEREDIT;
		    break;

		default:
		    break;
		}
		break;

	    case DLGGOTOBOOKBTN:
		/* Bring up the books dialog box */
		lpProc = (DLGPROC)MakeProcInstance ((FARPROC)BooksDlg,
								      hInst);
		ibook = DialogBox (hInst, "DlgBooks", hDlg, lpProc);
		FreeProcInstance ((FARPROC)lpProc);
		if ( ibook == NULL ) return (TRUE);
/*  p
		if ( hPenWin )
		{
		   for(iJCK=0;iJCK<3;iJCK++)szTemp[iJCK]=books[ibook][iJCK];
		   szTemp[3]='\0';
		   SetDlgItemText ( hDlg , DLGGOTOBOOKCOMBO , szTemp );
		}
		else
		{
p */
		   SendMessage ( hCombo, CB_SETCURSEL, (WPARAM)(ibook-1), 0L );
// p		}
		goto IsValidBook;
		break;

	    case DLGGOTOKEYPAD:
		/* Bring up the keypad dialog box */
		lpProc = (DLGPROC)MakeProcInstance ((FARPROC)KeypadDlg,
								      hInst);
		nReturnValue = DialogBox (hInst, "DlgKeypad", hDlg, lpProc);
		FreeProcInstance ((FARPROC)lpProc);
		if ( (BOOL)nReturnValue ) goto LabIDOK;
		return(TRUE);
		break;

	    case IDCANCEL:
		EndDialog(hDlg,NULL);
		return(TRUE);
		break;
	    }
	    break;
    }
    return(FALSE);
}

#pragma  alloc_text( SEG4, bValidateBookItem )
/****************************************************************************
 *									    *
 *  FUNCTION   : bValidateBookItem ( hDlg , ibook )			    *
 *									    *
 *  PURPOSE    : function to check for valid book name			    *
 *									    *
 ****************************************************************************/
BOOL FAR PASCAL bValidateBookItem ( HWND hDlg , LPINT ibook )

{
    int I;

    for ( I = 0 ; I < 5 ; I++ ) AWORD[I] = '\0';
    GetDlgItemText (hDlg , DLGGOTOBOOKCOMBO , &AWORD[0] , 5 );
    AnsiUpperBuff ( (LPSTR)&AWORD[0] , (WORD)5 );

    *ibook = 0;
    for ( *ibook = 1 ; *ibook <= 66 ; (*ibook)++ )
    {
	for ( I = 0 ; I < 3 ; I++ )
	    if ( books[*ibook][I] != AWORD[I] ) goto skipin;
	goto skipout;
skipin: continue;
    }
    return ( FALSE );

skipout:
    return ( TRUE );
}

#pragma  alloc_text( SEG5, BooksDlg )
/****************************************************************************
 *									    *
 *  FUNCTION   : BooksDlg (hDlg, message, wParam, lParam)		    *
 *									    *
 *  PURPOSE    : Dialog function for the books dialog box.		    *
 *									    *
 ****************************************************************************/
BOOL CALLBACK _export BooksDlg(hDlg, message, wParam, lParam)

HWND hDlg;
unsigned message;
WORD wParam;
LONG lParam;

{
int isBook, nButtonsInRow, isButtonWidth, isButtonHeight, nNumberRows;
int isRow, isCol, ijj, cxTotal, cyTotal;
char szBookName[]="   \0";
static COLORREF dwColor = RGB ( 128, 128, 128);
static HBRUSH hBrush;
POINT point;
HDC    hdc;

    switch (message)
    {
	case WM_INITDIALOG:
	    hdc = GetDC ( hDlg );
	    if ( GetDeviceCaps ( hdc , PLANES ) < 4 ) dwColor =
					       GetSysColor ( COLOR_BTNFACE );
	    ReleaseDC ( hDlg , hdc );
	    hBrush = CreateSolidBrush ( dwColor );

	    isButtonWidth = 6 * cxChar;
	    isButtonHeight = 7 * cyChar / 4;
	    nButtonsInRow = min(66, ( cxScreen - 2 * cxDlgFrame - 2 )
							   / isButtonWidth );
	    nNumberRows = 66 / nButtonsInRow + 1;
	    if ( 66 % nButtonsInRow == 0 ) nNumberRows--;
	    cxTotal = nButtonsInRow * isButtonWidth + 2 * cxDlgFrame + 2;
	    cyTotal = nNumberRows * isButtonHeight + 2 * cyDlgFrame +
							       cyCaption + 1;
	    if ( cyTotal > cyScreen )
	    {
		      (void)BWError
		      ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION , 1 ,
							   IDS_SMALLSCREEN );
	    }
	    MoveWindow (hDlg, max( 0, (cxScreen - cxTotal) / 2 ),
	      (cyScreen - cyTotal) < 102 ? 0 : 100, cxTotal, cyTotal, TRUE );
	    for ( isRow = 0 , isBook = 1 ; isRow < nNumberRows ; isRow++ )
	    {
		for ( isCol = 0 ;
		      isCol < nButtonsInRow && isBook < 67;
		      isCol++ , isBook++ )
		{
		   for ( ijj = 0 ; ijj < 3 ; ijj++ )
					  szBookName[ijj]=books[isBook][ijj];
		   CreateWindow ( "button", (LPSTR)&szBookName[0],
				   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |
				   WS_TABSTOP,
				   isButtonWidth * isCol,
				   isButtonHeight * isRow,
				   isButtonWidth, isButtonHeight,
				   hDlg, isBook + 10,
				   hInst, NULL);
		}
	    }
	    return(TRUE);
	    break;

	case WM_COMMAND:
	    if ( wParam == IDCANCEL )
	    {
		EndDialog(hDlg,NULL);
		return(TRUE);
	    }

	    if ( wParam > 10 && wParam < 77 )
	    {
	       nGotoFocus = DLGGOTOCHAPEDIT;
	       EndDialog(hDlg,(int)wParam-10);
	    }
	    else
	    {
	       (void)BWError ( hWnd, MB_APPLMODAL | MB_OK |
				   MB_ICONEXCLAMATION , 1 , IDS_BADBOOKARG );
	    }
	    return(TRUE);
	    break;

	case WM_PAINT:
	    PaintTheDlg ( hDlg );
	    break;

	case WM_DESTROY:
	    DeleteObject ( hBrush );
	    break;

	case WM_CTLCOLOR:
	    if (HIWORD (lParam) == CTLCOLOR_BTN)
	    {
		SetBkColor ( wParam, dwColor );
		UnrealizeObject ( hBrush );
		point.x = point.y = 0;
		ClientToScreen ( hDlg, &point );
		SetBrushOrg ( wParam, point.x, point.y );
		return ((DWORD) hBrush);
	    }
	    break;

	default:
	    break;
    }
    return(FALSE);
}

#pragma  alloc_text( SEG5, PaintTheDlg )
VOID NEAR PaintTheDlg ( HWND hDlg )
{
COLORREF dwColor = RGB ( 128, 128, 128);
HBRUSH hBrush;
HDC    hdc;
PAINTSTRUCT ps;
HPEN hPen;

hdc = BeginPaint ( hDlg , &ps );
if ( GetDeviceCaps ( hdc , PLANES ) < 4 ) dwColor =
					       GetSysColor ( COLOR_BTNFACE );
hBrush = CreateSolidBrush ( dwColor );
hBrush = SelectObject ( hdc, hBrush );
hPen = CreatePen ( PS_SOLID , 0 , dwColor );
hPen = SelectObject ( hdc, hPen );
Rectangle ( hdc, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right,
							 ps.rcPaint.bottom );
DeleteObject ( SelectObject ( hdc, hBrush ) );
DeleteObject ( SelectObject ( hdc, hPen ) );
EndPaint ( hDlg, &ps );
}


#pragma  alloc_text( SEG5, KeypadDlg )
/****************************************************************************
 *									    *
 *  FUNCTION   : KeypadDlg (hDlg, message, wParam, lParam)		    *
 *									    *
 *  PURPOSE    : Dialog function for the Go To dialog box.		    *
 *									    *
 ****************************************************************************/
BOOL CALLBACK _export KeypadDlg(hDlg, message, wParam, lParam)

HWND hDlg;
unsigned message;
WORD wParam;
LONG lParam;

{
HWND hwndParent;
int nNumChar;
char szText[6];
HWND hDlgItem;

    switch (message)
    {
	case WM_INITDIALOG:
	    return(TRUE);

	case WM_COMMAND:
	    if ( wParam == IDCANCEL )
	    {
		EndDialog(hDlg,(int)FALSE);
		return(TRUE);
	    }

	    if ( wParam > DLGKEYPAD9 )
	    {
	       switch (wParam)
	       {
	       case DLGKEYPADBKSP:
		   hwndParent = GetParent (hDlg );
		   if ( nGotoFocus == DLGGOTOBOOKCOMBO )
						nGotoFocus = DLGGOTOCHAPEDIT;
		   nNumChar = (int)SendDlgItemMessage(hwndParent, nGotoFocus,
			     WM_GETTEXT, (WORD)4, (DWORD)(LPSTR)&szText[0] );
		   if ( nNumChar > 0 )
		   {
		      szText[nNumChar-1] = '\0';
		      SendDlgItemMessage(hwndParent, nGotoFocus, WM_SETTEXT,
					    NULL, (DWORD)(LPSTR)&szText[0] );
		      hDlgItem = GetDlgItem (hwndParent , nGotoFocus );
		      SendMessage (hwndParent, WM_COMMAND, nGotoFocus,
					      MAKELONG(hDlgItem,EN_CHANGE) );
		   }
		   break;

	       case DLGKEYPADTAB:
		   switch (nGotoFocus)
		   {
		   case DLGGOTOBOOKCOMBO:
		      nGotoFocus = DLGGOTOCHAPEDIT;
		      break;

		   case DLGGOTOCHAPEDIT:
		      nGotoFocus = DLGGOTOVEREDIT;
		      break;

		   case DLGGOTOVEREDIT:
		      nGotoFocus = DLGGOTOBOOKCOMBO;
		      break;

		   default:
		      nGotoFocus = DLGGOTOCHAPEDIT;
		      break;
		   }
		   break;

	       case DLGKEYPADCANCEL:
		   EndDialog(hDlg,(int)FALSE);
		   break;

	       case DLGKEYPADENTER:
		   EndDialog(hDlg,(int)TRUE);
		   break;

	       default:
		   break;
	       }
	    }
	    else
	    {
	       if ( wParam < DLGKEYPAD0 || nGotoFocus == 0 ) return (TRUE);
	       hwndParent = GetParent (hDlg );
	       if ( nGotoFocus == DLGGOTOBOOKCOMBO )
					       nGotoFocus = DLGGOTOCHAPEDIT;
	       nNumChar = (int)SendDlgItemMessage(hwndParent, nGotoFocus,
			    WM_GETTEXT, (WORD)5, (DWORD)(LPSTR)&szText[0] );
	       if ( nNumChar > 2 ) nNumChar = 2;
	       szText[nNumChar] = (char)( (WORD)'0' + wParam -
							 (WORD)DLGKEYPAD0 );
	       szText[nNumChar+1] = '\0';
	       SendDlgItemMessage(hwndParent, nGotoFocus, WM_SETTEXT,
					   NULL, (DWORD)(LPSTR)&szText[0] );
	       hDlgItem = GetDlgItem (hwndParent , nGotoFocus );
	       SendMessage (hwndParent, WM_COMMAND, nGotoFocus,
					     MAKELONG(hDlgItem,EN_CHANGE) );
	    }
	    return(TRUE);
	    break;
    }
    return(FALSE);
}
/****************************************************************************
 *									    *
 *  FUNCTION   : Bible4wPaint ( hwnd )					    *
 *									    *
 *  PURPOSE    : Handles the repainting of the main app's client area.      *
 *									    *
 ****************************************************************************/
BOOL FAR PASCAL Bible4wPaint (hwnd)
HWND hwnd;
{
    PAINTSTRUCT ps;
    int 	line;
    POINT	pt;
    TEXTMETRIC	tm;
//    HFONT	  hFont;
    int i;

// *********************************************************************************************************
    if ( bCriticalSection1 )
    {
	hdc = BeginPaint (hwnd, (LPPAINTSTRUCT)&ps);
	EndPaint(hwnd, (LPPAINTSTRUCT)&ps);
	return ( FALSE );
    }

    if ( OPEN_KJB ( &IUNIT10 , szDatabaseName , OF_READ | OF_REOPEN
		      | OF_SHARE_DENY_WRITE ) ) return ( TRUE );

    hdc = BeginPaint (hwnd, (LPPAINTSTRUCT)&ps);
    if ( LockRes () ) return ( TRUE );
    lpBuffer = GlobalLock ( hDCBuffer );
//    hFont = CreateFont ( 16 , 4 , 0 , 0 , 400 , 0 , 0 , 0 , ANSI_CHARSET ,
//	      OUT_DEFAULT_PRECIS , CLIP_DEFAULT_PRECIS , DRAFT_QUALITY ,
//	      DEFAULT_PITCH | FF_DECORATIVE , "Miami" );
//    if ( hFont != NULL ) hFont = SelectObject ( hdc , hFont );
    GetTextMetrics ( hdc , &tm );
    cxChar = tm.tmAveCharWidth;
    cxCaps = ( tm.tmPitchAndFamily & 1 ? 3 : 2 ) * pt.x / 2;
    cyChar = tm.tmHeight + tm.tmExternalLeading;
    glocyChar = cyChar;
    GetClientRect (hwnd, (LPRECT)&rc);

    if ( nTOS < 0 || !bValidBuffer ) MakeBufValid ();

   /**************************Re-Paint**********************************/

    line = 0;
    i = nTOS;

    while ( line < rc.bottom )
    {
	TextOut ( hdc , 0 , line ,
		  lpBuffer + ( i * nNumColsInBuffer ) ,
		  (int)BufPoint[i].length );
	if ( BufPoint[i].picked ) BitBlt ( hdc , rc.left , line ,
		       rc.right - rc.left + 1 , cyChar , NULL , NULL , NULL ,
								 DSTINVERT );
	line += glocyChar;
	if ( i == nBOB ) goto Break2;
	i = BufPoint[i].forward;
    }
Break2:
    if ( ( ( LLDist ( nTOB , nTOS ) < (int)( (float)nNumLinesInBuffer *
						       1.0 / 3.5 ) ) &&
	 ( BufPoint[nTOB].refnum != 1 || BufPoint[nTOB].line != 1 ) ) ||
	 ( ( LLDist ( nTOS , nBOB ) < (int)( (float)nNumLinesInBuffer *
						       2.0 / 3.5 ) ) &&
				 ( BufPoint[nBOB].refnum != I2NREF ) ) )
				    {
					bValidBuffer = FALSE;
					nGoToRef = BufPoint[nTOS].refnum;
					ucGoToLine = BufPoint[nTOS].line;
					nTOS = -3;
					MakeBufValid ();
				    }


    _lclose ( IUNIT10 );
    if ( UnLockRes () ) return ( TRUE );
    GlobalUnlock   ( hDCBuffer );
//    if ( hFont != NULL ) DeleteObject ( SelectObject ( hdc , hFont ) );
////	if ( hFont != NULL ) SelectObject ( hdc , hFont );
    EndPaint(hwnd, (LPPAINTSTRUCT)&ps);
    return ( FALSE );
}

void NEAR MakeBufValid ( void )
{
int iIR , i , nNumLines , nTOSRef , nKeep, itIR, nOldTop;
unsigned char nTOSLine;
HCURSOR hCursor;
long int IAD;

	hCursor = SetCursor ( LoadCursor ( NULL , IDC_WAIT ) );
	ShowCursor ( TRUE );

	nOldTop   = nTopIRRef;
	if ( nTOS == -3 )
	{
	    nTopIRRef = nGoToRef -
				(int)( (float)VerseRefBufSize * 1.25 / 3.5 );
	    if ( nTopIRRef < 1 ) goto Type1;
	    if ( ( nTopIRRef + VerseRefBufSize ) > I2NREF ) goto Type2;
	    if ( abs ( nOldTop - nTopIRRef ) < VerseRefBufSize )
	    {
		if ( ( nOldTop - nTopIRRef ) > 0 )
		{
		    for ( iIR = VerseRefBufSize - nOldTop + nTopIRRef - 1 ,
				      itIR = VerseRefBufSize - 1 ; iIR >= 0 ;
							     iIR-- , itIR-- )
		    {
			VerseRefs[itIR] = VerseRefs[iIR];
		    }
		    for ( IR = nTopIRRef , iIR = 0 ; iIR <= itIR ;
							       IR++ , iIR++ )
		    {
			if ( ID == 0 )
			{
			    VerseRefs[iIR].VerseNum = (int)IR;
			}
			else
			{
			    GETWRD ( &VerseRefs[iIR].VerseNum ,
							ipoint.IPOINT + IR );
			}
			VerseRefs[iIR].picked = CheckPickList ( (int)IR );
		    }
		    for ( iIR = 0 ; iIR <= itIR ; iIR++ )
		    {
			I2VER = VerseRefs[iIR].VerseNum;
			IAD = IADSOV + ( (long int)I2VER - 1 ) * 2;
			GETWRD ( &hilo.I2HILO[0] , IAD );
			IAD = IAD + 1;
			GETWRD ( &hilo.I2HILO[1] , IAD );
			IAD = IAD + 1;
			VerseRefs[iIR].VerseStart = hilo.I4HILO;
			GETWRD ( &hilo.I2HILO[0] , IAD );
			IAD = IAD + 1;
			GETWRD ( &hilo.I2HILO[1] , IAD );
			VerseRefs[iIR].VerseEnd = hilo.I4HILO - 1;
		    }
		}
		else
		{
		    for ( itIR = 0 , iIR = ( nTopIRRef - nOldTop ) ;
				    iIR < VerseRefBufSize ; itIR++ , iIR++ )
		    {
			VerseRefs[itIR] = VerseRefs[iIR];
		    }
		    for ( IR = nTopIRRef + itIR , iIR = itIR ;
				       IR <= I2NREF , iIR < VerseRefBufSize ;
							       IR++ , iIR++ )
		    {
			if ( ID == 0 )
			{
			    VerseRefs[iIR].VerseNum = (int)IR;
			}
			else
			{
			    GETWRD ( &VerseRefs[iIR].VerseNum ,
							ipoint.IPOINT + IR );
			}
			VerseRefs[iIR].picked = CheckPickList ( (int)IR );
		    }
		    for ( iIR = itIR ; iIR < VerseRefBufSize ; iIR++ )
		    {
			I2VER = VerseRefs[iIR].VerseNum;
			IAD = IADSOV + ( (long int)I2VER - 1 ) * 2;
			GETWRD ( &hilo.I2HILO[0] , IAD );
			IAD = IAD + 1;
			GETWRD ( &hilo.I2HILO[1] , IAD );
			IAD = IAD + 1;
			VerseRefs[iIR].VerseStart = hilo.I4HILO;
			GETWRD ( &hilo.I2HILO[0] , IAD );
			IAD = IAD + 1;
			GETWRD ( &hilo.I2HILO[1] , IAD );
			VerseRefs[iIR].VerseEnd = hilo.I4HILO - 1;
		    }
		}
	    }
	    else
	    {
		for ( IR = nTopIRRef , iIR = 0 ;
				     IR <= I2NREF && iIR < VerseRefBufSize ;
							      IR++ , iIR++ )
		    {
			if ( ID == 0 )
			{
			    VerseRefs[iIR].VerseNum = (int)IR;
			}
			else
			{
			    GETWRD ( &VerseRefs[iIR].VerseNum ,
							ipoint.IPOINT + IR );
			}
			VerseRefs[iIR].picked = CheckPickList ( (int)IR );
		    }
		for ( iIR = 0 ; iIR < VerseRefBufSize ; iIR++ )
		{
		    I2VER = VerseRefs[iIR].VerseNum;
		    IAD = IADSOV + ( (long int)I2VER - 1 ) * 2;
		    GETWRD ( &hilo.I2HILO[0] , IAD );
		    IAD = IAD + 1;
		    GETWRD ( &hilo.I2HILO[1] , IAD );
		    IAD = IAD + 1;
		    VerseRefs[iIR].VerseStart = hilo.I4HILO;
		    GETWRD ( &hilo.I2HILO[0] , IAD );
		    IAD = IAD + 1;
		    GETWRD ( &hilo.I2HILO[1] , IAD );
		    VerseRefs[iIR].VerseEnd = hilo.I4HILO - 1;
		}
	    }
	}

	if ( nTOS == -2 )
	{
Type2:
	    nTopIRRef = max ( 1 , I2NREF - VerseRefBufSize + 1 );
	    for ( IR = nTopIRRef , iIR = 0 ;
		  IR <= I2NREF && iIR < VerseRefBufSize ;
		  IR++ , iIR++ )
		{
		    if ( ID == 0 )
		    {
			VerseRefs[iIR].VerseNum = (int)IR;
		    }
		    else
		    {
			GETWRD ( &VerseRefs[iIR].VerseNum ,
							ipoint.IPOINT + IR );
		    }
		    VerseRefs[iIR].picked = CheckPickList ( (int)IR );
		}
	    for ( IR = nTopIRRef , iIR = 0 ;
		  IR <= I2NREF && iIR < VerseRefBufSize ;
		  IR++ , iIR++ )
		{
	I2VER = VerseRefs[iIR].VerseNum;
	IAD = IADSOV + ( (long int)I2VER - 1 ) * 2;
	GETWRD ( &hilo.I2HILO[0] , IAD );
	IAD = IAD + 1;
	GETWRD ( &hilo.I2HILO[1] , IAD );
	IAD = IAD + 1;
	VerseRefs[iIR].VerseStart = hilo.I4HILO;
	GETWRD ( &hilo.I2HILO[0] , IAD );
	IAD = IAD + 1;
	GETWRD ( &hilo.I2HILO[1] , IAD );
	VerseRefs[iIR].VerseEnd = hilo.I4HILO - 1;
		}
	}

	if ( nTOS == -1 )
	{
Type1:
	    nTopIRRef = 1;
	    for ( IR = nTopIRRef , iIR = 0 ;
		  IR <= I2NREF && iIR < VerseRefBufSize ;
		  IR++ , iIR++ )
		{
		    if ( ID == 0 )
		    {
			VerseRefs[iIR].VerseNum = (int)IR;
		    }
		    else
		    {
			GETWRD ( &VerseRefs[iIR].VerseNum ,
							ipoint.IPOINT + IR );
		    }
		    VerseRefs[iIR].picked = CheckPickList ( (int)IR );
		}
	    for ( IR = nTopIRRef , iIR = 0 ;
		  IR <= I2NREF && iIR < VerseRefBufSize ;
		  IR++ , iIR++ )
		{
	I2VER = VerseRefs[iIR].VerseNum;
	IAD = IADSOV + ( (long int)I2VER - 1 ) * 2;
	GETWRD ( &hilo.I2HILO[0] , IAD );
	IAD = IAD + 1;
	GETWRD ( &hilo.I2HILO[1] , IAD );
	IAD = IAD + 1;
	VerseRefs[iIR].VerseStart = hilo.I4HILO;
	GETWRD ( &hilo.I2HILO[0] , IAD );
	IAD = IAD + 1;
	GETWRD ( &hilo.I2HILO[1] , IAD );
	VerseRefs[iIR].VerseEnd = hilo.I4HILO - 1;
		}
	}

	if ( !bValidBuffer )
	{
//   hCursor = SetCursor ( LoadCursor ( NULL , IDC_WAIT ) );
//   ShowCursor ( TRUE );
	    IR = max ( 1 , nGoToRef -
			   (int)( (float)nNumLinesInBuffer * 1.25 / 3.5 ) );
	    IVSG = IVS = IVE = 0;
	    IVW = 0;
	    nRefLine = 0;
	    nTOSRef = nGoToRef;
	    nTOSLine = ucGoToLine;
	    LLConnect ( nTOB , nTBOB );
	    i = 0;
	    nNumLines = 0;
	    BufPoint[i].refnum = 32760;
	    BufPoint[i].line   = 255;
	    while ( BufPoint[i].refnum != nTOSRef ||
		    BufPoint[i].line   != nTOSLine )
	    {
		i = BufPoint[i].forward;
		if ( !GetNextLine ( i , (int)IR ) )
		{
		    IR++;
		    nRefLine = 0;
		    GetNextLine ( i , (int)IR );
		}
		nNumLines++;
	    }
	    nTOS = i;
	    nTOB = i;
	    nKeep = min ( (int)( (float)nNumLinesInBuffer * 1.25 / 3.5 ) ,
			  nNumLines );
	    for ( i = 1 ; i < nKeep ; i++ ) nTOB = BufPoint[nTOB].backward;
	    nTBOB = LLBreak ( nTOB );
	    i = nTOS;
//   hCursor = SetCursor ( LoadCursor ( NULL , IDC_WAIT ) );
//   ShowCursor ( TRUE );
//   ShowCursor ( FALSE );
//   SetCursor ( hCursor );
	    while ( i != nTBOB && IR <= I2NREF )
	    {
		i = BufPoint[i].forward;
		if ( !GetNextLine ( i , (int)IR ) )
		{
		    nRefLine = 0;
		    IR++;
		    if ( IR <= I2NREF )
		    {
			GetNextLine ( i , (int)IR );
		    }
		    else
		    {
			nBOB = BufPoint[i].backward;
		    }
		}
	    }
	    if ( i == nTBOB ) nBOB = i;
	    bValidBuffer = TRUE;
	}
	ShowCursor ( FALSE );
	SetCursor ( hCursor );
	return;
}



BOOL NEAR GetNextLine ( int i , int IR )
{
static unsigned char nNextCLoc;
static unsigned int col;
long int IS1 , IO , IOS;
int IC1 , nWordLength , ivr , itmp;
unsigned int is, ie, ich, ibok;
char FAR *lpszNextBufLoc;
static BOOL bFirstExtCall;
static unsigned int LastStart = 0;

    if ( IVW >= IVE && IVE != 0 )
    {
	IVW = 0;
	return FALSE;
    }

    if ( IVW == 0 )
    {
	I2VER = VerseRefs[IR-nTopIRRef].VerseNum;
	isPicked = VerseRefs[IR-nTopIRRef].picked;
	IVSG = IVS = VerseRefs[IR-nTopIRRef].VerseStart;
	IVE = VerseRefs[IR-nTopIRRef].VerseEnd;
    }

    nNextCLoc = 0;
//    col = LastStart;
    col = cxChar;
    bFirstExtCall = TRUE;
    lpszNextBufLoc = lpBuffer + ( i * nNumColsInBuffer );
    for ( IVW = IVS ; IVW <= IVE ; IVW++ )
    {
	if ( IVW == IVSG )
	{
	    GETWRD ( &Word_Byte.Word , IVW );
	    IVW++;
	    ibok = (int)(WORD)Word_Byte.Byte[1];
	    ich  = (int)(WORD)Word_Byte.Byte[0];
	    GETWRD ( &Word_Byte.Word , IVW );
	    IVW++;
	    ivr  = (int)(WORD)Word_Byte.Byte[1];
	    ICAP = (WORD)Word_Byte.Byte[0] == 1 ? FALSE : TRUE;

	    *lpszNextBufLoc = ' ';
	    for ( itmp = 0 ; itmp < 3 ; itmp++ ) *(lpszNextBufLoc+itmp+1) =
							   books[ibok][itmp];
	    nNumChars = wsprintf ( lpszNextBufLoc+4 , " %i:%i " , ich , ivr ) + 4;
	    if ( ( nWordLength = LOWORD( GetTextExtent
			( hdc , lpszNextBufLoc , nNumChars ) ) ) + cxChar > rc.right )
	    {
//		  if ( col == LastStart )
		if ( col == (unsigned int)cxChar )
		{
		    while ( LOWORD( GetTextExtent ( hdc , lpszNextBufLoc , nNumChars ) ) > (WORD)rc.right )
							       nNumChars--;
		    nNextCLoc += nNumChars;
		    lpszNextBufLoc += nNumChars;
		    IVW++;
		    goto BreakOut;
		}
		goto BreakOut;
	    }
	    nNextCLoc += nNumChars;
	    lpszNextBufLoc += nNumChars;
	    col = LastStart = nWordLength + cxChar;
	}
//	  if ( IVW == IVS ) col = LastStart;

	GETWRD ( &I2WRD , IVW );
	IO = 0;
	if ( I2WRD > 7 )
	{
	    *lpszNextBufLoc = ' ';
	    IO++;
	}
	if ( I2WRD < iFirstd )
	{
	   IS1 = *(lpPoWords1 + I2WRD );
	   IWLT = *(lpPoWords1 + I2WRD + 1 ) - IS1;
	   _fstrncpy( lpszNextBufLoc+IO , lpWords1+IS1 , (size_t)IWLT );
	}
	else
	{
	   IS1 = *(lpPoWords2 + I2WRD - iFirstd );
	   IWLT = *(lpPoWords2 + I2WRD - iFirstd + 1 ) - IS1;
	   _fstrncpy( lpszNextBufLoc+IO , lpWords2+IS1 , (size_t)IWLT );
	}
	if ( IWLT <= 0 || IWLT > 127 )
	{
	      (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_BADDATABASE );
	      continue;
	}
	lpszNextBufLoc[IO+IWLT] = '\000' ;
	IOS = IO + IWLT;
	if ( ICAP )
	{
	    *(lpszNextBufLoc+IO)=toupper(*(lpszNextBufLoc+IO));
	    ICAP = FALSE;
	}
	if ( I2WRD < 4 )
	{
	    ICAP = TRUE;
	    *(lpszNextBufLoc+IOS) = ' ';
	    IOS++;
	}
	*(lpszNextBufLoc+IOS) = '\0';
	nNumChars = (int)IOS;

	if ( ( nWordLength = nNumChars * cxChar ) + col > rc.right )
	{
//	      if ( col == LastStart )
	    if ( col == (unsigned int)cxChar )
	    {
		while ( LOWORD( GetTextExtent ( hdc , lpszNextBufLoc , nNumChars ) ) > (WORD)rc.right )
							   nNumChars--;
		nNextCLoc += nNumChars;
		lpszNextBufLoc += nNumChars;
		IVW++;
		goto BreakOut;
	    }
	    if ( bFirstExtCall )
	    {
		col = cxChar + LOWORD( GetTextExtent ( hdc ,
			     lpszNextBufLoc - nNextCLoc , nNextCLoc ) ) ;
		bFirstExtCall = FALSE;
	    }
	    if ( ( nWordLength = LOWORD( GetTextExtent ( hdc ,
			     lpszNextBufLoc , nNumChars ) ) ) + col >
			     (int)rc.right ) goto BreakOut;
	}
	col += nWordLength;
	nNextCLoc += nNumChars;
	lpszNextBufLoc += nNumChars;
    }
BreakOut:
    IVS = IVW;
    *(lpBuffer + ( i * nNumColsInBuffer ) + nNextCLoc) = '\0';
    BufPoint[i].length = nNextCLoc;
    BufPoint[i].refnum = (int)IR;
    nRefLine++;
    BufPoint[i].line = nRefLine;
    BufPoint[i].picked = isPicked;
    return TRUE;
 }

#pragma  alloc_text( SEG6, Bible4WndProc )

/****************************************************************************
 *									    *
 *  FUNCTION   : Bible4WndProc (hWnd, message, wParam, lParam)		    *
 *									    *
 *  PURPOSE    : Window function for the main app. window. Processes all the*
 *		 menu selections and other messages.			    *
 *									    *
 ****************************************************************************/
#define Frame_DefProc   DefWindowProc
LRESULT CALLBACK _export Bible4WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    DLGPROC lpProc;
    int nEstNumLinesOnScreen;
    int nEstNumColsOnScreen;
    int i , yWinScrollInc;
    int nNewPick , j , line;
    HDC hdc;



    switch (message){
	case WM_COMMAND:
	    switch (wParam){
		 case IDM_EXIT:
		   DestroyWindow (hWnd);
		   break;

		 case IDM_HELP_INDEX:
                   if ( !WinHelp(hWnd,szHelpFileName,HELP_INDEX,0L) )
                   {
		       (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_BADHELPFILE );
                   }
		   break;

		 case IDM_HELP_KEYBOARD:
                   if ( !WinHelp(hWnd,szHelpFileName,HELP_KEY,(DWORD)(LPSTR)"keys") )
                   {
		       (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_BADHELPFILE );
                   }
		   break;

		 case  IDM_HELP_COMMANDS:
                   if ( !WinHelp(hWnd,szHelpFileName,HELP_KEY,(DWORD)(LPSTR)"commands") )
                   {
		       (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CHAPT0 );
                   }
		   break;

		 case IDM_HELP_PROCEDURES:
                   if ( !WinHelp(hWnd,szHelpFileName,HELP_KEY,(DWORD)(LPSTR)"procedures") )
                   {
		       (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_BADHELPFILE );
                   }
		   break;

		 case IDM_HELP_HELP:
                   if ( !WinHelp(hWnd,"WINHELP.HLP",HELP_INDEX,0L) )
                   {
		       (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_BADHELPFILE );
                   }
		   break;

		 case IDM_ABOUT:
		   /* Bring up the about dialog box */
		   lpProc = (DLGPROC)MakeProcInstance ((FARPROC)About, hInst);
		   DialogBox (hInst,
			      "AboutBox",
			      hWnd,
			      lpProc);
		   FreeProcInstance ((FARPROC)lpProc);
		   break;

		 case IDM_FIND:
		   /* Bring up the Find.. dialog box */
		   lpProc = (DLGPROC)MakeProcInstance ((FARPROC)FindDlg, hInst);
		   if (hPenWin)
		   {
		      DialogBox (hInst,
				 "PenFindBox",
				 hWnd,
				 lpProc);
		   }
		   else
		   {
		      DialogBox (hInst,
				 "FindBox",
				 hWnd,
				 lpProc);
		   }

		   FreeProcInstance ((FARPROC)lpProc);
		   break;

		 case IDM_GOTO:
		   /* Bring up the Go To.. dialog box */
		   lpProc = (DLGPROC)MakeProcInstance ((FARPROC)GoToDlg, hInst);
		   if (hPenWin)
		   {
		      DialogBox (hInst,
				 "PenGoToBox",
				 hWnd,
				 lpProc);
		   }
		   else
		   {
		      DialogBox (hInst,
				 "GoToBox",
				 hWnd,
				 lpProc);
		   }

		   FreeProcInstance ((FARPROC)lpProc);
		   break;

		 case IDM_COPY:
		   MoveToClipBoard ();
		   break;

		 case IDM_REF_FMT:
		   bShowNumRefs = !bShowNumRefs;
		   if ( bShowNumRefs )
		   {
		      CheckMenuItem ( GetMenu(hWnd), IDM_REF_FMT, MF_CHECKED);
		   }
		   else
		   {
		      CheckMenuItem ( GetMenu(hWnd), IDM_REF_FMT, MF_UNCHECKED);
		   }
		   break;
	    }
	    break;

	case WM_SIZE:
	    if (lParam)
	    {
		/* If window is being sized to a non zero value...
		 */

		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		if ( nTOS != -3 )
		{
		    if ( nTOS >= 0 )
		    {
			nGoToRef = BufPoint[nTOS].refnum;
			ucGoToLine = 1;
			nTOS = -3;
		    }
		    else
		    {
			nGoToRef = 1;
			ucGoToLine = 1;
			nTOS = -1;
		    }
		}
		if ( hDCBuffer != NULL ) GlobalFree ( hDCBuffer );
		nEstNumLinesOnScreen = cyClient / cyChar + 1;
		nEstNumColsOnScreen  = cxClient / cxChar + 1;
		nNumLinesInBuffer = (int)((float)nEstNumLinesOnScreen * 3.51);
		nNumLinesInBuffer = max ( nNumLinesInBuffer , 7 );
		nNumColsInBuffer  = (int)((float)nEstNumColsOnScreen  * 1.51);
		nNumColsInBuffer  = max ( nNumColsInBuffer , 5 );
                if ( ( hDCBuffer = GlobalAlloc ( GMEM_MOVEABLE ,
		     (DWORD)nNumLinesInBuffer * (DWORD)nNumColsInBuffer ) )
						     == NULL ) OutOfMem ();
		if ( nNumLinesInBuffer > VerseRefBufSize )
		{
		    (void)BWError ( hWnd,
//				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    MB_OK | MB_ICONHAND | MB_SYSTEMMODAL
				    , 0 , IDS_CANTRESIZE );
                    nNumLinesInBuffer = VerseRefBufSize;
		}
		for ( i = 0 ; i < nNumLinesInBuffer ; i++ )
		{
		    BufPoint[i].forward  =
			       (unsigned char)( ( i + 1 ) % nNumLinesInBuffer );
		    BufPoint[i].backward =
			       (unsigned char)( ( i - 1 + nNumLinesInBuffer ) %
							  nNumLinesInBuffer );
		}
		nTOB = 0;
		nBOB = nTBOB = nNumLinesInBuffer - 1;
		IR = IVSG = IVS = IVE = IVW = 0;
		bValidBuffer = FALSE;

		InvalidateRect (hWnd, NULL, TRUE);
	    }
	    break;

	case WM_PAINT:
	    Bible4wPaint ( hWnd );
	    break;

	case WM_CREATE:
	    OpenBible ( hWnd );
	    break;

	case WM_DESTROY:
	    if ( hDCBuffer != NULL ) GlobalFree ( hDCBuffer );
	    WinHelp(hWnd,szHelpFileName,HELP_QUIT,0L);
	    if (hPenWin)
	    {
	       /* Unregister this app */
	       if (RegPenApp != NULL)
		       (*RegPenApp)(RPA_DEFAULT, FALSE);

	       /* Close libraries */
	       FreeProcInstance(lpdfCustomDictProc);
	       FreeLibrary(hCustomDictLib);
	       /* Close custom dictionary callback function */
	       FreeProcInstance(lpfnLookUp);
	    }

	    PostQuitMessage (0);
	    break;

	case WM_KEYDOWN:
	    switch ( wParam )
	    {
		case VK_HOME:
		    SendMessage (hWnd, WM_VSCROLL, SB_TOP, 0L);
		    break;

		case VK_END:
		    SendMessage (hWnd, WM_VSCROLL, SB_BOTTOM, 0L);
		    break;

		case VK_PRIOR:
		    SendMessage (hWnd, WM_VSCROLL, SB_PAGEUP, 0L);
		    break;

		case VK_NEXT:
		    SendMessage (hWnd, WM_VSCROLL, SB_PAGEDOWN, 0L);
		    break;

		case VK_UP:
		    SendMessage (hWnd, WM_VSCROLL, SB_LINEUP, 0L);
		    break;

		case VK_DOWN:
		    SendMessage (hWnd, WM_VSCROLL, SB_LINEDOWN, 0L);
		    break;
	    }
	    return 0;

	case WM_VSCROLL:
	    switch ( wParam )
	    {
		case SB_LINEUP:
		    if ( BufPoint[nTOS].refnum == 1 )
		    {
			 (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CANTGOUP );
			 return ( 0 );
		    }
		    yWinScrollInc = cyChar;
		    nTOS = BufPoint[nTOS].backward;
		    break;

		case SB_LINEDOWN:
		    if ( BufPoint[nTOS].refnum == I2NREF )
		    {
			 (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CANTGODOWN );
			 return ( 0 );
		    }
		    yWinScrollInc = -cyChar;
		    nTOS = BufPoint[nTOS].forward;
		    break;

		case SB_PAGEUP:
		    yWinScrollInc = 0;
		    for ( i = 1 ; i < ( cyClient / cyChar ) ; i++ )
		    {
			if ( BufPoint[nTOS].refnum == 1 )
			{
			     (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CANTPAGEUP );
                             goto ScrollBreak;
			}
			nTOS = BufPoint[nTOS].backward;
		    }
		    break;

		case SB_PAGEDOWN:
		    yWinScrollInc = 0;
		    for ( i = 1 ; i < ( cyClient / cyChar ) ; i++ )
		    {
			if ( BufPoint[nTOS].refnum == I2NREF )
			{
			     (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CANTPAGEDOWN );
			     goto ScrollBreak;
			}
			nTOS = BufPoint[nTOS].forward;
		    }
		    break;

		case SB_THUMBPOSITION:
		    yWinScrollInc = 0;
		    nGoToRef = LOWORD(lParam);
		    ucGoToLine = 1;
		    nTOS = -3;
		    break;

		case SB_THUMBTRACK:
		    return 0;
		    break;

		case SB_TOP:
		    yWinScrollInc = 0;
		    nGoToRef = 1;
		    ucGoToLine = 1;
		    nTOS = -1;
		    break;

		case SB_BOTTOM:
		    yWinScrollInc = 0;
		    nGoToRef = I2NREF;
		    ucGoToLine = 1;
		    nTOS = -2;
		    break;

		default:
		    return 0;
		    break;
	    }
ScrollBreak:
	    if ( yWinScrollInc != 0 )
	    {
		ScrollWindow ( hWnd , 0 , yWinScrollInc , NULL , NULL );
	    }
	    else
		InvalidateRect ( hWnd , NULL , TRUE );
	    if ( nTOS < 0 )
	    {
		SetScrollPos ( hWnd , SB_VERT , nGoToRef , TRUE );
		bValidBuffer = FALSE;
	    }
	    else
		SetScrollPos ( hWnd , SB_VERT , BufPoint[nTOS].refnum
								    , TRUE );
	    UpdateWindow ( hWnd );
	    return 0;
	    break;

	case WM_LBUTTONDOWN:
	    hdc = GetDC ( hWnd );
	    GetClientRect (hWnd, (LPRECT)&rc);
	    for ( i = 0 , nNewPick = nTOS ;
				 i < ( (int)HIWORD(lParam) / cyChar ) ; i++ )
	    {
		if ( nNewPick == nBOB ) break;
		nNewPick = BufPoint[nNewPick].forward;
	    }
	    for ( j = nTOS , line = 0 ; line <= (int)HIWORD(lParam) ;
							       line+=cyChar )
	    {
		if ( BufPoint[j].refnum == BufPoint[nNewPick].refnum )
		{
		    BitBlt ( hdc , rc.left , line ,
		    rc.right - rc.left + 1 , cyChar , NULL , NULL , NULL ,
								 DSTINVERT );
		}
		if ( j == nBOB ) break;
		j = BufPoint[j].forward;
	    }
	    ReleaseDC ( hWnd , hdc );
	    if ( nNumPicks > 1 )
	    {
		if ( wParam & MK_CONTROL )
		{
		    for ( j = 0 ; j < nNumPicks ; j++ )
		    {
			if ( nPickList[j] == BufPoint[nNewPick].refnum )
			{
			    for ( i = j ; i < nNumPicks ; i++ )
			    {
				nPickList[i] = nPickList[i+1];
			    }
			    nNumPicks--;
			    nNewPick = -1;
			    break;
			}
		    }
		    if ( nNewPick != -1 )
		    {
			nPickList[nNumPicks] = BufPoint[nNewPick].refnum;
			if ( nNumPicks == PICKLISTSIZE - 1 )
			{
			    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_PLISTFULL );
			    return 0;
			}
			nNumPicks++;
		    }
		}
		else
		{
		    nPickList[0] = BufPoint[nNewPick].refnum;
		    nNumPicks = 1;
		}
	    }
	    else if ( nNumPicks == 1 )
	    {
		if ( nPickList[0] == BufPoint[nNewPick].refnum )
		{
		    nNumPicks = 0;
		}
		else
		{
		    if ( wParam & MK_CONTROL )
		    {
			nPickList[1] = BufPoint[nNewPick].refnum;
			nNumPicks = 2;
		    }
		    else
		    {
			nPickList[0] = BufPoint[nNewPick].refnum;
		    }
		}
	    }
	    else
	    {
		nPickList[0] = BufPoint[nNewPick].refnum;
		nNumPicks = 1;
	    }
	    i = nTOB;
	    while ( TRUE )
	    {
		BufPoint[i].picked = CheckPickList ( BufPoint[i].refnum );
		if ( i == nBOB ) break;
		i = BufPoint[i].forward;
	    }
	    InvalidateRect ( hWnd , NULL , TRUE );
	    return 0;
	    break;

	case WM_LBUTTONUP:
	    return 0;
	    break;

	default:
	    return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return(NULL);
}

BOOL FAR OpenBible ( hWndpar )
HWND hWndpar;
{
long int LOCTOC,LOCWL,I;
char szDbVer[]="BIB3P0";

	NHASH = 0;
	I2ZERO = 0;
//	  LASTVR = 0;		  what was this used for ????
	LASTCH = 0;
	LASTAD = 10;
	ITVERS = 0;
	IRMOD = 0;
	IRECIN = -1;
	ID = 0;

	LASTWD = 0;
	LASTSB = 1;

	if ( OPEN_CLIP ( &IUNIT11 , "c9l9i9p9.scr" , OF_READWRITE | OF_CREATE
				    | OF_SHARE_DENY_NONE ) ) return ( TRUE );
	_lclose ( IUNIT11 );

	if ( GetProfileString("Bible4W", "Database3p0", "KJB3p0.dat",
                            szDatabaseName, sizeof(szDatabaseName) ) == 0 )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
                                    , 1 , IDS_BADDBN );
        }
        if ( OPEN_KJB ( &IUNIT10 , szDatabaseName , OF_EXIST )
							   ) return ( TRUE );

        if ( OPEN_KJB ( &IUNIT10 , szDatabaseName , OF_READ
				   | OF_SHARE_DENY_WRITE ) ) return ( TRUE );

	LASTAD = 1;
	CHGWRD ( AWORD , 6 , LASTAD );
	AWORD[6]='\000';
	dprintf ( " VERSION = %s\n" , AWORD );
	if ( strcmp ( AWORD , szDbVer ) != 0 )
	{
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_BADDB2 );
	    return ( TRUE );
	}
	LASTAD = 4;
	I4GWRD ( &LOCTOC , LASTAD );
	LASTAD = 6;
	I4GWRD ( &LOCWL , LASTAD );
	LASTAD = 8;
	I4GWRD ( &IADOFF , LASTAD );
	LASTAD = 10;
	I4GWRD ( &IADSOV , LASTAD );

	GETOC ( (long int)LOCTOC );
	GETWL ( (long int)LOCWL );

	_lclose ( IUNIT10 );

	nGoToRef = 1 + (int)chap.IADCHP[(int)book.IADBOK[43]-1];

	ID = 0;
	I2NREF = (int)chap.IADCHP[(int)book.IADBOK[67]-1];
	ICAP = FALSE;
	IR = IVSG = IVS = IVE = IVW = 0;
	ucGoToLine = 1;
	nTOS = -3;
	bValidBuffer = FALSE;

	SetScrollRange ( hWndpar , SB_VERT , 1 , I2NREF , FALSE );
	SetScrollPos   ( hWndpar , SB_VERT , nGoToRef , TRUE );

	return ( FALSE );

}

void NEAR GETWL ( long int IAD )
{
long int I,LSTWDF,MADD,IS1,IW,IS1A,ID1,IS2;
char temptext[40];

	if ( ( hPoWords1 = LoadResource ( hInst , FindResource ( hInst ,
			   "wordsp1" , "WORDSP1" ) ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_BADDB2 );
        }
	if ( ( lpPoWords1 = ( int FAR * )LockResource ( hPoWords1 ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
        }
	UnlockResource ( hPoWords1 );
	if ( ( hPoWords2 = LoadResource ( hInst , FindResource ( hInst ,
			   "wordsp2" , "WORDSP2" ) ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_BADDB2 );
        }
	if ( ( lpPoWords2 = ( int FAR * )LockResource ( hPoWords2 ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
        }
	UnlockResource ( hPoWords2 );
	if ( ( hWords1 = LoadResource ( hInst , FindResource ( hInst ,
					"words1" , "WORDS1" ) ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_BADDB2 );
        }
	if ( ( lpWords1 = ( char FAR * )LockResource ( hWords1 ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
        }
	UnlockResource ( hWords1 );
	if ( ( hWords2 = LoadResource ( hInst , FindResource ( hInst ,
					"words2" , "WORDS2" ) ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_BADDB2 );
        }
	if ( ( lpWords2 = ( char FAR * )LockResource ( hWords2 ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
        }
	UnlockResource ( hWords2 );
	if ( ( hListSizes = LoadResource ( hInst , FindResource ( hInst ,
				    "listsizes" , "LISTSIZES" ) ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_BADDB2 );
        }
	if ( ( lpListSizes = ( char FAR * )LockResource ( hListSizes ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
	}
	iFirstd = (long int)*(int FAR *)lpListSizes;
	szFirstChar[0] = *((LPSTR)lpListSizes + sizeof(int) );
	iSizeWord1 = *((LPWORD)((LPSTR)lpListSizes + sizeof(int) + 2));
	iSizeWord2 = *((LPWORD)((LPSTR)lpListSizes + sizeof(int) + 2 +
				  sizeof(iSizeWord1)));
	iSizeWordp1 = *((LPWORD)((LPSTR)lpListSizes + sizeof(int) + 2 +
				  sizeof(iSizeWord1) + sizeof(iSizeWord2)));
	iSizeWordp2 = *((LPWORD)((LPSTR)lpListSizes + sizeof(int) + 2 +
				  sizeof(iSizeWord1) + sizeof(iSizeWord2) +
				  sizeof(iSizeWordp1) ));
	UnlockResource ( hListSizes );
 //	LASTAD = IAD1 + LASTWD / 2 + ( LASTWD % 2 ) + 1;
#ifdef DEBUG
/*
	MADD = 0;
	hpIWS = ( long int huge * )LockResource ( hIWS );
	for ( I = 1 ; I <= MAXW ; I++ )
	{
	    if ( IWL[I] != 0 )
	    {
		IS1 = *(hpIWS+I);
		if ( *(hpIWS+I) > MADD ) IW = I;
		MADD = max ( MADD , IS1 + IWL[I] - 1 );
	    }
	}
	    IS1 = *(hpIWS+IW);
	    UnlockResource ( hIWS );
	    IS1A = ( IS1 % NLENW );
	    ID1 = IS1 / NLENW + 1;
	    if ( IS1A == 0 )
	    {
		ID1 = ID1 - 1;
		IS1A = NLENW;
	    }
	    IS2 = IS1A + IWL[IW] - 1;
	    hpWORDS = ( char huge * )LockResource ( hWORDS );
	    for ( I = 0 ; (unsigned char)I < IWL[IW] ; I++ )
					     temptext[I] = *(hpWORDS+IS1+I);
	    UnlockResource ( hWORDS );
*/
#endif

	return;
}

#pragma  alloc_text( SEG7, fLookUp )
BOOL FAR PASCAL fLookUp ( LPSTR szLookUpWord , int iWordLength )
{
    LPSTR szTemp;
    int iIndex,ibook,iJCK,iJCK2;
    long int I;
    char szBook[8];

    if ( iWordLength == 0 ) return ( FALSE );

    szTemp = szLookUpWord;

    if ( bBookDict )
    {
	for ( iJCK2 = 0 ; iJCK2 < 7 , *szTemp ; iJCK2++ , szTemp++ )
	{
	    szBook[iJCK2] = *szTemp;
	}
	szBook[iJCK2] = '\0';
	iIndex = AnsiUpperBuff ( (LPSTR)szBook , (WORD)iJCK2 );
/* According to the documentation, AnsiUpperBuff should return the number
   of characters that converted... When we put in 3 characters, it is
   returning the value 32!  Therefore, we will use iJCK2 until Windows
   is fixed.  Note that this may be a problem when we go to double
   Byte characters.
*/
 //	  if ( iIndex != 3 ) return ( FALSE );
	if ( iJCK2 != 3 ) return ( FALSE );
	for ( ibook = 1 ; ibook <= 66 ; ibook++ )
	{
 //	      for ( iJCK = 0 ; iJCK < iIndex ; iJCK++ )
	    for ( iJCK = 0 ; iJCK < iJCK2 ; iJCK++ )
	    {
	    if ( books[ibook][iJCK] != szBook[iJCK] ) goto Lnextbook;
	    }
	    return ( TRUE );

Lnextbook: continue;
	}
	return ( FALSE );
    }
    else
    {
       LAWORD = (long int)iWordLength;
       for ( I = 1 ; I <= LAWORD ; I++ , szTemp++ )
       {
	   AWORD[I] = *szTemp;
       }

       FNDWRD ( &iIndex );

       if ( iIndex == 0 ) return ( FALSE );
	   else return ( TRUE );
    }
}

void FAR FNDWRD ( int FAR *I2HASH )
{
int FAR * lpTmp;
int NEAR * pTmp;

   *I2HASH = 0;
   IWLT = LAWORD;
   if ( LockRes () ) return;
   if ( tolower(AWORD[1]) < szFirstChar[0] )
   {
      if ( ( lpTmp = jkbsearch (
			       (void FAR*)NULL,
			       (int FAR*)lpPoWords1,
			       (size_t)(iSizeWordp1/sizeof(int)),
			       (size_t)sizeof(int),
			       fCompareWords1
			     )
	    ) == NULL
	  )
      {
	 UnLockRes ();
	 return;
      }
      *I2HASH = (int)(lpTmp - lpPoWords1 ) + 1L;
   }
   else
   {
      if ( ( lpTmp = jkbsearch (
			       (void FAR*)NULL,
			       (int FAR*)lpPoWords2,
			       (size_t)(iSizeWordp2/sizeof(int)),
			       (size_t)sizeof(int),
			       fCompareWords2
			     )
	    ) == NULL
	  )
      {
	 UnLockRes ();
	 return;
      }
      *I2HASH = (int)(lpTmp - lpPoWords2 ) + 1L + iFirstd;
   }
   UnLockRes ();
   return;
}

int FAR * jkbsearch(const void FAR * dumarg, int FAR * lpSearchArray,
	size_t nArraySize, size_t nElementSize, int fCompare(
	const void FAR *, const void FAR * ) )
{
int is=0;
int ie , Guess;
   ie = nArraySize;
   bCaseSensitive = FALSE;
   while ( ie > is + 1 )
   {
      Guess = ( ie + is ) >> 1 ;
      if ( fCompare ( (const void FAR *)NULL, lpSearchArray + Guess ) < 0 )
      {
	 ie = Guess;
      }
      else
      {
	 is = Guess;
      }
   }
   bCaseSensitive = TRUE;
   if ( fCompare ( (const void FAR *)NULL, lpSearchArray + is ) == 0 )
					      return ( lpSearchArray + is );
   if ( fCompare ( (const void FAR *)NULL, lpSearchArray + ie ) == 0 )
					      return ( lpSearchArray + ie );
   if ( fCompare ( (const void FAR *)NULL, lpSearchArray + is - 1 ) == 0 )
					  return ( lpSearchArray + is - 1 );
   if ( fCompare ( (const void FAR *)NULL, lpSearchArray + ie + 1 ) == 0 )
					  return ( lpSearchArray + ie + 1 );
   return ((void FAR *) NULL);
}

/* Compares and returns greater than (1), less than (-1), or equal to (0).
 * This function is called by bsearch. elem1 is the
 * key to be found, and elem2 is the the current table entry.
 */

int fCompareWords1( unsigned FAR *elem1, unsigned FAR *elem2 )
{
    int iLength , i;
    long int IS2 , IS3;
    char char1 , char2;

    IS2 = *elem2;
    IS3 = *( elem2 + 1 );
    iLength = min( IWLT , IS3 - IS2 );

    if ( bCaseSensitive )
    {
       char1 = AWORD[1];
       char2 = *( lpWords1 + IS2 );
    }
    else
    {
       char1 = tolower ( AWORD[1] );
       char2 = tolower ( *( lpWords1 + IS2 ) );
    }

    if ( char1 > char2 )
	return 1;
    else if ( char1 < char2 )
	return -1;
    else
    {
	if ( iLength > 1 )
	{
	   for ( i = 1 ; i < iLength ; i++ )
	   {
	      if( AWORD[i+1] > *(lpWords1+IS2+i) )
		  return 1;
	      else if( AWORD[i+1] < *(lpWords1+IS2+i) )
		  return -1;
	      else
		  continue;
	   }

	   if( IWLT > ( IS3 - IS2 ) )
	       return 1;
	   else if( IWLT < ( IS3 - IS2 ) )
	       return -1;
	}
	return 0;
    }
}

int fCompareWords2( unsigned FAR *elem1, unsigned FAR *elem2 )
{
    int iLength , i;
    long int IS2 , IS3;
    char char1 , char2;

    IS2 = *elem2;
    IS3 = *( elem2 + 1 );
    iLength = min( IWLT , IS3 - IS2 );

    if ( bCaseSensitive )
    {
       char1 = AWORD[1];
       char2 = *( lpWords2 + IS2 );
    }
    else
    {
       char1 = tolower ( AWORD[1] );
       char2 = tolower ( *( lpWords2 + IS2 ) );
    }

    if ( char1 > char2 )
	return 1;
    else if ( char1 < char2 )
	return -1;
    else
    {
	if ( iLength > 1 )
	{
	   for ( i = 1 ; i < iLength ; i++ )
	   {
	      if( AWORD[i+1] > *(lpWords2+IS2+i) )
		  return 1;
	      else if( AWORD[i+1] < *(lpWords2+IS2+i) )
		  return -1;
	      else
		  continue;
	   }

	   if( IWLT > ( IS3 - IS2 ) )
	       return 1;
	   else if( IWLT < ( IS3 - IS2 ) )
	       return -1;
	}
	return 0;
    }
}



void NEAR LLConnect ( int nT , int nB )
{
    BufPoint[nB].forward  = (unsigned char)nT;
    BufPoint[nT].backward = (unsigned char)nB;
    return;
}

int  NEAR LLBreak   ( int nT )
{
    int Temp;
    Temp = BufPoint[nT].backward;
    BufPoint[nT].backward   = -1;
    BufPoint[Temp].forward  = -1;
    return Temp;
}

int  NEAR LLDist    ( int nT , int nS )
{
    int Temp;
    unsigned char i;
    if ( nT == nS ) return 0;
    Temp = 1;
    i = (unsigned char)nT;
    while ( BufPoint[i].forward != (unsigned char)nS )
    {
	Temp++;
	i = BufPoint[i].forward;
    }
    return Temp;
}


void NEAR GETOC ( long int LOCTC )
{
    long int IAD,I;

    IAD = LOCTC -1;
    for ( I = 2 ; I < 2402 ; I++ )
    {
	IAD++;
	GETWRD ( &chap.I2AC[I] , IAD );
    }

    for ( I = 2 ; I < 136 ; I++ )
    {
	IAD++;
	GETWRD ( &book.I2BK[I] , IAD );
    }
    for ( I = 1 ; I <= 67 ; I++ )
    {
	unBook2Chap[I] = (unsigned int)chap.IADCHP[book.IADBOK[I]-1];
    }
    unBook2Chap[0] = (unsigned int)1;
    return;
}

#pragma  alloc_text( SEG8, MoveToClipBoard )
BOOL FAR MoveToClipBoard ( void )
{
    int i , nSizeOfClip , ich , ibok , ivr , itmp;
    long int IAD , IS1 , IS2 , IO , IOS , IC1;
    char szWord[33];
    GLOBALHANDLE hClipMemory;
    char FAR *lpClipMemory;

    if ( nNumPicks == 0 )
    {
	(void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_PLISTEMPTY );
	return ( FALSE );
    }
    nSizeOfClip = 0;

    if ( OPEN_KJB ( &IUNIT10 , szDatabaseName , OF_READ | OF_REOPEN
				 | OF_SHARE_DENY_WRITE ) ) return ( TRUE );
    if ( OPEN_CLIP ( &IUNIT11 , "c9l9i9p9.scr" , OF_READWRITE | OF_CREATE
		       | OF_REOPEN | OF_SHARE_DENY_NONE ) ) return ( TRUE );
    if ( LockRes () ) return ( TRUE );
    lpBuffer = GlobalLock ( hDCBuffer );

    for ( i = 0 ; i < nNumPicks ; i++ )
    {
	if ( ID == 0 )
	{
	    I2VER = nPickList[i];
	}
	else
	{
		GETWRD ( &I2VER , ipoint.IPOINT + nPickList[i] );
	}
	IAD = IADSOV + ( (long int)I2VER - 1 ) * 2;
	GETWRD ( &hilo.I2HILO[0] , IAD );
	IAD = IAD + 1;
	GETWRD ( &hilo.I2HILO[1] , IAD );
	IAD = IAD + 1;
	IVS = hilo.I4HILO;
	GETWRD ( &hilo.I2HILO[0] , IAD );
	IAD = IAD + 1;
	GETWRD ( &hilo.I2HILO[1] , IAD );
	IVE = hilo.I4HILO - 1;

	for ( IVW = IVS ; IVW <= IVE ; IVW++ )
	{
	    if ( IVW == IVS )
	    {
	       GETWRD ( &Word_Byte.Word , IVW );
	       IVW++;
	       ibok = (int)(WORD)Word_Byte.Byte[1];
	       ich  = (int)(WORD)Word_Byte.Byte[0];
	       GETWRD ( &Word_Byte.Word , IVW );
	       IVW++;
	       ivr  = (int)(WORD)Word_Byte.Byte[1];
	       ICAP = (WORD)Word_Byte.Byte[0] == 1 ? FALSE : TRUE;

	       szWord[0] = ' ';
	       for ( itmp = 0 ; itmp < 3 ; itmp++ ) szWord[itmp+1] =
							  books[ibok][itmp];
	       nNumChars = wsprintf ( &szWord[4] , " %i:%i " , ich ,
								  ivr ) + 4;
	       if ( _lwrite ( IUNIT11 , (LPSTR)szWord , nNumChars ) == -1 )
								 wexit ( 91 );
	       nSizeOfClip += nNumChars;
	    }
	    GETWRD ( &I2WRD , IVW );
	    IO = 0;
	    if ( I2WRD > 7 )
	    {
		szWord[0] = ' ';
		IO++;
	    }
	    if ( I2WRD < iFirstd )
	    {
		IS1 = *(lpPoWords1 + I2WRD );
		IS2 = *(lpPoWords1 + I2WRD + 1 );
		IWLT = IS2 - IS1;
		_fstrncpy( szWord+IO , lpWords1+IS1 , (size_t)IWLT );
	    }
	    else
	    {
		IS1 = *(lpPoWords2 + I2WRD - iFirstd );
		IS2 = *(lpPoWords2 + I2WRD - iFirstd + 1 );
		IWLT = IS2 - IS1;
		_fstrncpy( szWord+IO , lpWords2+IS1 , (size_t)IWLT );
	    }
	    szWord[IO+IWLT] = '\000' ;
	    IOS = IO + IWLT;
	    if ( ICAP )
	    {
		*(szWord+IO)=toupper(*(szWord+IO));
		ICAP = FALSE;
	    }
	    if ( IWLT <= 0 || IWLT > 127 )
	    {
		  (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_BADDATABASE );
		  continue;
	    }
//	    _fstrncpy ( &szWord[IO] , hpWORDS+IS1 , IWL[I2WRD] );
	    if ( I2WRD < 4 )
	    {
		ICAP = TRUE;
		szWord[IOS] = ' ';
		IOS++;
	    }
	    szWord[IOS] = '\0';
	    nNumChars = (int)IOS;

	    if ( _lwrite ( IUNIT11 , (LPSTR)szWord , nNumChars ) == -1 )
								 wexit ( 91 );
	    nSizeOfClip += nNumChars;
	}
	nNumChars = wsprintf ( (LPSTR)szWord , "\r\n" );
	if ( _lwrite ( IUNIT11 , (LPSTR)szWord , nNumChars ) == -1 )
								 wexit ( 91 );
	nSizeOfClip += nNumChars;
    }

    UnLockRes ();
    szWord[0] = '\0';
    if ( _lwrite ( IUNIT11 , (LPSTR)szWord , 1 ) == -1 ) wexit ( 91 );
    nSizeOfClip++;
    _lclose ( IUNIT10 );
    GlobalUnlock   ( hDCBuffer );

    _llseek ( IUNIT11 , 0 , 0 );
    if ( ( hClipMemory = GlobalAlloc ( GHND , (DWORD) nSizeOfClip + 1L ) ) == NULL ) OutOfMem ();
    if ( ( lpClipMemory = GlobalLock ( hClipMemory ) ) == NULL ) OutOfMem ();
    if ( _lread ( IUNIT11 , lpClipMemory , nSizeOfClip ) <= 0 ) wexit ( 79 );
    GlobalUnlock ( hClipMemory );
    OpenClipboard ( hWnd );
    EmptyClipboard ();
    SetClipboardData ( CF_TEXT , hClipMemory );
    CloseClipboard ();
    _lclose ( IUNIT11 );

    return ( FALSE );

}

BOOL FAR CheckPickList ( int Vnum )
{
    int i;

    if ( nNumPicks == 0 ) return FALSE;
    for ( i = 0 ; i < nNumPicks ; i++ ) if ( nPickList[i] == Vnum )
								 return TRUE;
    return FALSE;
}

#pragma  alloc_text( SEG1, MakeHelpPathName )
/****************************************************************************

   FUNCTION:   MakeHelpPathName

   PURPOSE:    Bible4w assumes that the .HLP help file is in the same
	       directory as the Bible4w executable.This function derives
               the full path name of the help file from the path of the
               executable.

****************************************************************************/

void FAR MakeHelpPathName(szFileName)
char * szFileName;
{
   char *  pcFileName;
   int     nFileNameLen;

   nFileNameLen = GetModuleFileName(hInst,szFileName,EXE_NAME_MAX_SIZE);
   pcFileName = szFileName + nFileNameLen;

   while (pcFileName > szFileName) {
       if (*pcFileName == '\\' || *pcFileName == ':') {
           *(++pcFileName) = '\0';
           break;
       }
   nFileNameLen--;
   pcFileName--;
   }

   if ((nFileNameLen+13) < EXE_NAME_MAX_SIZE) {
       lstrcat(szFileName, "bible4w.hlp");
   }

   else {
       lstrcat(szFileName, "?");
   }

   return;
}

void FAR OutOfMem ( void )
{
    int msg;

    MessageBeep ( MB_ICONHAND );
    msg = MessageBox ( hWnd , "Out of Memory - close some windows and try again",
		    "Bible4W Error", MB_OK | MB_ICONHAND | MB_SYSTEMMODAL );

#if defined ( DEBUG )
    if ( msg == 0 )
    {
	dprintf ( "Out of Memory\n" );
	FatalExit ( -1 );
    }
#else
    DestroyWindow (hWnd);
#endif

    return;
}

/****************************************************************************
 *									    *
 *  FUNCTION   : BWError ( hwnd, flags, quit, id, ...)			    *
 *		 hwnd = parent Window handle				    *
 *		 flags = MB_ flags sent to the message box routine	    *
 *		 quit = post quit message flag ( ==1 => post quit)	    *
 *		 id = string id number					    *
 *		 (additional parameters passed on to wsprintf function)     *
 *									    *
 *  PURPOSE    : Flashes a Message Box to the user. The format string is    *
 *		 taken from the STRINGTABLE.				    *
 *									    *
 *  RETURNS    : Returns value returned by MessageBox() to the caller.	    *
 *									    *
 ****************************************************************************/
short FAR BWError(HWND hwnd, WORD bFlags, WORD quit, WORD id, ...)
{
    int msg;
    char sz[250];
    char szFmt[250];
    static char szMBstring[]="Bible4W Error";

    switch ( quit )
    {
	case 0:
	default:
	   MessageBeep(MB_ICONEXCLAMATION);
	   break;

	case 1:
	   MessageBeep ( MB_ICONHAND );
	   break;
    }
    if ( LoadString (hInst, id, szFmt, sizeof (szFmt)) == 0 )
    {
	wvsprintf (sz, "Cannot load string resource %u !", (LPSTR)(&id) );
	msg = MessageBox (hWnd, sz, szMBstring,
				      MB_OK | MB_ICONHAND | MB_SYSTEMMODAL );

#if defined ( DEBUG )
	if ( msg == 0 )
	{
	    dprintf ( "Cannot load string %u\n" , id );
	    FatalExit ( -1 );
	}
#endif
	DestroyWindow (hWnd);
	return 0;
    }

    wvsprintf (sz, szFmt, (LPSTR)(&id + 1));
#if defined ( DEBUG )
    dprintf ( "%s\n" , sz );
#endif
	if ( !(msg = MessageBox (hWnd, (LPCSTR)sz, (LPCSTR)szMBstring, bFlags) ) )
      {
	msg = MessageBox ( hWnd , "Out of Memory (2) - close some windows and try again",
		    szMBstring, MB_OK | MB_ICONHAND | MB_SYSTEMMODAL );

#if defined ( DEBUG )
	if ( msg == 0 )
	{
	    dprintf ( "Out of Memory\n" );
	    FatalExit ( -1 );
	}
#endif
	DestroyWindow (hWnd);
	return 0;
      }
    if ( quit == 1 ) DestroyWindow (hWnd);
    return msg;
}

VOID FAR wexit(int status)
{
    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
	  , 1 , IDS_ABORT, status );
    return;
}

#pragma  alloc_text( SEG1, Bible4wInit )
/****************************************************************************
 *									    *
 *  FUNCTION   : Bible4wInit (hInstance,hPrevInstance)			    *
 *									    *
 *  PURPOSE    : Registers the main window class.			    *
 *									    *
 *  RETURNS    : TRUE	-  if RegisterClass() went off ok		    *
 *		 FALSE	-  otherwise.					    *
 *									    *
 ****************************************************************************/
BOOL FAR PASCAL Bible4wInit (hInstance,hPrevInstance)

HINSTANCE hInstance;
HINSTANCE hPrevInstance;

{
    HANDLE    hMemory;
    PWNDCLASS pWndClass;
    DWORD TempFlags, TotFreeMem;
    DWORD dwMinFree=400000;
    char lpszTemp[30];
    HANDLE hMemTemp; BOOL bTemp;
    WORD nWindowsVersion;
    int iKanjiWinHeight, iDBCSEnabled;

    DebugFlag = GetProfileInt("Bible4W", "debug", 0 );


#if defined ( DEBUG )
	    dprintf ( "In Bible4wInit\n" );
#endif

    TempFlags = GetWinFlags ();
    nWindowsVersion = GetVersion();
    iDBCSEnabled    = GetSystemMetrics ( SM_DBCSENABLED );
    iKanjiWinHeight = GetSystemMetrics ( SM_CYKANJIWINDOW );
    cxScreen =	      GetSystemMetrics ( SM_CXSCREEN );
    cyScreen =	      GetSystemMetrics ( SM_CYSCREEN );
    cxDlgFrame =      GetSystemMetrics ( SM_CXDLGFRAME );
    cyDlgFrame =      GetSystemMetrics ( SM_CYDLGFRAME );
    cyCaption =       GetSystemMetrics ( SM_CYCAPTION );

#if defined ( DEBUG )
	    dprintf ( "TempFlags = %li, Windows Version = %i , %i\n",
		       TempFlags,
		       (int)LOBYTE(nWindowsVersion),
		       (int)HIBYTE(nWindowsVersion) );
	    dprintf ( "Kanji Window Height = %i\n", iKanjiWinHeight );
	    dprintf ( "DBCS Enabled = %i\n", iDBCSEnabled );
	    if ( TempFlags & WF_CPU086 )
	       dprintf ( "8086 cpu, " );
	    if ( TempFlags & WF_CPU186 )
	       dprintf ( "80186 cpu, " );
	    if ( TempFlags & WF_CPU286 )
	       dprintf ( "80286 cpu, " );
	    if ( TempFlags & WF_CPU386 )
	       dprintf ( "80386 cpu, " );
	    if ( TempFlags & WF_CPU486 )
	       dprintf ( "80486 cpu, " );
	    if ( !(TempFlags & WF_80x87) )
	       dprintf ( "no " );
	    dprintf ( "80x87 math coprocessor, " );
	    if ( TempFlags & WF_ENHANCED )
	       dprintf ( "386 enhanced " );
	    if ( TempFlags & WF_STANDARD )
	       dprintf ( "standard " );
	    if ( TempFlags & WF_PMODE )
	       dprintf ( "protected mode" );
	    if ( TempFlags & WF_SMALLFRAME )
	       dprintf ( "small-frame EMS" );
	    if ( TempFlags & WF_LARGEFRAME )
	       dprintf ( "large-frame EMS" );
	    dprintf ( "\n" );
#endif

    if ( !( ( TempFlags & WF_ENHANCED ) | ( TempFlags & WF_STANDARD ) ) )
    {
	hMemTemp = GlobalAlloc ( GMEM_MOVEABLE ,
			       TotFreeMem = GlobalCompact ( dwMinFree ) );
	if ( hMemTemp == NULL )
	{
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CANTCOMPACT );
	}
	GlobalFree ( hMemTemp );
	dprintf ( "Free Memory = %li\n" , TotFreeMem );
    }

    MakeHelpPathName ( szHelpFileName );

    if ( !hPrevInstance )
    {
	/* Initialize the menu window class */
        if ( ( hMemory = LocalAlloc(LPTR, sizeof(WNDCLASS)) ) == NULL )
        {

#if defined ( DEBUG )
	    dprintf ( "Cannot allocate local heap for WndClass structure\n" );
#endif

            OutOfMem ();
        }
	pWndClass = (PWNDCLASS) LocalLock(hMemory);

	pWndClass->style	 = NULL;
	pWndClass->lpfnWndProc	 = Bible4WndProc;
	pWndClass->hInstance	 = hInstance;
	pWndClass->hIcon	 = LoadIcon (hInstance, "Bible4W_v1.3");
	pWndClass->hCursor	 = LoadCursor (NULL, IDC_ARROW);
	pWndClass->hbrBackground = GetStockObject (WHITE_BRUSH);
	pWndClass->lpszMenuName  = (LPSTR) "Bible4W1.3Menu",
	pWndClass->lpszClassName = szClassName;

	bTemp = RegisterClass ( pWndClass );
	LocalUnlock ( hMemory );
	LocalFree ( hMemory );
	if ( !bTemp ) return bTemp;
    }
/* If running on a Pen Windows system, register this app so all
		EDIT controls in dialogs are replaced by HEDIT controls.
		(Notice the CONTROL statement in the RC file is "EDIT",
		RegisterPenApp will automatically change that control to
		an HEDIT.
*/

	if ((hPenWin = GetSystemMetrics(SM_PENWINDOWS)) != NULL)
	{
/*
   We do this fancy GetProcAddress simply because we don't know if we're
   running Pen Windows.
*/
#if defined ( DEBUG )
	   dprintf ( "hPenWin != NULL\n" );
#endif

	   if ( (RegPenApp = GetProcAddress(hPenWin, "RegisterPenApp"))
				    != NULL) (*RegPenApp)(RPA_DEFAULT, TRUE);
	}

	/* load the libarary containing the custom dictionary procedure */
	if ( hPenWin )
	{
	   if ((hCustomDictLib = LoadLibrary(szCustomDictLib)) >= 32)
		{
		if ((lpdfCustomDictProc = GetProcAddress(hCustomDictLib, szCustomDictProc)) == NULL)
 			return FALSE;
		}
	   else
		{
		(void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 0 , IDS_CHECKPATH, (LPSTR)szCustomDictLib);
		return FALSE;
		}
	   lpfnLookUp = MakeProcInstance ( fLookUp , hInst );
	}

/* Create the app. window */

    return ( ( hWnd = CreateWindow (
			 szClassName,
			 szAppName,
                         WS_OVERLAPPEDWINDOW | WS_VSCROLL |
                                               ES_AUTOVSCROLL,
			 CW_USEDEFAULT,
			 CW_USEDEFAULT,
			 cxScreen * 9 / 10,
			 cyScreen * 9 / 10,
			 (HWND) NULL,
			 NULL,
			 hInstance,
			 (LPSTR) NULL
			 ) ) == NULL ? FALSE : TRUE );
}

BOOL FAR OPEN_KJB ( HFILE FAR *pFile, LPSTR szFileName, WORD szMode )
{
#ifdef DEBUG
    char szMsgx[18];
#endif

    if ((*pFile = OpenFile(szFileName,&ofKJB,szMode)) == HFILE_ERROR)
    {
	bCriticalSection1 = TRUE;
	switch (wKJBDriveType)
	{
	case 0:
	default:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENB, (LPSTR)szFileName );
	    break;

	case DRIVE_REMOVABLE:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENBR, (LPSTR)szFileName );
	    break;

	case DRIVE_FIXED:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENBF, (LPSTR)szFileName );
	    break;

	case DRIVE_REMOTE:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENBN, (LPSTR)szFileName );
	    break;
	}
//	  bCriticalSection1 = FALSE;
	return ( TRUE );
    }
    if ( bFirstOpenKJB )
    {
	bFirstOpenKJB = FALSE;
	dprintf ( "KJB database pathname = %s\n" , ofKJB.szPathName );
	wKJBDriveType = GetDriveType((int)(ofKJB.szPathName[0]-'A'));
#ifdef DEBUG
	szMsgx[0]='\0';
	switch (wKJBDriveType)
	{
	case 0:
	    strcat(szMsgx, "undetermined");
	    break;

	case DRIVE_REMOVABLE:
	    strcat(szMsgx, "removable");
	    break;

	case DRIVE_FIXED:
	    strcat(szMsgx, "fixed");
	    break;

	case DRIVE_REMOTE:
	    strcat(szMsgx, "remote (network)");
	    break;
	}
	dprintf("KJB file type is %s\n" , szMsgx);
#endif
    }
    return ( FALSE );
}

BOOL FAR OPEN_CLIP ( HFILE FAR *pFile, LPSTR szFileName, WORD szMode )
{
#ifdef DEBUG
    char szMsgx[18];
#endif

    if ((*pFile = OpenFile(szFileName,&ofCLIP,szMode)) == HFILE_ERROR)
    {
	switch (wCLIPDriveType)
	{
	case 0:
	default:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENS, (LPSTR)szFileName );
	    break;

	case DRIVE_REMOVABLE:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENSR, (LPSTR)szFileName );
	    break;

	case DRIVE_FIXED:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENSF, (LPSTR)szFileName );
	    break;

	case DRIVE_REMOTE:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENSN, (LPSTR)szFileName );
	    break;
	}
	return ( TRUE );
    }
    if ( bFirstOpenCLIP )
    {
	bFirstOpenCLIP = FALSE;
	dprintf ( "Clipboard scratch file pathname = %s\n" , ofCLIP.szPathName );
	wCLIPDriveType = GetDriveType((int)(ofCLIP.szPathName[0]-'A'));
#ifdef DEBUG
	szMsgx[0]='\0';
	switch (wCLIPDriveType)
	{
	case 0:
	    strcat(szMsgx, "undetermined");
	    break;

	case DRIVE_REMOVABLE:
	    strcat(szMsgx, "removable");
	    break;

	case DRIVE_FIXED:
	    strcat(szMsgx, "fixed");
	    break;

	case DRIVE_REMOTE:
	    strcat(szMsgx, "remote (network)");
	    break;
	}
	dprintf("Clipboard scratch file type is %s\n" , szMsgx);
#endif
    }
    return ( FALSE );
}


void FAR DisplayKJBError ()
{
	switch (wKJBDriveType)
	{
	case 0:
	default:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENB, (LPSTR)"" );
	    break;

	case DRIVE_REMOVABLE:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENBR, (LPSTR)"" );
	    break;

	case DRIVE_FIXED:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENBF, (LPSTR)"" );
	    break;

	case DRIVE_REMOTE:
	    (void)BWError ( hWnd, MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				  , 1 , IDS_CANTOPENBN, (LPSTR)"" );
	    break;
	}
    return;
}

VOID FAR WinPrintfJK ( LPSTR a , ... )
{
#ifdef DEBUG
   if ( DebugFlag == 1 ) WinPrintf (a, *((&(DWORD)a)+1), *((&(DWORD)a)+2),
		     *((&(DWORD)a)+3), *((&(DWORD)a)+4), *((&(DWORD)a)+5) );
#endif
   return;
}

BOOL FAR LockRes (void)
{
	if ( ( lpPoWords1 = ( int FAR * )LockResource ( hPoWords1 ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
	    UnlockResource ( hPoWords1 );
	    return ( TRUE );
        }
	if ( ( lpPoWords2 = ( int FAR * )LockResource ( hPoWords2 ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
	    UnlockResource ( hPoWords1 );
	    UnlockResource ( hPoWords2 );
	    return ( TRUE );
        }
	if ( ( lpWords1 = ( char FAR * )LockResource ( hWords1 ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
	    UnlockResource ( hPoWords1 );
	    UnlockResource ( hPoWords2 );
	    UnlockResource ( hWords1 );
	    return ( TRUE );
        }
	if ( ( lpWords2 = ( char FAR * )LockResource ( hWords2 ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
	    UnlockResource ( hPoWords1 );
	    UnlockResource ( hPoWords2 );
	    UnlockResource ( hWords1 );
	    UnlockResource ( hWords2 );
	    return ( TRUE );
        }
	if ( ( lpListSizes = ( char FAR * )LockResource ( hListSizes ) ) == NULL )
        {
	    (void)BWError ( hWnd,
				    MB_APPLMODAL | MB_OK | MB_ICONEXCLAMATION
				    , 1 , IDS_OUTOFMEM );
	    UnlockResource ( hPoWords1 );
	    UnlockResource ( hPoWords2 );
	    UnlockResource ( hWords1 );
	    UnlockResource ( hWords2 );
	    UnlockResource ( hListSizes );
	    return ( TRUE );
        }
	return ( FALSE );
}
BOOL FAR UnLockRes (void)
{
	UnlockResource ( hPoWords1 );
	UnlockResource ( hPoWords2 );
	UnlockResource ( hWords1 );
	UnlockResource ( hWords2 );
	UnlockResource ( hListSizes );
    return ( FALSE );
}
