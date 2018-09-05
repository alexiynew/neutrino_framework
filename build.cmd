@ECHO off

REM =============================================================================
REM MIT License
REM
REM Copyright (c) 2017-2018 Fedorov Alexey
REM
REM Permission is hereby granted, free of charge, to any person obtaining a copy
REM of this software and associated documentation files (the "Software"), to deal
REM in the Software without restriction, including without limitation the rights
REM to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
REM copies of the Software, and to permit persons to whom the Software is
REM furnished to do so, subject to the following conditions:
REM
REM The above copyright notice and this permission notice shall be included in all
REM copies or substantial portions of the Software.
REM
REM THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
REM IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
REM FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
REM AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
REM LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
REM OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
REM SOFTWARE.
REM =============================================================================

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
