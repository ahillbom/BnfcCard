@echo off
git rev-parse HEAD > "..\temp.txt"
set /p GITVER=<"..\temp.txt"
del "..\temp.txt"
echo #define GIT_VERSION  "%GITVER%" > "..\gitversion.h"