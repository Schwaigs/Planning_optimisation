cd src
if %*% == 3 (
    CALL main.exe %1 %2 %3
) else (
    CALL main.exe
)