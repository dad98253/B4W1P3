PROJ = BIB4W1P3
PROJFILE = BIB4W1P3.MAK
DEBUG = 1

PWBRMAKE  = pwbrmake
NMAKEBSC1  = set
NMAKEBSC2  = nmake
CC  = cl
CFLAGS_G  = /W2 /Gw /Zp /BATCH
CFLAGS_D  = /Od /Zi /Ze
CFLAGS_R  = /Oe /Og /Os /Gs /FPa
FOR  = fl
FORFLAGS_G  = /MW1 /G2
FORFLAGS_R  = /Ot /Ol /Gs
FORFLAGS_D  = /Zi /Od /4Yb
ASM  = ml
AFLAGS_G  = /Cx /W2 /WX
AFLAGS_D  = /Zi
AFLAGS_R  = /nologo
MAPFILE_D  = NUL
MAPFILE_R  = NUL
LFLAGS_G  =  /STACK:8000  /BATCH
LFLAGS_D  =  /CO /NOF /NOP
LFLAGS_R  =  /NOF /NOP
LLIBS_G  = libw slibcew slibce
LINKER	= link
ILINK  = ilink
LRF  = echo > NUL
RC  = rc
LLIBS_D  = wprintf

DEF_FILE  = BIBLE4W.DEF
OBJS  = BIBLE4W.obj GETWRDW.obj
LIBS_EXT  = CUSTDICT.LIB MUSCROLL.LIB
LIBS  = $(LIBS_EXT)
RESS  = BIBLE4W.res
SBRS  = BIBLE4W.sbr GETWRDW.sbr

all: $(PROJ).exe

.SUFFIXES:
.SUFFIXES: .sbr .obj .res .c .rc

BIBLE4W.obj : BIBLE4W.C bible4w.h wprintf.h muscroll.h bwindlg.h

BIBLE4W.sbr : BIBLE4W.C bible4w.h wprintf.h muscroll.h bwindlg.h

GETWRDW.obj : GETWRDW.C bible4w.h muscroll.h bwindlg.h

GETWRDW.sbr : GETWRDW.C bible4w.h muscroll.h bwindlg.h

BIBLE4W.res : BIBLE4W.RC bible4w.h bible4w.dlg bwFind.dlg bpFind.dlg goto.dlg\
	bpgoto.dlg bkeypad.dlg bbooks.dlg wordlist.dlg muscroll.h bwindlg.h


$(PROJ).bsc : $(SBRS)
	$(PWBRMAKE) @<<
$(BRFLAGS) $(SBRS)
<<

$(PROJ).exe : $(DEF_FILE) $(OBJS) $(LIBS) $(RESS)
!IF $(DEBUG)
	$(LRF) @<<$(PROJ).lrf
$(RT_OBJS: = +^
) $(OBJS: = +^
)
$@
$(MAPFILE_D)
$(LLIBS_G: = +^
) +
$(LLIBS_D: = +^
) +
$(LIBS: = +^
)
$(FOR_DEFS) $(DEF_FILE) $(LFLAGS_G) $(LFLAGS_D);
<<
!ELSE
	$(LRF) @<<$(PROJ).lrf
$(RT_OBJS: = +^
) $(OBJS: = +^
)
$@
$(MAPFILE_R)
$(LLIBS_G: = +^
) +
$(LLIBS_R: = +^
) +
$(LIBS: = +^
)
$(FOR_DEFS) $(DEF_FILE) $(LFLAGS_G) $(LFLAGS_R);
<<
!ENDIF
	$(LINKER) @$(PROJ).lrf
	$(RC) $(RESS) $@


.c.sbr :
!IF $(DEBUG)
	$(CC) /Zs $(CFLAGS_G) $(CFLAGS_D) /FR$@ $<
!ELSE
	$(CC) /Zs $(CFLAGS_G) $(CFLAGS_R) /FR$@ $<
!ENDIF

.c.obj :
!IF $(DEBUG)
	$(CC) /c $(CFLAGS_G) $(CFLAGS_D) /Fo$@ $<
!ELSE
	$(CC) /c $(CFLAGS_G) $(CFLAGS_R) /Fo$@ $<
!ENDIF

.rc.res :
	$(RC) /r $<


run: $(PROJ).exe
	WIN $(PROJ).exe $(RUNFLAGS)

debug: $(PROJ).exe
	WIN CVW $(CVFLAGS) $(PROJ).exe $(RUNFLAGS)
