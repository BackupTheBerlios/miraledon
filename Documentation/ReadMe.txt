Miraledon

(c) 1996-2006 Gerrit M. Albrecht

Miraledon is a class library which provides centrally maintained,
free MFC classes which may be used without restrictions in own projects.
All classes are designed to be as fast as possible. Every additions or
enhancements which change the standard look and feel are optional and
have to be explicitly switched on.

The license is the LGPL. Most classes have it's origin on websites
like CodeProject.com or CodeGuru.com. These sites do not force
their article writers to put their sources below a certain license.
So many authors only tell "it's free" or use no real license.
Some classes in this library are from such "free" sources. All of the
original classes are free for both, commercial and free projects so I
think we should have no problems including them here. If there where
restrictions (Copyright notices which have to be left unchanged in
the source or something similar) I respected them.

To use these classes you could copy the needed classes into your
project. Or you can just add the needed and all depending classes
together with their header files to your project. Then add the path
to the right headers directory as additional include directory.
This is the simplest, but not the best way.

The suggested way is the building of an own Miraledon DLL. This is a
true MFC extension DLL and only works together with MFC applications.
The sources does only compile and work with Visual Studio 2005 and at least
MFC 8.0. It is not planned to support older compilers. All you need to
use the Miraledon DLL is to add the Project to your Solution and add the
right Include directory (e.g. "..\..\Miraledon"). Then mark Miraledeon as
a dependency of your project.

To distribute the Miraledon DLL you can install your version into your
application directory. If you want to install Miraledon into the System DLL
directory, you have to ensure a conflict-free installation. It is enough
to rename inofficial DLLs. Just add the checkout date of your sources
(e.g. "miraledon-060228.dll"). So your application will work even if the
system provides another file. Official versions get a version number added
to the DLL name: "miraledon-1.0.dll". Do not use official names for
inofficial builds.
