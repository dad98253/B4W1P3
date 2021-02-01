Table of Contents
Abstract:	2
System Requirements:	2
Installation Instructions:	3
Installing a Copy Down-Loaded From a BBS:	5
Installing From Diskettes:	6
Installing From a CD ROM Flat File:	6
Running Bible4W:	9
Terms of Use:	10
For Additional Help...	10
King James Bible Notes	11
Appendix	12
Supplier List:	12
Acknowledgements:	13



Abstract:
Bible4W (formerly called Bible for Windows) is a simple no frills electronic 
bible program.  Because it uses a non-copyrighted version of the King James 
text, it can be given away free.  It can look up text by Book-Chapter-Verse 
and then scroll through the text.  Verses can be selected and copied to the 
Windows clipboard for use in a word processor.  It can also be used as an 
electronic concordance, but it can not do complex Boolean word searches as 
many other Bible programs can.  It is fast enough to run on even the slowest 
Windows machine.  It will run on a 4MHz XT, but the memory requirements are 
such that it can barely squeeze into memory when running Windows in real 
mode with only 640K memory.  You will want about 1M Byte to run Bible4W 
along with your word processor!  Liberal use is made of the hyper-text 
Windows Help utility to provide on-line documentation.

This version has been tested for use with Microsoft Windows versions 3.0 and 
3.1, Microsoft Pen Windows version 3.1, J-Windows (Japan) version 3.0, OS/2 
version 1.3 running Windows 3.0 in the compatibility box and OS/2 version 
2.0.  In addition, an alternative version (version 1.2NT) is available which 
has been compiled in 32 bit mode to run on the July 1992 pre-release of 
Windows NT.

This version (except for the Windows NT release) is "Pen Aware"... i.e., the 
program automatically detects when it is being run on a Pen Windows system, 
and will use modified dialog boxes for Bible4W's "Find..." and "Go To..." 
commands.  The modified dialog boxes use handwriting recognition edit boxes 
rather than the standard Windows edit boxes.  A custom dictionary (file 
custdict.dll) is included.  It is used by the Pen Windows handwriting 
recognition routine to help identify the names of the books of the Bible and 
the words used in the Bible.  (The standard Microsoft dictionary does not 
include words like "escapeth" and "Abelmeholah"!)
System Requirements:

- IBM PC, XT, or compatible with 640K RAM (or more)
	or
  IBM AT, PS/1, [286]PS/2, or 286 compatible with 1M RAM (or more)
	or
  IBM [386]PS/2 or 386 compatible with 2M RAM (or more)
	or (for the Windows NT release)
  IBM [386]PS/2 or 386 compatible with 10M RAM (or more)

- supports monochrome or color monitors

- hard disk with 4.3MB available unused space 
  ( 8.6MB to install from files down-loaded from a BBS )

- a 1.2MB or a 360KB floppy disk drive
  ( when installing from floppy disks )

- Microsoft Windows version 3.0 or later
	or
  Microsoft Pen Windows version 3.1 or later
	or
  Microsoft J-Windows (Japan) version 3.0
	or
  OS/2 version 2.0
	or
  OS/2 version 1.2 or later plus Microsoft Windows version 3.0
	or
  the July 1992 pre-release of Windows NT

Installation Instructions:

The following instructions assume that you have copies of all of the files 
required to install Bible4W.  If you...

Down-loaded Bible4W from a bulletin board:
You should have 12 sets of archived files (probably) in .ZIP format.  Each 
archive contains the equivalent of one 360K Byte diskette.

Received Bible4W on 360K Byte diskettes:
You should have 12 diskettes.  The first diskette will contain all of the 
program, help, and installation files.  The remaining diskettes will contain 
the King James text database files kjb2p0.dat, kjb2p0.da2, ... thru 
kjb2p0.d11.

Received Bible4W on 1.2M Byte diskettes:
You should have 4 diskettes.  The first diskette will contain all of the 
program, help, and installation files plus the first two King James text 
database files (kjb2p0.dat and kjb2p0.da2).  The remaining diskettes will 
contain the King James text database files (kjb2p0.da3, kjb2p0.da4, ... thru 
kjb2p0.d11), three per diskette.

Received the 1.2NT release of Bible4W on 1.2M Byte diskettes:
You should have 4 diskettes.  The first diskette will contain the Biblw4W 
help and installation files plus the first King James text database file 
(kjb2p0.dat).  The next two diskettes will contain the King James text 
database files kjb2p0.da2 and kjb2p0.da3.  The last diskette will contain 
the Bible4W program and the King James text database file kjb2p0.da4.

Received Bible4W on CD ROM:
The way that the program is stored on the CD ROM can vary, but it will 
likely be in one of the following three formats: 1)  BBS image format, 2) 
floppy disk image format, or 3) flat file format.  The storage format used 
is important, because the steps necessary for you to use the program depend 
on how it is stored on the CD ROM.  The steps for each case are outlined 
below, but first you will need to identify the format.  The first thing that 
you should do is read over any documentation that came with your CD ROM 
disk.  If it gives you specific information on how you must load or run 
Bible4W, then ignore the steps outlined below.  If it does not mention 
Bible4W specifically, but tells how to copy CD ROM files onto your hard 
disk, look for mention of special file copying programs or "data 
compression".  If they mention either of these, then the program is stored 
in BBS image format.  Follow their instructions for copying the files onto 
your hard disk, and then install the program as if you had downloaded the 
files from a BBS.  If the CD ROM instructions say that you can use the DOS 
"copy" command to move the files to your hard disk, or do not indicate how 
to read the CD ROM, then you will need to perform the following experiment 
to determin if the program is stored as floppy disk images, or as a flat 
file:  put the CD ROM in your CD drive, and open the Windows File Manager 
program.  You should see a CD ROM icon somewhere on the disk drive button 
bar.  It will look like a CD drive with a tiny CD ROM disk hanging half out 
of the drive.  Click on the CD drive button with your mouse to bring up a 
directory tree of the files on the CD ROM.  Browse through the files on the 
CD ROM until you find the Bible4W program.  Hopefully, the CD ROM publisher 
will have put all of the Bible4W files in a sub-directory of their own with 
an obvious directory name such as "BIBLE4W".  Look for a file in this 
directory named KJB2P0.DAT.  If its length is less than 3,900,000 Bytes, 
then the files are stored as floppy disk images, and you will need to follow 
the instructions below for installing the program from floppy disks.  
However, if the KJB2P0.DAT file is slightly greater that the size indicated 
above, then the program is stored in flat file format.  If the program is 
stored in flat file format, then you do not need to install it on your hard 
drive.  It can be executed directly from the CD ROM disk!  See the notes 
below for installing from a CD ROM flat file.

Regardless of how you received Bible4W (floppy disk, BBS, or CD ROM), it 
would be worth your time to check the sizes, dates, and time tags of each of 
these files at this point.  The Bible4W Install program thoroughly checks 
the integrity of these files during the installation process.  If any of 
them have been damaged or tampered with in any way, the Install program will 
detect it and display an error message.  Depending on the severity of the 
damage, the program may or may not be able to successfully complete the 
installation.  The diskettes (or .ZIP archives) should contain the following 
files (as a minimum... additional files may have been added by the 
distributor of the disks or the BBS SysOp):

for the 16 bit Windows version:
              appsetup inf      ???? 03-22-92  ??:???
              bible4w  exe    290816 03-21-92   2:51p
              bible4w  hlp     22270 03-21-92   2:53p
              custdict.dll      7871 03-21-92   2:50p
              install  exe     39968 01-19-92  12:51a
              readme   txt      ???? 03-22-92  ??:???
              kjb2p0   dat    362496 09-07-91  15:15a
              kjb2p0   da2    362496 09-07-91  14:50a
              kjb2p0   da3    362496 09-07-91  16:38a
              kjb2p0   da4    362496 09-07-91   2:43p
              kjb2p0   da5    362496 09-07-91   8:48a
              kjb2p0   da6    362496 09-07-91  19:59a
              kjb2p0   da7    362496 09-07-91  14:54a
              kjb2p0   da8    362496 09-07-91   1:41p
              kjb2p0   da9    362496 09-07-91   8:55p
              kjb2p0   d10    362496 09-07-91   9:56a
              kjb2p0   d11    275968 09-07-91   3:56p

for the 32 bit Windows version:
              appsetup inf      ???? 03-22-92  ??:???
              bible4w  exe    290816 03-21-92   2:51p
              bible4w  hlp     22270 03-21-92   2:53p
              install  exe     39968 01-19-92  12:51a
              readme   txt      ???? 03-22-92  ??:???
              kjb2p0   dat    362496 09-07-91  15:15a
              kjb2p0   da2    362496 09-07-91  14:50a
              kjb2p0   da3    362496 09-07-91  16:38a
              kjb2p0   da4    362496 09-07-91   2:43p

NOTE:  All CD ROM versions (i.e., 16 or 32 bit) which are distributed in 
flat file format will probably be missing the the KJB2P0.DAn and KJB2P0.Dnn 
files (where n is a number).  In this case, the KJB2P0.DAT file will be 
3900928 Bytes long and have a date of 09-07-91, and the time tag could be 
anything.  The APPSETUP.INF and INSTALL.EXE files may also be missing, 
because you won't need them.


During the installation process, the Install program will be assembling 
these files onto your hard disk.  If you don't have an additional 4,300,000 
Bytes of available space on your disk, don't bother to try to install 
Bible4W.  You will first need to make the required space available by 
deleting or archiving some of the other files on your disk.

Installing a Copy Down-Loaded From a BBS:

Files available from electronic Bulletin Boards (BBS) are often distributed 
in a "compressed" or "archived" format.  The format used varies from one BBS 
to another.  The following instructions assume that you have successfully 
down-loaded all of the files necessary to install Bible4W, that they have 
been "de-compressed" or "un-archived", and that they have all been copied 
into a single directory on your hard drive.  This directory should now 
contain all of the files listed above.

NOTE:  During the installation process, the Install program will be 
assembling the files that you have down-loaded onto your hard disk into a 
second directory.  This means that during the installation process you will 
at one point have two complete copies of Bible4W on your disk.  If you don't 
have an additional 4,300,000 Bytes of available space on you disk, don't 
bother to try to install Bible4W.  You will first need to make the required 
space available by deleting or archiving some of the other files on your 
disk.  Once Bible4W has been installed, the files listed above can be 
deleted.

If you are not already in Microsoft Windows, start it up now.  The Bible4W 
Install program cannot be run from the DOS prompt.  It is a "Windows 
Application" program, and requires Windows to run.

From your Windows desktop, open up the Program Manager program and pull down 
the "File" menu.  Select "Run" from the "File" menu.  Type in the full path 
(drive letter and sub-directory name) and file name (i.e., 
c:\download\install.exe ) of the Bible4W Install program and click on the 
Enter button.  You will be prompted for the name of the directory that you 
want to install Bible4W in.  DO NOT enter the name of the directory that you 
currently are using to store your down-loaded files!!!!  If you do, the 
Install program will try to copy some of these files over themselves, and 
this may result in the files being deleted.  Type in a unique path name and 
click on the Enter button.  (Note: if the path that you enter does not 
currently exist, the Install program will attempt to create it for you.  
However, it can only create a new path that is one directory level deeper 
than a current directory path.  For example, if you type in 
c:\bible\windows\version1 , then the path c:\bible\windows must already 
exist.  Install will create only the \version1 sub-directory!)  Once Install 
has successfully assembled the files in the new directory, it will add a 
Program Group titled "Bible" to your Program Manager window and store a copy 
of the Bible4W icon there.  When this is complete, a small dialog box will 
be displayed indicating that the installation is complete.  Click on the OK 
button and you're done!  However, you still have an additional copy of the 
Bible4W install files on your hard disk that you no longer need.  Before you 
delete the expanded "install" files on your hard disk (i.e., the files in 
"download" directory mentioned above) you may wish to use them to make a set 
of installation floppy disks that you could use not only as a backup of you 
hard disk copy, but also to share the program with your friends.  To do 
this, you will have to format a set of floppies, and then copy the files one 
at a time (using either the DOS "copy" command or the Windows File Manager) 
to the floppies.  Make sure that you copy the files to the floppies 
indicated at the beginning of the Installation Instructions section above.  
If you put a file on the wrong floppy disk, the install program will still 
work, but it will prompt for the wrong disk when it cannot find the file it 
is looking for on the floppy currently in the drive.


Installing From Diskettes:

If you are not already in Microsoft Windows, start it up now.  The Bible4W 
Install program cannot be run from the DOS prompt.  It is a "Windows 
Application" program, and requires Windows to run.

Insert the first diskette into your floppy drive.  From your Windows 
desktop, open up the Program Manager program and pull down the "File" menu.  
Select "Run" from the "File" menu.  Type in the full path (drive letter and 
sub-directory name) and file name (i.e., a:\INSTALL.EXE ) of the Bible4W 
Install program and click on the Enter button.  You will be prompted for the 
name of the directory that you want to install Bible4W in.  Type in a unique 
path name (make sure that you use the drive letter for your hard disk, and 
not that of your floppy drive) and click on the Enter button.  (Note: if the 
path that you enter does not currently exist, the Install program will 
attempt to create it for you.  However, it can only create a new path that 
is one directory level deeper than a current directory path.  For example, 
if you type in c:\bible\windows\version1 , then the path c:\bible\windows 
must already exist.  Install will create only the \version1 sub-directory!)  
The Install program will tell you when you should insert the remaining 
diskettes.  Once Install has successfully assembled the files in the new 
directory, it will add a Program Group titled "Bible" to your Program 
Manager window and store a copy of the Bible4W icon there.  When this is 
complete, a small dialog box will be displayed indicating that the 
installation is complete.  Click on the OK button and you're done!


Installing From a CD ROM Flat File:

If you received Bible4W on a CD ROM, and have determined that the program is 
stored in a flat file format (see the section above titled "Received Bible4W 
on CD ROM:" for how to determin the storage format used by the CD ROM), then 
you have the option of either running Bible4W directly from the CD ROM, or 
copying the program to your hard disk.  The advantage of running directly 
from your CR ROM is that you will save the over 4,300,000 Bytes of storage 
space required to save Bible4W on your hard disk.  The current state-of-the-
art 5 inch CD ROM drives transfer data to yout computer at a rate slightly 
faster than the original PC XT hard disk.  If your PC is a 286 ( i.e., IBM 
AT or AT clone) or better, then your hard disk is probably several time 
faster than your CD drive.   Therefore, you will find that Bible4W will run 
significantly faster if you install it on your hard disk (especially when 
doing word searches).  If you are using a PC XT (or XT clone), you will 
probably still want to copy Bible4W to your hard disk.  When running on a XT 
class machine, the software required to support your CD ROM drive is 
significant compared to the total amount of memory on your machine.  With 
your CD ROM driver software loaded, you may not have enough memory left to 
run Bible4W, much less both Bible4W and you favorite word processing 
program.

When installing Bible4W from a CD ROM flat file, you CANNOT use the Bible4W 
Install program!  You must do it manually.  The following description 
assumes that you are running version 3.1 of Windows or Windows NT.  If you 
are running a different version, please check your Windows documentation for 
the correct procedure.

If you want to run Bible4W directly from the CD ROM disk, insert the CD ROM 
into your drive and if you are not already in Microsoft Windows, start it up 
now.  From Program Manager, pull down the File menu and select "New...".  A 
small dialog box titled "New Program Object" will appear.  If the small 
circle next to the text that reads "Program Group"  does not have a black 
dot in it, click on the circle with your mouse.  Next, click on the button 
labelled "OK".  A dialog box titled "Program Group Properties" will appear.  
In the box next to "Description:" enter a unique group name, for example 
"Bible Programs" and then click on the "OK" button.  At this point the 
Program Manager will create a new Group Child Window with your description 
on the title bar, but otherwise empty.  If you have any other Group Child 
Windows displayed at this time, the title bar of the new one will be a 
different color.  This Child Window is said to "have the focus" in Windows 
lingo.  If you were to click you mouse on any of the other Child Windows or 
Icons displayed by Program Manager at this point, the focus will change to 
that Window or Icon.  With the focus still set to your new Group Child 
Window, once again pull down the File menu and select "New...".  Notice that 
when the "New Program Object" dialog box appears this time, the black dot is 
in the circle labelled "Program Item".  Leave it there and click on the "OK" 
button.  This time a larger dialog box titled "Program Item Properties" will 
be displayed.  Click on the button labeled "Browse...".  A dialog box titled 
"Browse" will open.  On the left side of this dialog box there will be a 
list of file names, a directory tree will be displayed near the center, and 
below that a box with a disk drive icon accompabied by the disk drive letter 
and name of one of the drives on your system.  The directory tree and drive 
designation will probably be pointing to the directory and drive which 
contain the Windows operating system files.  First, click the down pointing 
arrow immediately to the right of the "Drives:" box.  This will cause a 
Windows "List Box" to be displayed.  Locate your CD drive in this list using 
the scroll bars if necessary.  When you click on the icon or name of your CD 
drive, several changes will be made to the Browse dialog box.  First, the 
list box will disapear, and your CD drive icon and name will be displayed in 
the "Drives:" box.  In addition, the "Directories:" box will display the 
directory tree of your CD ROM, and the file list will display the executable 
files in one of the directories on your CD ROM (usually the root directory).  
Double clicking on the little file folder icons displayed in the directory 
tree in the "Directories:" box will cause the executable files in that sub-
directory to be displayed in the file list.  The current sub-directory being 
displayed is indicated by a file folder icon that is open and darker than 
any of the other open folder icons.  Traverse the directory tree on your CD 
ROM until you find the sub-directory containing Bible4W.  When you find it, 
the file name "bible4w.exe" ( and possibly also "install.exe") will be 
displayed in the file list.  Double click on "bible4w.exe" in the file list 
box.  The browse dialog box will disapear, and you will be back at the 
"Program Item Properties" dialog box.  Notice, however, that the full path 
and file name of the bible4w.exe file has been inserted into the box labeled 
"Command Line:".  Click on the "OK" button with your mouse.  A message box 
will be displayed warning you that the file that you are pointing to (i.e., 
the bible4w.exe file on your CD ROM) may not be available during later 
Windows sessions, and asking if you want to continue.  Click on the "Yes" 
button.  The Bible4W installation is now complete.  Whenever you want to run 
Bible4W, just double click on the Bible4W icon that you have just installed 
using Program Manager.  Note, however, that you must be sure to have the CD 
ROM containing Bible4W loaded in your CD drive (and the CD drive turned on) 
whenever you use the program.  If you don't, Windows will display an error 
message stating that the "working directory is invalid" .

If you received Bible4W in the form of a CD ROM flat file, and you want to 
install Bible4W on your hard disk do the following:  Insert the CD ROM into 
your drive and if you are not already in Microsoft Windows, start it up now.  
The first thing that you need to do is to copy the Bible4W program, help, 
and King James text database files from the CD ROM to your hard disk.  The 
easyest way to do this is to use File Manager.  First, create a new sub-
directory on your hard disk to copy the Bible4W files into.  From File 
Manager, pull down the File menu and select "Create Directory...".  A small 
dialog box titled "Create Directory" will appear.  If the box labeled 
"Name:", type in the full path of the sub-directory that you want to create.  
For example: "c:\bible4w" (do not include the quote marks).  Next, click on 
the "OK" button.  If there are currently no Child Windows being displayed 
within the File Manager Window (i.e., they have all been shunk to icons, 
either restore one of the icons, or create a new Child window by pulling 
down the "Window" menu and selecting "New Window".  If the disk drive 
containing the sub-directory that you just created is not currently 
displayed in the Child Window, click on the disk drive icon on the button 
bar which represents that drive.  If the sub-directory name is not displayed 
in the directory tree, scroll the tree until it is.  Next, create another 
new Child window by pulling down the "Window" menu and selecting "New 
Window" once again.  You should see a CD ROM icon somewhere on the disk 
drive button bar.  It will look like a CD drive with a tiny CD ROM disk 
hanging half out of the drive.  Click on the CD drive button with your mouse 
to bring up a directory tree of the files on the CD ROM.  Browse through the 
files on the CD ROM until you find the Bible4W program.  Hopefully, the CD 
ROM publisher will have put all of the Bible4W files in a sub-directory of 
their own with an obvious directory name such as "BIBLE4W".  At this point, 
the right half of the Child Window will be displaying a list of the files in 
sub-directory that contains Bible4W.  Before proceeding on to the next step, 
arraing the two Child Windows (the one pointing to the directory that you 
are going to move the files to, and the one that displays the CD ROM files) 
so that you can see both the folder icon representing the sub-directory on 
your hard disk that you wish to copy Bible4W into, and also the file list of 
the sub-directory on the CD ROM that contains Bible4W.  In the CD ROM file 
list, click once on the file "bible4w.exe".  It will become highlighted.  
Next, with one hand press and hold down the control key (usually labled 
"Ctrl") on your keyboard, while with your other hand, use your mouse to 
click on the "bible4w.hlp" file.  Now both the bible4w.exe file and the 
bible4w.hlp file should be highlighted.  Repeat this two handed sequence to 
select the "kjb2p0.dat" file.  At this point all three file should be 
highlighted.  Finally, use a "click and drag" gesture to move the selected 
files to your hard disk.  To do this, move the mouse cursor over one of the 
files to be moved.  Be carfull not to press any mouse buttons.  When the 
cursor is possisioned, press down the left mouse button and hold it down.  
Without lifting your finger from the mouse button, move the mouse cursor 
until it is directly over the name or icon of the hard disk sub-directory 
that you are moving the files into.  You will notice that the cursor will 
change as you bigin to move the mouse, and that when it is over the sub-
directory that you want to deposit the files in,  a box will be drawn around 
the icon and name.  When the correct hard disk sub-directory is enclosed by 
the box, release the left mouse button.  Normally, a message box titled 
"Confirm Mouse Operation" will be displayed asking you to confirm that you 
want to copy the selected files (however, this confimation message may have 
been disabled from the Options menu in File Manager).  Click on the "Yes" 
button, and the files will be copied to your hard disk.  When the file copy 
operation completes, you may close the File Manager and remove the CD ROM 
from your CD drive.  Finally, you will want to set up your Program Manager 
so that you can execute Bible4W by clicking on a Program manager icon.  The 
previous paragraph explains how to do this when setting up the Program 
Manage to execute Bible4W directly from the CD ROM.  Follow the same 
procedure to set up Program Manager to execute you hard disk copy of 
Bible4W, only be sure that you are browsing you hard disk when you select 
the "bible4w.exe" file, and not your CD ROM.  By removing the CD ROM from 
your drive before you begin the Program Manager setup procedure, you will be 
unable to make this mistake.


Running Bible4W:


To run Bible4W, simply double click on the Bible4W icon displayed in the 
Program Manager.  For additional information on Bible4W commands, select 
"Help" from within the program.  



Terms of Use:


Bible4W is copyrighted by Nehemiah Ministries, Incorporated.  The terms of 
your license to use Bible4W are as follows:

1.	 You may use Bible4W for any purpose you wish, as long as you use it
for the glory of God.

2.	 You may not sell Bible4W, but may distribute it freely to anyone you 
wish. You do not need permission to distribute it - just do so.  All 
commercial and retail rights are reserved by the copyright holder.  Those 
distributing Bible4W may request a charge not exceeding $5 a disk, to 
cover costs.  If you are a shareware distributor, please send Nehemiah 
Ministries a letter indicating that you are distributing Bible4W.  If you 
do so, Nehemiah Ministries will include your name, address, and pertinent 
price information in the appendix at the end of this README file.

3.	 You may not distribute copies of Bible4W that have been added to or 
altered in anyway, without written permission.  When requesting such 
permission, you must send Nehemiah Ministries a copy of your changes for 
approval.

See the appendix for more information about distributing Bible4W.

If you find Bible4W useful, consider making a donation to your favorite 
evangelical organization.  If you do not have one, please give a gift to the 
Gideons.  Please be generous.  The development costs of Bible4W are 
underwritten by Nehemiah Ministries Inc.

For Additional Help...
If you have any problems or suggestions, please contact us.  Your 
constructive criticism, prayers, and letters of encouragement will be 
greatly appreciated.

Please mail any correspondence to:

Nehemiah Ministries
P. O. Box 46964
Seattle, Wa. 98146

You wish, you can leave an electronic message at El Shaddia Bulletin Board 
(206) 941-5282, by sending it to me, John Kuras.  (Please be patient in 
waiting for a reply... I usually log onto the Bulletin board only once every 
few weeks!)  Note: The El Shaddia SysOp has set up a special conference area 
for Bible4W.  You may be able to get the help that you need quicker by 
posting an open message there first!


King James Bible Notes

Please notify Nehemiah Ministries of any errors you find in the text.  The 
following deviations from the King James text are known:

1.	 Proper names are not hyphenated.  This was done to simplify searching 
for names. Some words still contain hyphens, e.g. God-ward, us-ward, you-
ward and so forth.

2.	 Embedded capitals are not consistently used.  The following two words, 
Aenon and Aeneas, should properly be AEnon and AEneas, but are 
represented without the embedded capitals in Bible4W.  On the other hand, 
EleloheIsrael and MeribahKadesh are represented properly.

3.	 Unfortunately, due to a programming bug, the proper name "God" is not 
consistently capitalized.  Searching on the word "God" will correctly 
display only the verses where His proper name is used in the King James.  
However, note that His name is often in lower case when it is displayed 
in the Bible4W text window.  This will be fixed in a future version of 
the program.




Appendix

Supplier List:

As of the release date of version 1.1 of Bible4W, the following firms have 
agreed to distribute program disks:

1.   Shorewood Christian School
     Attn.   Larry Clemons
     10300 28th Ave. S.W.
     Seattle, Wa. 98146
     (206) 932-0186
     Make check or money order out to:..... Shorewood Christian School
     set of four 1.2MB disks................................... $20.00
     set of twelve 360KB disks................................. $25.0



Acknowledgements:

Some of the wording for this readme file was adopted with the permission of 
Online Bible Ministries from the readme file provided with their Online 
Bible program.

Thanks to Larry Pierce for his encouragement and valuable insight into the 
problems associated with publishing Bible freeware.

Thanks to my boss for permitting me to write a Windows application for our 
use at work.  I would never have been able to learn enough on my own time to 
be able to complete this program before Windows becomes obsolete.  Thanks, 
Sam!

A special thank you to my wife Alyce, for her sacrifice and unbelievable 
patience.

And last but never least, thank you to our three year old son Cameron, who 
sacrificed many hours of playing with daddy to permit me to write this 
program.  Can I ever make it up to you?


                                                                                       
	John Kuras
                                                                                       
	President,
                                                                                       
	Nehemiah Ministries
 
Page 2

Readme.txt file for Bible for Windows version 1.1
10/09/92


Page 1
