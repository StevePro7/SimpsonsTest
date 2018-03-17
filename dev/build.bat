@echo off
REM echo Execute bmp2tile
REM bmp2tile.exe raw\font.bmp -savetiles "font (tiles).psgcompr" -removedupes -tileoffset 0 -savetilemap "font (tilemap).bin" -savepalette "font (palette).bin"
REM bmp2tile.exe raw\splash.bmp -savetiles "splash (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 112 -savetilemap "splash (tilemap).stmcompr" -savepalette "splash (palette).bin"
REM bmp2tile.exe raw\simpsons.bmp -savetiles "simpsons (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 80 -savetilemap "simpsons (tilemap).stmcompr" -savepalette "simpsons (palette).bin"

REM bmp2tile.exe raw\tick.bmp -savetiles "tick (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "tick (palette).bin" -spritepalette
REM bmp2tile.exe raw\cross.bmp -savetiles "cross (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "cross (palette).bin" -spritepalette
REM bmp2tile.exe raw\select.png -savetiles "select (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "select (palette).bin" -spritepalette


REM echo Build gfx.c and gfx.h from gfx folder
folder2c ..\gfx gfx
folder2c ..\psg psg

REM echo Build gfx
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 gfx.c
if %errorlevel% NEQ 0 goto :EOF

REM echo Build psg
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 psg.c
if %errorlevel% NEQ 0 goto :EOF

REM echo Build banks
cd banks
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c
cd ..

REM echo Build main
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c
if %errorlevel% NEQ 0 goto :EOF

REM echo Linking
sdcc -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 ^
-Wl-b_BANK2=0x8000 ^
-Wl-b_BANK3=0x8000 ^
..\crt0\crt0_sms.rel ^main.rel ^
..\lib\SMSlib.lib ^
..\lib\PSGlib.rel ^
banks\bank2.rel ^
banks\bank3.rel ^
gfx.rel ^
psg.rel

if %errorlevel% NEQ 0 goto :EOF

REM echo Binary output
ihx2sms output.ihx output.sms
if %errorlevel% NEQ 0 goto :EOF

REM echo Copy output
copy output.sms ..\asm
copy output.sms ..\Simpsons.sms

REM echo Disassemble output
cd ..\asm
smsexamine.exe output.sms
cd ..\dev

REM echo Delete
cd banks
del *.asm > nul
del *.lst > nul
del *.rel > nul
del *.sym > nul
cd ..

del *.asm > nul
del *.ihx > nul
del *.lk > nul
del *.lst > nul
del *.map > nul
del *.noi > nul
REM del *.rel > nul
del main.rel > nul
del *.sym > nul

output.sms