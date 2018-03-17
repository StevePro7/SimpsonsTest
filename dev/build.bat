@echo off
REM echo Execute bmp2tile
REM bmp2tile.exe raw\font.bmp -savetiles "font (tiles).psgcompr" -removedupes -tileoffset 0 -savetilemap "font (tilemap).bin" -savepalette "font (palette).bin"
REM bmp2tile.exe raw\splash.bmp -savetiles "splash (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 112 -savetilemap "splash (tilemap).stmcompr" -savepalette "splash (palette).bin"
REM bmp2tile.exe raw\simpsons.bmp -savetiles "simpsons (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 80 -savetilemap "simpsons (tilemap).stmcompr" -savepalette "simpsons (palette).bin"

REM bmp2tile.exe raw\right.bmp -savetiles "right (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "right (palette).bin" -spritepalette
REM bmp2tile.exe raw\wrong.bmp -savetiles "wrong (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "wrong (palette).bin" -spritepalette
REM bmp2tile.exe raw\select.png -savetiles "select (tiles).psgcompr" -noremovedupes -nomirror -planar -savepalette "select (palette).bin" -spritepalette

REM bmp2tile.exe raw\maggie.bmp -savetiles "maggie (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 112 -savetilemap "maggie (tilemap).stmcompr" -savepalette "maggie (palette).bin"

REM echo Build gfx.c and gfx.h from gfx folder
folder2c ..\gfx gfx
REM folder2c ..\psg psg

REM echo Build gfx
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 gfx.c
if %errorlevel% NEQ 0 goto :EOF

REM echo Build psg
REM sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 psg.c
if %errorlevel% NEQ 0 goto :EOF

REM echo Build banks
REM cd banks
REM sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c
REM sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c
REM cd ..

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
REM del *.asm > nul
REM del *.lst > nul
REM del *.rel > nul
REM del *.sym > nul
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