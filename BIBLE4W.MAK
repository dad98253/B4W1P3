PROJ = BIBLE4W
PROJFILE = BIBLE4W.MAK
DEBUG = 1

CC  = cl
CFLAGS_G  = /W2 /Gw /Zp /BATCH
CFLAGS_D  = /Od /Zi /DDEBUG /Ze
CFLAGS_R  = /Os /Og /Oe /Gs
MAPFILE_D  = NUL
MAPFILE_R  = NUL
LFLAGS_G  =  /NOD /STACK:8000  /ST:8000 /BATCH
LFLAGS_D  =  /CO /NOF /NOP
LFLAGS_R  =  /FAR /PACKC /PACKD
LLIBS_G  = LIBW.LIB slibcew slibce
LINKER	= link
ILINK  = ilink
LRF  = echo > NUL
RC  = rc
LLIBS_D  = wprintf
CVFLAGS  =  /25 /S

DEF_FILE  = BIBLE4W.DEF
OBJS  = BIBLE4W.obj GETWRDW.obj
LIBS_EXT  = CUSTDICT.LIB MUSCROLL.LIB
LIBS  = $(LIBS_EXT)
RESS  = BIBLE4W.res

all: $(PROJ).exe

.SUFFIXES:
.SUFFIXES: .obj .res .c .rc

BIBLE4W.obj : BIBLE4W.C bible4w.h wprintf.h muscroll.h bwindlg.h
!IF $(DEBUG)
	$(CC) /c $(CFLAGS_G) $(CFLAGS_D) /FoBIBLE4W.obj BIBLE4W.C
!ELSE
	$(CC) /c $(CFLAGS_G) $(CFLAGS_R) /FoBIBLE4W.obj BIBLE4W.C
!ENDIF

BIBLE4W.res : BIBLE4W.RC bible4w.h bible4w.dlg bwFind.dlg bpFind.dlg goto.dlg\
	bpgoto.dlg bkeypad.dlg bbooks.dlg muscroll.h bwindlg.h

GETWRDW.obj : GETWRDW.C bible4w.h muscroll.h bwindlg.h


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
$(DEF_FILE) $(LFLAGS_G) $(LFLAGS_D);
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
$(DEF_FILE) $(LFLAGS_G) $(LFLAGS_R);
<<
!ENDIF
!IF $(DEBUG)
	$(LINKER) @$(PROJ).lrf
!ELSE
	$(LINKER) @$(PROJ).lrf
!ENDIF
	$(RC) $(RESS) $@


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
