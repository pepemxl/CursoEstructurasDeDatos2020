@ECHO OFF
REM busquen la ubicacion de su mingw y cambien el correspondiente PATH, correr como administrador
SET TEMP_PATH=C:\Program Files (x86)\CodeBlocks\MinGW\bin
COPY "%TEMP_PATH%\mingw32-make.exe" "%TEMP_PATH%\make.exe"