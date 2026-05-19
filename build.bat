@echo off
cd d:\computer_graphics
echo Compiling simple.cpp...
C:\msys64\ucrt64\bin\g++.exe simple.cpp -o simple.exe
echo Build status: %ERRORLEVEL%
if exist simple.exe (
    echo Executable created successfully
    simple.exe
) else (
    echo Executable was not created
)
pause
