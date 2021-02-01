Table of Contents
Abstract:	2
System Requirements:	2
Installation Instructions:	4
Installing a Copy Down-Loaded From a BBS:	6
Installing From Diskettes:	7
Installing From a CD ROM Flat File:	8
Running Bible4W:	9
Installing and Running Bible4W Over a Network:	10
Terms of Use:	11
For Additional Help...	11
King James Bible Notes	12
Appendix	13
Supplier List:	13
Acknowledgements:	14



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

- hard disk with 4.5MB available unused space 
  ( 9.0MB to install from files down-loaded from a BBS )

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
You should have 4 diskettes.  The first diskette will contain the Bible4W 
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
in BBS image format.  Follow the publisher's instructions for copying the 
files onto your hard disk, and then install the program as if you had 
downloaded the files from a BBS.  If the CD ROM instructions say that you 
can use the DOS "copy" command to move the files to your hard disk, or do 
not indicate how to read the CD ROM, then you will need to perform the 
following experiment to determine if the program is stored as floppy disk 
images, or as a flat file:  put the CD ROM in your CD drive, and open the 
Windows File Manager program.  You should see a CD ROM icon somewhere on the 
disk drive button bar.  It will look like a CD drive with a tiny CD ROM disk 
hanging half out of the drive.  Click on the CD drive button with your mouse 
to bring up a directory tree of the files on the CD ROM.  Browse through the 
files on the CD ROM until you find the Bible4W program.  Hopefully, the CD 
ROM publisher will have put all of the Bible4W files in a sub-directory of 
their own with an obvious directory name such as "BIBLE4W".  Look for a file 
in this directory named KJB2P0.DAT.  If its length is less than 3,900,000 
Bytes, then the files are stored as floppy disk images, and you will need to 
follow the instructions below for installing the program from floppy disks.  
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
              appsetup inf      ???? 10-10-92  ??:???
              bible4w  exe    290304 10-03-92   9:15a
              bible4w  hlp     22259 10-03-92   6:59a
              install  exe    112640 10-10-92   2:53p
              readme   txt      ???? 10-10-92  ??:???
              kjb2p0   dat    774144 07-24-91   6:46p
              kjb2p0   da2   1213952 07-24-91  12:20a
              kjb2p0   da3   1213952 07-24-91  12:40a
              kjb2p0   da4    698880 07-24-91   7:19a

NOTE:  All CD ROM versions (i.e., 16 or 32 bit) which are distributed in 
flat file format will probably be missing the KJB2P0.DAn and KJB2P0.Dnn 
files (where n is a number).  In this case, the KJB2P0.DAT file will be 
3900928 Bytes long and have a date of 08/04/90, and a time tag of 07:56am.


During the installation process, the Install program will be assembling 
these files onto your hard disk.  If you don't have an additional 4,500,000 
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
have an additional 4,500,000 Bytes of available space on you disk, don't 
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
on CD ROM:" for how to determine the storage format used on the CD ROM), 
then you have the option of either running Bible4W directly from the CD ROM, 
or copying the program to your hard disk.  The advantage of running directly 
from your CR ROM is that you will save the 4,500,000 Bytes of storage space 
required to save Bible4W on your hard disk.  However, the current state-of-
the-art 5 inch CD ROM drives transfer data to your computer at a rate 
slightly faster than the original PC XT hard disk.  If your PC is a 286 ( 
i.e., IBM AT or AT clone) or better, then your hard disk is probably several 
time faster than your CD drive.   Therefore, you will find that Bible4W will 
run significantly faster if you install it on your hard disk (especially 
when doing word searches).  If you are using a PC XT (or XT clone), you will 
probably still want to copy Bible4W to your hard disk.  When running on a XT 
class machine, the software required to support your CD ROM drive is 
significant compared to the total amount of memory on your machine.  With 
your CD ROM driver software loaded, you may not have enough memory left to 
run Bible4W, much less both Bible4W and you favorite word processing 
program.

When installing Bible4W from a CD ROM flat file, use the Bible4W Install 
program.  If you want to run Bible4W directly from the CD ROM disk, insert 
the CD ROM into your drive and if you are not already in Microsoft Windows, 
start it up now.  From Program Manager, pull down the File menu and select 
"Run" .  Type in the full path (drive letter and sub-directory name and file 
name, for example, S:\BIBLE4W\INSTALL.EXE) of the Bible4W Install program 
and click on the Enter button.  You will be prompted for the name of the 
directory that you want to install Bible4W in.  Enter the drive and path of 
the CD ROM directory which contains the install program (corresponding to 
the example used above, this would be S:\BIBLE4W).  You need not worry about 
the install program over-writing files on the CD, because it is a read-only 
device!   The Install program will add a Program Group titled "Bible" to 
your Program Manager window and store a copy of the Bible4W icon there.  
When this is complete, a small dialog box will be displayed indicating that 
the installation is complete.  Click on the OK button and you're done!

If you received Bible4W in the form of a CD ROM flat file, and you want to 
install Bible4W on your hard disk, follow the same steps outlined above for 
running from the CD ROM, only when the Bible4W Install program prompts you 
to enter the name of the directory that you want to install Bible4W in, 
specify a drive letter associated with your hard disk, and a sub-directory 
name.  The default used by the Install program is C:\BIBLE4W.  Click on the 
Enter button.  (Note: if the path that you enter does not currently exist, 
the Install program will attempt to create it for you.  However, it can only 
create a new path that is one directory level deeper than a current 
directory path.  For example, if you type in c:\bible\windows\version1 , 
then the path c:\bible\windows must already exist.  Install will create only 
the \version1 sub-directory!)  Once Install has successfully copied the 
files into the new directory, it will add a Program Group titled "Bible" to 
your Program Manager window and store a copy of the Bible4W icon there.  
When this is complete, a small dialog box will be displayed indicating that 
the installation is complete.  Click on the OK button and you're done!



Running Bible4W:


To run Bible4W, simply double click on the Bible4W icon displayed in the 
Program Manager.  For additional information on Bible4W commands, select 
"Help" from within the program.  




Installing and Running Bible4W Over a Network:


Although both Bible4W and its Install program will generally run fine 
over a network, be aware that neither of these programs are "network 
aware"!  When running over a network, certain situations can arise 
that are not possible on a single user workstation.  The most common 
problem is when the a network connection between a client and server 
is broken while the client is accessing files on the server.  A 
"network aware" program will detect this situation, and fail 
gracefully.  If you are running the Windows NT versions of either of 
the Bible4W programs over a network, and the network connection is 
broken, a cryptic "Application Error" message will be displayed, and 
the program will die.  If you are running either of these programs on 
a 16 bit network product (such as Windows for Workgroups) and the 
network connection is broken, your machine will hang and you may be 
forced to re-boot!  This problem will be corrected in a future release 
of Bible4W.




Terms of Use:


Bible4W is copyrighted by Nehemiah Ministries, Incorporated.  The terms of 
your license to use Bible4W are as follows:

1.	 You may use Bible4W for any purpose you wish, as long as you use it for 
the glory of God.

2.	 You may not sell Bible4W, but may distribute it freely to anyone you 
wish. You do not need permission to distribute it - just do so.  All 
commercial and retail rights are reserved by the copyright holder.  Those 
distributing Bible4W may request a charge not exceeding $5 a disk, to 
cover costs.  If you are a shareware distributor, please send Nehemiah 
Ministries a letter indicating that you are distributing Bible4W.  If you 
do so, Nehemiah Ministries will include your name, address, and pertinent 
price information in the appendix at the end of this README file.

3.	 You may not distribute copies of Bible4W that have been added to or 
altered in anyway without written permission.  When requesting such 
permission, you must send Nehemiah Ministries a copy of your changes for 
approval.

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

If you wish, you can leave an electronic message at El Shaddia Bulletin 
Board (206) 941-5282, by sending it to  John Kuras.  (Please be patient in 
waiting for a reply... I do not log onto the Bulletin board very often!)  
Note: The El Shaddia SysOp has set up a special conference area for Bible4W.  
You may be able to get the help that you need quicker by posting an open 
message there first!


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
 


Readme.txt file for Bible4W version 1.2
10/10/92






