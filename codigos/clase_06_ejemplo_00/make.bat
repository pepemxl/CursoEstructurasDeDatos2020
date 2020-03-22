@ECHO OFF
REM Limpiamos codigo objecto
del *.o
REM g++ -std=c++11 main.cpp -o run.exe
REM g++ -std=c++11 main.cpp lib1.cpp -o run.exe

g++ -std=c++11 -c main.cpp
g++ -std=c++11 -c lib1.cpp
g++ -std=c++11 -o run.exe main.o lib1.o 
