@echo off

pushd %~dp0\..\ 
call vendor\premake\bin\premake5.exe vs2022
call vendor\premake\bin\premake5.exe export-compile-commands
popd
PAUSE
