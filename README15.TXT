                             Table of Contents
Table of Contents                               1
Abstract:                                       2
System Requirements for version 1.3:            2
Installation Instructions:                      3
Installing a Copy Down-Loaded From a BBS:	5
Installing From Diskettes:                      6
Installing From a CD ROM Flat File:             7
Running Bible4W:                                8
Installing and Running Bible4W Over a Network:	8
Terms of Use:                                   8
For Additional Help...                         10
King James Bible Notes                         11
Appendix                                       12
Supplier List:                                 12
Acknowledgements:                              13



Abstract:
Bible4W (formerly called Bible for Windows) is a simple no frills electronic 
bible program.  It can look up text by Book-Chapter-Verse and then scroll 
through the text.  Verses can be selected and copied to the Windows 
clipboard for use in a word processor.  It can also be used as an electronic 
concordance.  It is fast enough to run on even the slowest Windows machine.  
Liberal use is made of the hyper-text Windows Help utility to provide on-
line documentation.

This version has been tested for use with Microsoft Windows versions 3.1 and 
Microsoft Windows for Workgroups 3.1.  In addition, the program can be run 
in 16 bit mode on Windows NT version 3.1, and will also be able to do the 
same on Windows 4.0 when it is released.  A previous version (version 1.2) 
is available which is compatible with Microsoft Windows versions 3.0 
(standard and enhanced modes), Microsoft Pen Windows version 3.1, J-Windows 
(Japan) version 3.0, and OS/2 version 2.0.  Another previous version 
(version 1.1) is available which will run under Windows 3.0 in real mode and 
in the OS/2 1.x compatibility box (running Windows 3.0).  In addition, an 
alternative version (version 1.2NT) is available which has been compiled in 
32 bit mode to run on Windows NT.

Note:  Although this version (1.3) retains the "Pen Aware" features (i.e., 
the program automatically detects when it is being run on a Pen Windows 
system, and will use modified dialog boxes for Bible4W's "Find..." and "Go 
To..." commands) of the previous Bible4W version, the pen specific 
capability has not been re-tested since the version 1.2 release.  These 
features are provided "as is".  I welcome any news regarding whether or not 
they are still operable!  The modified dialog boxes use handwriting 
recognition edit boxes rather than the standard Windows edit boxes.  A 
custom dictionary (file custdict.dll) is included.  It is used by the Pen 
Windows handwriting recognition routine to help identify the names of the 
books of the Bible and the words used in the Bible.  (The standard Microsoft 
dictionary does not include words like "escapeth" and "Abelmeholah"!)
System Requirements for version 1.3:

- IBM [386]PS/2 or 386 compatible with 2M RAM (or more)

- supports monochrome or color monitors

- hard disk with 4.5MB available unused space 
  ( 9.0MB to install from files down-loaded from a BBS )

- a 1.2MB or a 360KB floppy disk drive
  ( when installing from floppy disks )

- Microsoft Windows version 3.1 or later
	or
  Windows NT version 3.1

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
help, and installation files, two dynamic link library files (custdict.dll 
and muscroll.dll) plus the first three King James text database files 
(kjb2p0.dat, kjb2p0.da2, and kjb2p0.da3).  The next two diskettes will 
contain the King James text database files (kjb2p0.da4, kjb2p0.da5, ... thru 
kjb2p0.da9), three per diskette.  The last diskette will contain the 
remaining two database files (kjb2p0.d10, and kjb2p0.d11) and the 
Bible4W.exe program file.

Note to Windows/NT users:  Although the 16 bit version of Bible4W will run 
under Windows/NT, the Bible4W Install program will not.  If you want to run 
the 16 bit version of Bible4W on Windows/NT, you will have to find a way to 
install the program files from a DOS based (i.e., true 16 bit Windows) 
machine, and then either move the files over to your Windows/NT system, or 
access Bible4W through a network connection directly from the DOS machine.  
However, for the best performance, Windows/NT users should obtain a copy of 
Bible4W version 1.2NT.  This version of Bible4W (and the Install program 
that comes with it) runs in Windows/NT's native 32 bit mode.

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

              appsetup inf      ???? 06-06-93  ??:???
              bible4w  exe    297472 06-06-93  15:58p
              bible4w  hlp     22259 06-05-93  18:61p
              custdict dll      8000 06-05-93   3:43a
              install  exe     39968 01-19-92  12:51p
              kjb2p0   dat    362496 09-07-91  15:15p
              kjb2p0   da2    362496 09-07-91  14:50p
              kjb2p0   da3    362496 09-07-91  16:38p
              kjb2p0   da4    362496 09-07-91   2:43p
              kjb2p0   da5    362496 09-07-91   8:48a
              kjb2p0   da6    362496 09-07-91  19:59p
              kjb2p0   da7    362496 09-07-91  14:54p
              kjb2p0   da8    362496 09-07-91   1:41p
              kjb2p0   da9    362496 09-07-91   8:55p
              kjb2p0   d10    362496 09-07-91   9:56a
              kjb2p0   d11    275968 09-07-91   3:56p
              muscroll dll     10240 05-30-93  18:13p
              readme   txt      ???? 06-06-93  ??:???

NOTE:  All CD ROM versions which are distributed in flat file format will 
probably be missing the KJB2P0.DAn and KJB2P0.Dnn files (where n is a 
number).  In this case, the KJB2P0.DAT file will be 3900928 Bytes long and 
have a date of 08/04/90, and a time tag of 07:56am.


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
delete the "install" files on your hard disk (i.e., the files in "download" 
directory mentioned above) you may wish to use them to make a set of 
installation floppy disks that you could use not only as a backup of you 
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
required to save Bible4W on your hard disk.  However, many current 5 inch CD 
ROM drives transfer data to your computer at a rate that is considerably 
slower than that of your hard disk.   Therefore, you will find that Bible4W 
will run significantly faster if you install it on your hard disk 
(especially when doing word searches).

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
over a network, be aware that only the Bible4W program is "network 
aware".  The Bible4W install program is not!  When running over a 
network, certain situations can arise that are not possible on a 
single user workstation.  The most common problem is when the a 
network connection between a client and server is broken while the 
client is accessing files on the server.  A "network aware" program 
will detect this situation, and fail gracefully.  If you are 
installing the Windows NT version of Bible4W over a network, and the 
network connection is broken, a cryptic "Application Error" message 
will be displayed, and the install program will die.  If you are 
installing Bible4W on a 16 bit network product (such as Windows for 
Workgroups) and the network connection is broken, your machine will 
hang and you may be forced to re-boot!

Terms of Use:


Bible4W is owned and copyrighted by John C. Kuras and is protected by United 
States copyright laws and international treaty provisions.  The terms of 
your license to use Bible4W are as follows:

1.	 You may use Bible4W for any purpose you wish, as long as you use it for 
the glory of God.

2.	 You may distribute Bible4W freely to anyone you wish. You do not need 
permission to distribute it - just do so.  No commercial or retail rights 
are reserved by the copyright holder.  Those distributing Bible4W are 
permitted to request a reimbursement over and above their costs incurred 
in the distribution of the product.  If you are a shareware distributor, 
please send Nehemiah Ministries a letter indicating that you are 
distributing Bible4W.  If you do so, Nehemiah Ministries will include 
your name, address, and pertinent price information in the appendix at 
the end of this README file.

3.	 You may not distribute copies of Bible4W that have been added to or 
altered in anyway without written permission.  When requesting such 
permission, you must send Nehemiah Ministries a copy of your changes for 
approval.  An unaltered copy of this README.TXT file (or a modified copy 
thereof which has been approved by Nehemiah Ministries) must be included 
with all copies of Bible4W.

4.	You may not rent or lease this software.  However, you may duplicate or 
transfer the software and its accompanying files subject to the 
conditions set forth in this agreement.  You may not reverse engineer, 
decompile, or disassemble the software.  You are also not permitted to 
publish or provide such information to others.

5.	"Bible4W" is a trademark of John C. Kuras.  Prior to January 1, 1994, 
"Bible4W" and "Bible for Windows" were trademarks of Nehemiah Ministries, 
Inc.  The previous name for this product, "Bible for Windows", was 
changed per Microsoft's published request at the July 1992 Windows/NT 
Developers Conference.  This name change does not imply agreement with 
Microsoft's claim regarding the use of the term "Windows" in non-
Microsoft products and trademarks.

6.	These files are provided "as is", and no warranty of any kind is 
provided.  Standard good programming and testing practices have been 
employed to attempt to assure bug free operation of the programs.  
However, as with all software products, there can be no guarantee that 
programming bugs do not continue to exist in the final product.  Use of 
this software implies acceptance of the following warranty disclaimers:

	NO OTHER WARRANTIES:  To the maximum extent permitted by applicable laws, 
John Kuras and Nehemiah Ministries disclaim all warranties, either 
expressed or implied, including, but not limited to, implied warranties 
of merchantability and fitness for a particular purpose, with regard to 
the software, the accompanying files, and any accompanying hardware.  
This limited warranty gives you no specific legal rights.  You may have 
others which vary from jurisdiction to jurisdiction.

	NO LIABILITY FOR CONSEQUENTIAL DAMAGES:  To the maximum extent permitted 
by applicable laws, in no event shall John Kuras or Nehemiah Ministries 
be liable for any damages whatsoever (including, without limitation, 
damages for loss of business profits, business interruption, loss of 
business information, or any other pecuniary loss) arising out of the use 
of or inability to use this product, even if John Kuras or Nehemiah 
Ministries have been advised of the possibility of such damages.  Because 
some jurisdictions do not allow the exclusion or limitation of liability 
for consequential or incidental damages, the above limitation may not 
apply to you.

	U.S. GOVERNMENT RESTRICTED RIGHTS:  The software and accompanying files 
are provided with restricted rights.  Use, duplication, or disclosure by 
the Government is subject to restrictions as set forth in subparagraph 
(c)(1)(ii) of The Rights in Technical Data and Computer Software clause 
at DFARS 252.227-7013 or subparagraphs (c)(1) and (2) of the Commercial 
Computer Software--Restricted Rights 48 CFR 52.227-19, as applicable.  
The Manufacturer is John C. Kuras/140 Brakel Ln./Media PA 19063.

	If this product is acquired in the United States, this Agreement is 
governed by the laws of the State of Pennsylvania.  If you have any 
questions concerning this Agreement, or if you desire to contact John 
Kuras for any reason, please write:  John C. Kuras/140 Brakel Ln./Media 
PA 19063.



If you find Bible4W useful, please send $35 to:

John C. Kuras
140 Brakel Ln
Media, PA 19063

The development costs of Bible4W were underwritten totally by John C. Kuras.  
Your remuneration will be gratefully appreciated, and will help provide the 
resources necessary to continue maintaining and enhancing this product.  If 
you cannot afford the $35, then please remember us in your prayers.

For Additional Help...
If you have any problems or suggestions, please contact us.  Your 
constructive criticism, prayers, and letters of encouragement will be 
greatly appreciated.

Please mail any correspondence to:

John C. Kuras
140 Brakel Ln
Media, PA 19063

If you wish, you can leave an electronic message for John Kuras through 
Compuserve by sending e-mail to: [70062,3504], or through internet at: 
<70062.3504@compuserve.com>

Note: the SysOp of the El Shaddia Bulletin Board ((206)941-5282) has set up 
a special conference area for Bible4W.  You may be able to get the help that 
you need quicker by posting an open message there first!  I do not log onto 
Compuserve on a regular basis.
King James Bible Notes

Please notify John Kuras of any errors you find in the text.  The following 
deviations from the King James text are known:

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
the program.  (Note:  This is not a doctrinal statement of any kind!  It 
is a bug which will be hard for me to fix, so please be gracious!)




Appendix

Supplier List:

As of the release date of version 1.2 of Bible4W, the following firm has 
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
problems associated with publishing Bible shareware.

Thanks to my boss for permitting me to write a Windows application for our 
use at work.  I would never have been able to learn enough on my own time to 
be able to complete this program before Windows becomes obsolete.  Thanks, 
Sam!

A special thank you to my wife Alyce, for her sacrifice and unbelievable 
patience.

And last but never least, thank you to our five year old son Cameron, who 
sacrificed many hours of playing with daddy to permit me to write this 
program.  Can I ever make it up to you?


                                                                                       
	John Kuras
                                                April 1994



Readme.txt file for Bible for Windows version 1.2
04/21/94
