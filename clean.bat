chcp 437

@echo off
setlocal

for /f "usebackq" %%a in (`dir /s /a /w /b ^| find /v /c ""`) do set "size_before=%%a"

del /f /s /q tempCodeRunnerFile.cpp
del /f /s /q a.out
del /f /s /q *.a
del /f /s /q *.o
del /f /s /q *.exe
del /f /s /q *.tmp
del /f /s /q *.dmp
del /f /s /q *.log
del /f /s /q *.temp

for /f "usebackq" %%a in (`dir /s /a /w /b ^| find /v /c ""`) do set "size_after=%%a"

set /a size_difference=size_after-size_before

echo The folder size has changed by %size_difference% bytes.

endlocal
pause