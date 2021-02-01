/****************************************************************************
 *									    *
 *  FILE	: Bible4w.h						    *
 *									    *
 *  DESCRIPTION : Header file for Bible4w				    *
 *									    *
 ****************************************************************************/

#include "muscroll.h"
#include "bwindlg.h"
#define TRUE 1
#define FALSE 0

#ifdef DEBUG
        BOOL    __f;
        extern  int FAR _Assert(PSTR,int);
	extern  BOOL fDebug;
	#define dprintf if (fDebug) WinPrintfJK
        #define WinAssert(exp)  ((exp) ? 0 : _Assert(__FILE__,__LINE__))
        #define WinEval(exp) (__f=(exp),WinAssert(__f),__f)
#else
        #define dprintf if (0) ((int (*)(char *, ...)) 0)
        #define WinAssert(exp) 0
        #define WinEval(exp) (exp)
#endif

#define MAXVER 33000
#define MAXWRD 25000
#define NDIMW	 190
#define NLENW	1024
#define NPUN	   8
#define MAXLIN	  80

#define maxwrd_dim     25001
#define maxver_dim     33001
#define ndimw_dim	 191
#define nlenw_dim	1024
#define maxlin_dim	  81
#define VerseRefBufSize  500
#define PICKLISTSIZE	 100
#define EXE_NAME_MAX_SIZE  128

#define COLOR_SCALE_RED     1
#define COLOR_SCALE_GREEN   2
#define COLOR_SCALE_BLUE    3
#define COLOR_SCALE_GRAY    4


int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR  lpCmdLine, int nCmdShow);
//extern int PASCAL WinMain(HANDLE, HANDLE, LPSTR, int);
LRESULT CALLBACK  Bible4WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK  About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK  FindDlg(HWND, unsigned, WORD, LONG);
BOOL CALLBACK  GoToDlg(HWND, unsigned, WORD, LONG);
BOOL CALLBACK  KeypadDlg(HWND, unsigned, WORD, LONG);
BOOL CALLBACK  BooksDlg(HWND, unsigned, WORD, LONG);
BOOL CALLBACK  WordListDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
extern VOID FAR CHPWRD ( char[] , long int , long int );
extern VOID FAR I1PWRD ( char[] , long int , long int );
extern VOID FAR I4PWRD ( long int , long int );
extern VOID FAR CHGWRD ( char huge[] , long int , long int );
extern VOID FAR I1GWRD ( char[] , long int , long int );
extern VOID FAR I4GWRD ( long int* , long int );
extern VOID FAR GETWRD ( int* , long int );
extern VOID FAR PUTWRD ( int , long int );
extern void FAR DisplayKJBError ( void );
extern short FAR BWError(HWND hwnd, WORD bFlags, WORD quit, WORD id, ...);

extern int I2ZERO;
extern long int LASTAD , IRECIN , IRMOD;
extern int I2IX[257];
extern HFILE IUNIT10;
extern HWND hWnd;

/* strings */
#define IDS_CANTOPENB	 1
#define IDS_CANTREAD	 2
#define IDS_CANTCREATE	 3
#define IDS_CANTWRITE	 4
#define IDS_ILLFNM	 5
#define IDS_CANTFIND	 8
#define IDS_HELPNOTAVAIL 9
#define IDS_CANTOPENS	10
#define IDS_ABORT	11
#define IDS_SMALLSCREEN 12
#define IDS_BADBOOKARG	14
#define IDS_CHAPT0	15
#define IDS_CANTRECOGNIZE 16
#define IDS_NOFINDWRD	17
#define IDS_APPNAME	18
#define IDS_CANTRECOGBOOK 19
#define IDS_CANTRECOGCHAPT 20
#define IDS_CANTRECOGVER  21
#define IDS_BADBOOK	  22
#define IDS_BADCHAPT	  23
#define IDS_CHAPT2BIG	  24
#define IDS_BADVERSE	  25
#define IDS_VERSE0	  26
#define IDS_VERSE2BIG	  27
#define IDS_BADDATABASE   28
#define IDS_BADHELPFILE   29
#define IDS_CANTRESIZE	  30
#define IDS_CANTGOUP	  31
#define IDS_CANTGODOWN	  32
#define IDS_CANTPAGEUP	  33
#define IDS_CANTPAGEDOWN  34
#define IDS_PLISTFULL	  35
#define IDS_BADDB2	  36
#define IDS_OUTOFMEM	  37
#define IDS_PLISTEMPTY	  38
#define IDS_CANTCOMPACT   39
#define IDS_CHECKPATH	  40
#define IDS_OUTOFCBSPACE  41
#define IDS_CANTOPENBR	  42
#define IDS_CANTOPENBF	  43
#define IDS_CANTOPENBN	  44
#define IDS_CANTOPENSR	  45
#define IDS_CANTOPENSF	  46
#define IDS_CANTOPENSN	  47
#define IDS_ILLEGALWRITE  48
#define IDS_BADDBN	  49
#define IDS_OWNERLISTBOX  50
