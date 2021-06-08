cd src
set argC=0
for %%x in (%*) do Set /A argC+=1
if %argC% equ 3 (
    CALL main.exe %1 %2 %3
)
else (
    CALL main.exe
)