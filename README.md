# B4W1P3

The very first (as far as I know) Windows based bible program. It was orriginally called Bible for Windows, but Microsoft got all bent out of shape when early developers started using the term "Windows" in the name of their products. So, its name was changed to Bible4w. Development originally started on Windows 2.1, but by the time it was released, Windows 3.0 was out. This was pre-Internet, kiddies. Release was by uploading to a BBS:)

Yes, that's right, this is all 16 bit code! It will run under Windows 2.1 (we really did write Windows code to run in real mode... Ah, such fond memories (not!)... dealing with NEAR and FAR pointers, waiting a couple seconds for a menu to paint, the romantic clacking of the MFM hard drive, three finger solutes when it froze up (if you were lucky, otherwise it was big red switch time!). It also ran in real or protected modes on Win 3.0, protected mode on 3.1, 3.11, pen Windows, Win 95, 98, Win NT, Win2k, XP(32 bit only). I think it may have been tested on O/S 2 as well, but my memory is cloudy. I just checked, and yes, it will still run under wine on 64 bit linux!

Unfortunately, I don't have a paid account on github, so I can't upload the exe file. Will it still compile? I hope so! If you want to compile it, you'll probably need to run an old version of Windows on an virtual machine - I don't think real mode code will run on modern hardware with UEFI booting. You'll need something with a BIOS. You'll also need a 16 bit compiler and the old 16 bit Windows SDK. I used to use Microsoft C version 6. Maybe MSVC98 will work? I don't know.... I suspect that anything later will require a lot of fixin.

The installer has a built in checksum of the files. (This was before anti-virus software.) Unfortunately, uploaded BBS code got infected by viruses so fast, that most of the copies of b4w that were available for download would not install! The installer saves the checksum in the file's time tag. You'll probably need to disable this feature (or avoid the installer completely!). The source for the installer is located here: https://github.com/dad98253/B4W1P3_INSTALL

Have fun!

P.s.,
The code was originally copyrighted in my name and/or a non-profit that I formed called "Nehemiah Ministries". I have since removed the copyright. As far as I (the author) am concerned, this code is now public domain. I'm pretty sure that the King James text that the program serves up is also public domain (but, I'm not a lawyer).

BTW, this was my very first C program as well as my first Windows program; so please be kind:)
