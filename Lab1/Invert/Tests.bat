set PROGRAM="%~1"
echo tests open

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err
echo test 1 passed

rem Во входном в файле обычная не вырожденная матрица ожидается нулевой код возврата
%PROGRAM% simple_input.txt "%TEMP%\output.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" simple_out.txt >nul
if ERRORLEVEL 1 goto err
echo test 2 passed

rem Во входном файле вырожденная матрица ожидается ненулевой код возврата
%PROGRAM% degen_matrix_in.txt "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
echo test 3 passed

echo OK
