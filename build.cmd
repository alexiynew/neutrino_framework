@ECHO off


REM Main script body
REM ==========================================
IF [%1] EQU [] (
    CALL :ERROR "Command expected."
) ELSE (
    FOR %%c IN (%*) DO (
       CALL :RUN_COMAND %%c 
    )
)
GOTO :eof


REM Main logic
REM ==========================================
:RUN_COMAND
SETLOCAL
    IF "%1" EQU "help" (
        CALL :HELP
        GOTO :eof
    )

    IF "%1" EQU "clean" (
        CALL :CLEAN
        GOTO :eof
    ) 

    IF "%1" EQU "build" (
        CALL :BUILD
        GOTO :eof
    )

    IF "%1" EQU "test" (
        CALL :TEST
        GOTO :eof
    )

    IF "%1" EQU "test_verbose" (
        CALL :TEST_VERBOSE
        GOTO :eof
    )

    CALL :ERROR "Unknown command '%1'."
    CALL :HELP
    GOTO :eof
ENDLOCAL


REM Command functions
REM ==========================================
:HELP
SETLOCAL
    CALL :INFO "Build script help."
    ECHO.
    ECHO Posible command are:
    ECHO.    help          - Show this help
    ECHO.    clean         - Clean build folders
    ECHO.    build         - Build framework and tests 
    ECHO.    test          - Run tests 
    ECHO.    test_verbose  - Run tests in verbose mode 

    GOTO :eof
ENDLOCAL

:CLEAN
SETLOCAL
    CALL :INFO " === Clean build. === "

    RD /Q /S .\build
    RD /Q /S .\output

    GOTO :eof
ENDLOCAL

:BUILD
SETLOCAL
    CALL :INFO " === Configure === "
    MD build
    CD build
    cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE="Debug" -DBUILD_TESTING=ON ../

    CALL :INFO " === Build framework === "
    cmake --build . --target framework

    CALL :INFO " === Build framework tests === "
    cmake --build . --target framework_tests

    CD ../
    GOTO :eof
ENDLOCAL

:TEST
SETLOCAL
    CALL :INFO " === Run tests === "
    CD build
    cmake --build . --target run_all_tests

    CD ../
    GOTO :eof
ENDLOCAL

:TEST_VERBOSE
SETLOCAL
    CALL :INFO " === Run tests verbose === "
    CD build
    cmake --build . --target run_all_tests_verbose

    CD ../
    GOTO :eof
ENDLOCAL


REM Helper functions
REM ==========================================
:INFO
SETLOCAL
    ECHO INFO: %~1
    GOTO :eof
ENDLOCAL

:ERROR
SETLOCAL
    ECHO ERROR: %~1
    GOTO :eof
ENDLOCAL
