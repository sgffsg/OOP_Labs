@echo off
SET PROGRAM="%~1"

REM Null Arguments
%PROGRAM% > nil && goto err
echo Test 1 passed

REM Input file is missing
%PROGRAM% Missing.txt > nil && goto err
echo Test 2 passed

REM Input file is empty
%PROGRAM% Empty.txt > nil && goto err
echo Test 3 passed


REM Matrix do not have row
%PROGRAM% MatrixWithoutRow.txt > nil && goto err
echo Test 4 passed
REM Matrix do not have one element
%PROGRAM% MatrixWithoutElt.txt > nil && goto err
echo Test 5 passed
REM Matrix element have no digit sybmol
%PROGRAM% MatrixWithNoDigitElt.txt > nil && goto err
echo Test 6 passed


REM Succes invert matrix
%PROGRAM% Matrix.txt > "output.txt" || goto err
fc CorrectInvertMatrix.txt "output.txt" > nil || goto err
echo Test 7 passed

REM Matrix do not have invert matrix
%PROGRAM% MatrixWithoutInvertMatrix.txt > "output.txt" || goto err
echo Non-invertible> "err.txt"
fc "err.txt" "output.txt" > nil || goto err
echo Test 8 passed

echo All tests passed successfully
exit /B 0

:err
echo Test failed
exit /B 1