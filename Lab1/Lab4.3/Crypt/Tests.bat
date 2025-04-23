@echo off

SET PROGRAM="%~1"

REM Run Program with 0, 1, 2, 3, 5 arguments
%PROGRAM% && goto err
echo Test 1 passed
%PROGRAM% crypt && goto err
echo Test 2 passed
%PROGRAM% crypt input.txt && goto err
echo Test 3 passed
%PROGRAM% crypt input.txt output.txt && goto err
echo Test 4 passed
%PROGRAM% crypt input.txt ouput.txt 20 excessArg && goto err
echo Test 5 passed

REM Invalid mode
%PROGRAM% invalid input.txt ouput.txt 2 && goto err
echo Test 6 passed

REM Key less min and more max acceptable value
%PROGRAM% crypt input.txt ouput.txt -1 && goto err
echo Test 7 passed
%PROGRAM% crypt input.txt ouput.txt 256 && goto err
echo Test 8 passed

REM Input file not found
%PROGRAM% crypt Missing.txt output.txt 2 && goto err
echo Test 9 passed

rem Output file can't open
%PROGRAM% crypt input.txt "./Crypt.exe" 20 || goto err
echo Test 10 passed

REM Input file empty
%PROGRAM% crypt Empty.txt "%TEMP%\output.txt" 2 || goto err
fc Empty.txt "%TEMP%\output.txt" > nil || goto err
echo Test 11 passed

REM Crypt and decrypt file with one line
%PROGRAM% crypt OneLine.txt "%TEMP%\output.txt" 2 || goto err
fc OneLine.txt "%TEMP%\output.txt" > nil && goto err
%PROGRAM% decrypt "%TEMP%\output.txt" "%TEMP%\output1.txt" 2 || goto err
fc OneLine.txt "%TEMP%\output1.txt" > nil || goto err
echo Test 12 passed

REM Crypt and decrypt file with many line
%PROGRAM% crypt ManyLines.txt "%TEMP%\output.txt" 20 || goto err
fc OneLine.txt "%TEMP%\output.txt" > nil && goto err
%PROGRAM% decrypt "%TEMP%\output.txt" "%TEMP%\output1.txt" 20 || goto err
fc ManyLines.txt "%TEMP%\output1.txt" > nil || goto err
echo Test 13 passed

rem Invalid decryption key
%PROGRAM% crypt OneLine.txt "%TEMP%\output.txt" 2 || goto err
%PROGRAM% decrypt "%TEMP%\output.txt" "%TEMP%\output1.txt" 3 || goto err
fc OneLine.txt "%TEMP%\output1.txt" > nil && goto err
echo Test 14 passed

echo All tests passed successfully
exit /B 0

:err
echo Tests failed
exit /B 1