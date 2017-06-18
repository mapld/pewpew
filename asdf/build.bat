@echo off
if not defined DevEnvDir (
    call vcvarsall.bat
)
call cl -Zi /EHsc -I C:\vs_dev_lib\lib\include src/*.cpp C:\vs_dev_lib\lib\x86\SDL2.lib C:\vs_dev_lib\lib\x86\SDL2main.lib /Fepewpew.exe /link /SUBSYSTEM:CONSOLE 