@echo off
set MATLAB=C:\Program Files\Polyspace\R2021a
"%MATLAB%\bin\win64\gmake" -f IBC1.mk  OPTS="-DTID01EQ=0"
