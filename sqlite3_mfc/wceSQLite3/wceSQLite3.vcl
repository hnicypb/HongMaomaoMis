<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: wceSQLite3 - Win32 (WCE ARMV4) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\Temp\RSPF6.tmp" with contents
[
/nologo /W3 /Gf /D "ARM" /D "_ARM_" /D "ARMV4" /D "NDEBUG" /D _WIN32_WCE=420 /D "WCE_PLATFORM_STANDARDSDK" /D UNDER_CE=420 /D "UNICODE" /D "_UNICODE" /D "_USRDLL" /D "WCESQLITE3_EXPORTS" /D "__CPLUSPLUS" /Fp"ARMV4Rel/wceSQLite3.pch" /YX /Fo"ARMV4Rel/" /O2 /MC /c 
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\alter.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\attach.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\auth.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\btree.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\build.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\callback.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\date.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\delete.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\expr.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\func.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\hash.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\insert.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\legacy.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\main.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\opcodes.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\os_unix.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\os_win.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\os_wince.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\pager.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\parse.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\pragma.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\prepare.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\printf.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\random.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\select.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\table.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\tokenize.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\trigger.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\update.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\utf.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\util.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\vacuum.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\vdbe.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\vdbeapi.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\vdbeaux.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\vdbemem.c"
"S:\DevWork\Source\Win\CodeProj\SQLite3\wince\sqlite3\where.c"
]
Creating command line "clarm.exe @C:\Temp\RSPF6.tmp" 
Creating temporary file "C:\Temp\RSPF7.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:no /pdb:"ARMV4Rel/wceSQLite3.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /def:"..\wince\sqlite3\sqlite3.def" /out:"ARMV4Rel/wceSQLite3.dll" /implib:"ARMV4Rel/wceSQLite3.lib" /subsystem:windowsce,4.20 /align:"4096" /MACHINE:ARM 
.\ARMV4Rel\alter.obj
.\ARMV4Rel\attach.obj
.\ARMV4Rel\auth.obj
.\ARMV4Rel\btree.obj
.\ARMV4Rel\build.obj
.\ARMV4Rel\callback.obj
.\ARMV4Rel\date.obj
.\ARMV4Rel\delete.obj
.\ARMV4Rel\expr.obj
.\ARMV4Rel\func.obj
.\ARMV4Rel\hash.obj
.\ARMV4Rel\insert.obj
.\ARMV4Rel\legacy.obj
.\ARMV4Rel\main.obj
.\ARMV4Rel\opcodes.obj
.\ARMV4Rel\os_unix.obj
.\ARMV4Rel\os_win.obj
.\ARMV4Rel\os_wince.obj
.\ARMV4Rel\pager.obj
.\ARMV4Rel\parse.obj
.\ARMV4Rel\pragma.obj
.\ARMV4Rel\prepare.obj
.\ARMV4Rel\printf.obj
.\ARMV4Rel\random.obj
.\ARMV4Rel\select.obj
.\ARMV4Rel\table.obj
.\ARMV4Rel\tokenize.obj
.\ARMV4Rel\trigger.obj
.\ARMV4Rel\update.obj
.\ARMV4Rel\utf.obj
.\ARMV4Rel\util.obj
.\ARMV4Rel\vacuum.obj
.\ARMV4Rel\vdbe.obj
.\ARMV4Rel\vdbeapi.obj
.\ARMV4Rel\vdbeaux.obj
.\ARMV4Rel\vdbemem.obj
.\ARMV4Rel\where.obj
]
Creating command line "link.exe @C:\Temp\RSPF7.tmp"
<h3>Output Window</h3>
Compiling...
alter.c
attach.c
auth.c
btree.c
build.c
callback.c
date.c
delete.c
expr.c
func.c
hash.c
insert.c
legacy.c
main.c
opcodes.c
os_unix.c
os_win.c
os_wince.c
pager.c
parse.c
pragma.c
prepare.c
printf.c
random.c
select.c
table.c
tokenize.c
trigger.c
update.c
utf.c
util.c
vacuum.c
vdbe.c
vdbeapi.c
vdbeaux.c
vdbemem.c
where.c
Linking...
   Creating library ARMV4Rel/wceSQLite3.lib and object ARMV4Rel/wceSQLite3.exp




<h3>Results</h3>
wceSQLite3.dll - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
