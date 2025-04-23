set PROGRAM="%~1"

REM ������������� &&:
REM ���� command1 ���������� �������, ��������� �������� � ����� success.
REM ���� command1 ���������� � �������, ��������� �� ��������, � ������ ����� �������� ��������� �������.

REM ������������� ||:
REM ���� command1 ���������� � �������, ����� �������� ������� � ����� error.
REM ���� command1 ���������� �������, ��������� ��������� �������� goto error �� ����������.


REM Arguments Test 
echo Arguments Tests
%PROGRAM%
if NOT ERRORLEVEL 1 goto err
echo [1]/[7] Arguments Test - PASSED
%PROGRAM% "-h"
if NOT ERRORLEVEL 0 goto err
echo [2]/[7] Arguments Test - PASSED
%PROGRAM% test-data/input.txt
if NOT ERRORLEVEL 1 goto err
echo [3]/[7] Arguments Test - PASSED
%PROGRAM% test-data/input.txt "%TEMP%\output.txt" 
if NOT ERRORLEVEL 1 goto err
echo [4]/[7] Arguments Test - PASSED
%PROGRAM% test-data/input.txt "%TEMP%\output.txt" "search"
if NOT ERRORLEVEL 1 goto err
echo [5]/[7] Arguments Test - PASSED
%PROGRAM% test-data/input.txt "%TEMP%\output.txt" "search" "replace" 
if NOT ERRORLEVEL 1 goto err
echo [6]/[7] Arguments Test - PASSED
%PROGRAM% test-data/input.txt "%TEMP%\output.txt" "search" "replace" "another" 
if NOT ERRORLEVEL 1 goto err
echo [7]/[7] Arguments Test - PASSED


%PROGRAM% "test-data\empty.txt" "%TEMP%\output.txt" bad good
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "test-data\empty.txt" >nul
if ERRORLEVEL 1 goto err
echo test 5 passed


echo All tests passed successfuly
exit 0

:err
echo Tests failed
exit /B 1