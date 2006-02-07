Miraledon

(c) 1996-2006 Gerrit M. Albrecht

Miraledon is a class library which provides centrally
maintained MFC classes which may freely be used in own projects.
The license is the LGPL.

To use these classes just add the needed and all depending classes
together with their header files to your project. Then add the path
to the right headers directory as additional include directory.
This is the simplest way.

However, you can also build an own Miraledon DLL. This is a true
MFC extension DLL and only works together with MFC applications.
Because of the living sources which may change from time to time,
I would suggest to rename the DLL (just add a version number)
so that your application will work even if the system provides
a newer file.
