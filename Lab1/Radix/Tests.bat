set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err
echo non argument test passed

rem При запуске со значением выше максимального ожидается нулевой код возврата
%PROGRAM% 10 36 2147483648 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
echo max int test passed

rem При запуске с отрицательным основанием ожидается нулевой код возврата
%PROGRAM% -10 -36 10 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
echo minus notation test passed

echo OK
exit 0

:err
echo Program testing failed
exit 1