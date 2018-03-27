# SimpsonsTriviaSMS
Simpsons Trivia game for the Sega Master System 2018 Competition

###### RELEASE
Tuesday, 27th March 2017

###### INTRO
The Simpsons is a hit American TV show that has become a cultural phenomenon.
<br />
Therefore, it only seems natural to build a Simpsons Trivia game for the SMS!

###### INSTRUCTIONS
Simple: move joystick Up and Down to select multichoice answer: A, B, C, D.
<br />
Press button 1 to select an answer or progress forward through any prompts.
<br />
Note: Press button 2 to always go back.  Also Left and Right are not used.

###### TOOLS
- Programming:	devkitSMS
- Languages:	C / Z80
- Visual Studio 2008
- Graphics:		BMP2Tile
- Music:		VGM2PSG
- Assembler:	WLA-DX
- Disassembler:	SMS Examine
- Emulators:	Fusion / Meka / Emulicious

###### SOURCE CODE
http://github.com/SteveProXNA/SimpsonsTriviaSMS

###### ROM HACKING
You can hack this ROM!  
Download and dump CandyKidDemo.sms into Hex Editor, e.g. HxD, and modify bytes:
- 0x0050	Steps to move Kid: 1, 2, 4, 8 pixels.
- 0x0051	Delay for enemy ghosts arm moves.
- 0x0052	Hands for enemy ghosts to toggle.
- 0x0053	Music 0=music play otherwise off.
- 0x0054	Sound	0=sound on otherwise off.
- 0x0055	Paths to test individually 1 thru 8.

###### CREDITS
Extra special thanks to: sverx for devkitSMS https://github.com/sverx/devkitSMS
<br />
Special thanks to: 
Maxim, Martin, Ville Helin, Steve Snake, Bock + Emulicious devs
<br />
Also, I "borrowed" sound effects from Baluba Balok http://bit.ly/2nnSQJG Thanks!

###### SOCIAL MEDIA
- You Tube https://youtu.be/HbtZgRN_j0Y

###### COMPANY BIO
StevePro Studios is an independent game developer that builds and publishes 80s retro arcade video games!
<br />
Founded by Steven Boland "SteveProXNA" (Jan-2007) a "one man team of one" currently based in Dublin, Ireland.

Previous Sega-based retro games published include "Candy Kid" available here:
- iOS		http://apple.co/1QcidUk
- Android	http://goo.gl/5rWsYO
- Kindle	http://amzn.to/1IQPBA4
- PC		http://amzn.to/1QiHM9d

###### CONTACT
- Blog:		http://steveproxna.blogspot.com
- Email:	steven_boland@hotmail.com
- Twitter:	[@SteveProXNA](http://twitter.com/SteveProXNA)
