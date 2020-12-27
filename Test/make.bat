@ECHO OFF
SET TEMP_PATH=../DS2020
g++ -std=c++11 -L%TEMP_PATH% CStack_unit_01.cpp -o CStack_unit_01.exe