

#pragma  alloc_text( SEG3, WordListDlg )
/****************************************************************************
 *									    *
 *  FUNCTION   : WordListDlg (hDlg, message, wParam, lParam)		    *
 *									    *
 *  PURPOSE    : Dialog function for the WordList dialog box.		    *
 *									    *
 ****************************************************************************/
BOOL CALLBACK _export WordListDlg(hDlg, message, wParam, lParam)

HWND hDlg;
unsigned message;
WORD wParam;
LONG lParam;

{
int i;

    switch (message)
	{
	case WM_INITDIALOG:
	    for ( i = 18 ; i < 13856 ; i++ )
	    {
	       dwIndex = SendDlgItemMessage ( hDlg, DLGWORDLISTBOX,
						    LB_ADDSTRING, (DWORD)i );
	    }
	    return(TRUE);

	case WM_COMMAND:
	    switch (wParam)
	    {

	    case DLGWORDLISTOK:
		EndDialog(hDlg,NULL);
		return(TRUE);
		break;

	    case DLGWORDLISTCANCEL:
		EndDialog(hDlg,NULL);
		return(TRUE);
		break;

	    }
	    break;
	}
    return(FALSE);
}
