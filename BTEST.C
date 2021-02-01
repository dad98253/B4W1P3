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
//#include <windowsx.h>
#include <penwin.h>
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
#include "bible4w.h"
#include "wprintf.h"

		   /*  + + + + +  Macros  + + + + +  */

		  /*  + + + + +  Functions  + + + + +  */

BOOL FAR PASCAL Bible4wInit(HINSTANCE, HINSTANCE);
BOOL FAR PASCAL Bible4wPaint ( HWND );
void NEAR GETOC ( long int );
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
VOID FAR PASCAL Index2Word (int i, LPSTR szAword , LPINT nLAWORD);


		/*  + + + + +  Static Globals  + + + + +  */

char    szDatabaseName[120];
char *	szCustomDictLib	= "custdict.dll";
char *	szCustomDictProc = "DictionaryProc";
HANDLE 	hCustomDictLib;
LPDF	lpdfCustomDictProc;
FARPROC lpfnLookUp;
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
char AWORD[33];
//char ALN[82]; 		  what was this used for ????
//char huge (*hpWORDS)[ndimw_dim][nlenw_dim];
char FAR *lpWords1;
char FAR *lpWords2;
GLOBALHANDLE hWords1;
GLOBALHANDLE hWords2;
char FAR *lpListSizes;


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


#pragma  alloc_text( SEG3, FindDlg )
/****************************************************************************
 *									    *
 *  FUNCTION   : FindDlg (hDlg, message, wParam, lParam)		    *
 *									    *
 *  PURPOSE    : Dialog function for the Find dialog box.		    *
 *									    *
 ****************************************************************************/
BOOL CALLBACK _export FindDlg(hDlg, message, wParam, lParam)

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
//		Index2Word ( (INT)DialogBox (hInst, "DlgWordList", hWnd,
//		       lpProc) , &AWORD[1] , &LAWORD );
		FreeProcInstance ((FARPROC)lpProc);
//		SetDlgItemText (hDlg , DLGFINDEDITBOX , &AWORD[1] );
		return(TRUE);
		break;

	    case DLGFINDWORDLIST2:
		// Bring up the word list dialog box
//		lpProc = (DLGPROC)MakeProcInstance ((FARPROC)WordListDlg,
//								      hInst);
		bDoListAtoK = FALSE;
//		Index2Word ( (INT)DialogBox (hInst, "DlgWordList", hWnd,
//		       lpProc) , &AWORD[1] , &LAWORD );
		FreeProcInstance ((FARPROC)lpProc);
//		SetDlgItemText (hDlg , DLGFINDEDITBOX , &AWORD[1] );
		return(TRUE);
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
 *  FUNCTION   : Index2Word (INT i, LPSTR szAword, *INT nLAWORD)	    *
 *									    *
 *  PURPOSE    : Convert a dictionary index number to a string.		    *
 *									    *
 ****************************************************************************/
VOID FAR PASCAL Index2Word (INT i, LPSTR szAword , LPINT nLAWORD)
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
   *nLAWORD = IWLT2;
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
BOOL CALLBACK _export WordListDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
	       nListStart = iSizeWordp1 >> 1;
	       nListEnd = ( iSizeWordp1 >> 1 ) + ( iSizeWordp2 >> 1 ) - 2; // 13856
	    }
	    for ( i = nListStart ; i < nListEnd	; i++ )
	    {
	       if ( i < iFirstd )
	       {
		  IS1 = *(lpPoWords1 + i - 1 );
		  IS2 = *(lpPoWords1 + i     );
		  IS3 = *(lpPoWords1 + i + 1 );
		  IWLT1 = IS2 - IS1;
		  IWLT2 = IS3 - IS2;
		  if ( IWLT1 == IWLT2 )
		  {
		     if ( _fstrnicmp( lpWords1+IS1 , lpWords1+IS2 ,
				      (size_t)IWLT1 ) == 0 ) continue;
		  }
	       }
	       else
	       {
		  if ( i != iFirstd )
		  {
		     IS1 = *(lpPoWords2 + i - 1 - iFirstd );
		     IS2 = *(lpPoWords2 + i - iFirstd );
		     IS3 = *(lpPoWords2 + i + 1 - iFirstd );
		     IWLT1 = IS2 - IS1;
		     IWLT2 = IS3 - IS2;
		     if ( IWLT1 == IWLT2 )
		     {
			if ( _fstrnicmp( lpWords2+IS1 , lpWords2+IS2 ,
					 (size_t)IWLT1 ) == 0 ) continue;
		     }
		  }
	       }
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
		   EndDialog ( hDlg, SendDlgItemMessage ( hDlg, DLGWORDLISTLB,
					      LB_GETITEMDATA, dwIndex, 0 ) );
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
