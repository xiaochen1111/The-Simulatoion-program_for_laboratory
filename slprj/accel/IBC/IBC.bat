@echo off
set MATLAB=C:\Program Files\Polyspace\R2021a
"%MATLAB%\bin\win64\gmake" -f IBC.mk  OPTS="-DTID01EQ=0"
