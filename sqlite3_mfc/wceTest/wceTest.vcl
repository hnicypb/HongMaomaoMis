<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: wceTest - Win32 (WCE ARMV4) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"ARMV4Dbg/wceTest.res" /d UNDER_CE=420 /d _WIN32_WCE=420 /d "DEBUG" /d "UNICODE" /d "_UNICODE" /d "WCE_PLATFORM_STANDARDSDK" /d "ARM" /d "_ARM_" /d "ARMV4" /d "_AFXDLL" /r "S:\DevWork\Source\Win\CodeProj\SQLite3\wceTest\wceTest.rc"" 
Creating temporary file "C:\Temp\RSPFD.tmp" with contents
[
/nologo /W3 /GX /Zi /Od /Gf /I ".\\" /I "..\wince\sqlite3" /I "..\wince\wce_port" /I "..\Wrapper" /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "WCE_PLATFORM_STANDARDSDK" /D "UNICODE" /D "_UNICODE" /D "_AFXDLL" /Fp"ARMV4Dbg/wceTest.pch" /Yu"stdafx.h" /Fo"ARMV4Dbg/" /Fd"ARMV4Dbg/" /MC /c 
"S:\DevWork\Source\Win\CodeProj\SQLite3\Wrapper\DbSQLite.cpp"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wceTest\TestApp.cpp"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wceTest\TestDlg.cpp"
]
Creating command line "clarm.exe @C:\Temp\RSPFD.tmp" 
Creating temporary file "C:\Temp\RSPFE.tmp" with contents
[
/nologo /W3 /GX /Zi /Od /Gf /I ".\\" /I "..\wince\sqlite3" /I "..\wince\wce_port" /I "..\Wrapper" /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "WCE_PLATFORM_STANDARDSDK" /D "UNICODE" /D "_UNICODE" /D "_AFXDLL" /Fp"ARMV4Dbg/wceTest.pch" /Yc"stdafx.h" /Fo"ARMV4Dbg/" /Fd"ARMV4Dbg/" /MC /c 
"S:\DevWork\Source\Win\CodeProj\SQLite3\wceTest\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\Temp\RSPFE.tmp" 
Creating temporary file "C:\Temp\RSPFF.tmp" with contents
[
wceSQLite3.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"ARMV4Dbg/wceTest.pdb" /debug /out:"ARMV4Dbg/wceTest.exe" /libpath:"..\Lib" /subsystem:windowsce,4.20 /align:"4096" /MACHINE:ARM 
.\ARMV4Dbg\DbSQLite.obj
.\ARMV4Dbg\StdAfx.obj
.\ARMV4Dbg\TestApp.obj
.\ARMV4Dbg\TestDlg.obj
.\ARMV4Dbg\wceTest.res
]
Creating command line "link.exe @C:\Temp\RSPFF.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
DbSQLite.cpp
Unicode Selected
e:\msdev\evc4\sdk_420\include\armv4\xmemory(46) : warning C4291: 'void *__cdecl operator new(unsigned int,void *)' : no matching operator delete found; memory will not be freed if initialization throws an exception
        e:\msdev\evc4\sdk_420\mfc\include\wcealt.h(244) : see declaration of 'new'
        e:\msdev\evc4\sdk_420\include\armv4\xmemory(78) : see reference to function template instantiation 'void __cdecl std::_Construct(class CDbSQLite::ResultRecord *,const class CDbSQLite::ResultRecord &)' being compiled
TestApp.cpp
TestDlg.cpp
Generating Code...
Unicode Selected
Linking...




<h3>Results</h3>
wceTest.exe - 0 error(s), 1 warning(s)
</pre>
</body>
</html>
