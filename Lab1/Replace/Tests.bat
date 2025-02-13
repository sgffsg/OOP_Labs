set PROGRAM="%~1"

rem При запуске без параметров ожидается нулевой код возврата
%PROGRAM% > nul
if ERRORLEVEL 1 goto err
echo test 1 passed

rem Проверка на замену в пустом файле ожидается нулевой код возврата
%PROGRAM% "test-data\empty.txt" "%TEMP%\output.txt" bad good
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "test-data\empty.txt" >nul
if ERRORLEVEL 1 goto err
echo test 2 passed

rem В входном в файле отсутствует заменяемое слово ожидается нулевой код возврата
%PROGRAM% "test-data\input.txt" "%TEMP%\output.txt" normal good
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "test-data\input.txt" >nul
if ERRORLEVEL 1 goto err
echo test 3 passed

rem В входном файле присутствует заменяемое слово ожидается нулевой код возврата
%PROGRAM% "test-data\input.txt" "%TEMP%\output.txt" bad good
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "test-data\input-replace-bad-with-good.txt" >nul
if ERRORLEVEL 1 goto err
echo test 4 passed

rem Проверка на зацикливание ожидается нулевой код возврата
%PROGRAM% "test-data\input_cycle.txt" "%TEMP%\output.txt" ma mama
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "test-data\input_cycle-replace-ma-with-mama.txt" >nul
if ERRORLEVEL 1 goto err
echo test 5 passed

rem Стресс-тест ожидается нулевой код возврата
%PROGRAM% "test-data\input_more_a.txt" "%TEMP%\output.txt" a BB
echo test 6 passed

echo OK
exit 0

:err
echo Program testing failed
exit 1