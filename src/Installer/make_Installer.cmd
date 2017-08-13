REM @echo off

PUSHD %1

DIR

REM This script needs NSIS and plugins installed into it's default localtion (e.g. C:\Program Files\NSIS)

REM Set this to the build output root (objs141) for the allegiance output files.
SET AllegianceDX7ObjsDir=..\..\objs14\FZRetail-DX7
SET AllegianceDX9ObjsDir=..\..\objs14\FZRetail

REM Remove Read-only/Archive flag from all files
REM Somehow this cased problems with build installer (crash during downloading filelist.txt/MotD)
REM I think it's a problem with TortoiseSVN, so this is just a dirty workaround
attrib -R -A /S *.*

REM Copy DX7 allegiance.exe from build output folder.
COPY /Y %AllegianceDX9ObjsDir%\Wintrek\Allegiance-DX9.exe Resources\Allegiance\Allegiance-DX9.exe

REM Copy DX7 allegiance.exe from build output folder.
COPY /Y %AllegianceDX7ObjsDir%\Wintrek\Allegiance-DX7.exe Resources\Allegiance\Allegiance-DX7.exe
COPY /Y %AllegianceDX7ObjsDir%\Wintrek\FreeImage.dll Resources\Allegiance\FreeImage.dll
COPY /Y %AllegianceDX7ObjsDir%\Wintrek\steam_api.dll Resources\Allegiance\steam_api.dll
COPY /Y %AllegianceDX7ObjsDir%\Wintrek\steam_appid.txt Resources\Allegiance\steam_appid.txt
REM COPY /Y %AllegianceObjsDir%\Reloader\Reloader.exe Resources\Allegiance\Reloader.exe

REM Run from 32 bit systems default location
if EXIST "%ProgramFiles%\NSIS\makensis.exe" "%ProgramFiles%\NSIS\makensis.exe" Allegiance.nsi

REM Run from 64 bit systems default location
if EXIST "%ProgramFiles(x86)%\NSIS\makensis.exe" "%ProgramFiles(x86)%\NSIS\makensis.exe" Allegiance.nsi

POPD

REM Don't close the window automaticly, if finished.
pause

