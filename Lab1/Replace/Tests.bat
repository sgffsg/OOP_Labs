set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ������� ��� ��������
%PROGRAM% > nul
if ERRORLEVEL 1 goto err
echo test 1 passed

rem �������� �� ������ � ������ ����� ��������� ������� ��� ��������
%PROGRAM% "test-data\empty.txt" "%TEMP%\output.txt" bad good
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "test-data\empty.txt" >nul
if ERRORLEVEL 1 goto err
echo test 2 passed

rem � ������� � ����� ����������� ���������� ����� ��������� ������� ��� ��������
%PROGRAM% "test-data\input.txt" "%TEMP%\output.txt" normal good
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "test-data\input.txt" >nul
if ERRORLEVEL 1 goto err
echo test 3 passed

rem � ������� ����� ������������ ���������� ����� ��������� ������� ��� ��������
%PROGRAM% "test-data\input.txt" "%TEMP%\output.txt" bad good
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "test-data\input-replace-bad-with-good.txt" >nul
if ERRORLEVEL 1 goto err
echo test 4 passed

rem �������� �� ������������ ��������� ������� ��� ��������
%PROGRAM% "test-data\input_cycle.txt" "%TEMP%\output.txt" ma mama
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "test-data\input_cycle-replace-ma-with-mama.txt" >nul
if ERRORLEVEL 1 goto err
echo test 5 passed

rem ������-���� ��������� ������� ��� ��������
%PROGRAM% "test-data\input_more_a.txt" "%TEMP%\output.txt" a BB
echo test 6 passed

echo OK
exit 0

:err
echo Program testing failed
exit 1