/************************************************************

	PROGRAM:	CUSTDICT.H

	PURPOSE:
	
		Header file for CUSTDICT.C


************************************************************/


/* Global Variables */
char	* szDescription =	"Custom Dictionary (Bible words)";

/* Constants */
#define cbMaxLen	256


/* Prototypes */
BOOL NEAR PASCAL FBestGuess(LPSTR, LPSYV);
int  NEAR PASCAL GetDllDescription(LPSTR, int);
