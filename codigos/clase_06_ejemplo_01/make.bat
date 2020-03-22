@ECHO OFF
REM del *.o
REM g++ -std=c++11 main.cpp -o run.exe
g++ -std=c++11 main.cpp Point.cpp Rectangle.cpp -o run.exe

REM g++ -c main.cpp
REM g++ -c Point.cpp
REM g++ -c Rectangle.cpp
REM g++ -std=c++11 -o run.exe main.o Rectangle.o Point.o
