/****************************************************************************
 *									    *
 *  FILE	: convert.h						    *
 *									    *
 *  DESCRIPTION : Header file for convert				    *
 *									    *
 ****************************************************************************/

#include "convdlg.h"
#define TRUE 1
#define FALSE 0

#ifdef DEBUG
        BOOL    __f;
        extern  int FAR _Assert(PSTR,int);
	extern  BOOL fDebug;
        #define dprintf if (fDebug) WinPrintf
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
#define EXE_NAME_MAX_SIZE  128



int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR  lpCmdLine, int nCmdShow);
LRESULT CALLBACK _export Bible4WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK _export About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
extern VOID FAR CHPWRD ( char[] , long int , long int );
extern VOID FAR I1PWRD ( char[] , long int , long int );
extern VOID FAR I4PWRD ( long int , long int );
extern VOID FAR CHGWRD ( char huge[] , long int , long int );
extern VOID FAR I1GWRD ( char[] , long int , long int );
extern VOID FAR I4GWRD ( long int* , long int );
extern VOID FAR GETWRD ( int* , long int );
extern VOID FAR PUTWRD ( int , long int );

extern int I2ZERO;
extern long int LASTAD , IRECIN , IRMOD;
extern int I2IX[257];
extern long int LASTAD2 , IRECIN2 , IRMOD2;
extern int I2IX22[257];
extern HFILE IUNIT10;
extern HFILE IUNIT11;


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
