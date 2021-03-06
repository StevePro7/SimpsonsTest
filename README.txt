# SimpsonsTriviaSMS
Simpsons Trivia game for the SMS Power! 2018 Competition

###### RELEASE
Tuesday, 27th March 2017

###### INTRO
The Simpsons is a hit TV show that has become a world wide phenomenon.

Therefore, it seems only natural to build a Simpsons Trivia game for the SMS!

###### INSTRUCTIONS
Simple: move joystick Up and Down to select a multi-choice answer: A, B, C, D.

Press button 1 to select an answer or progress forward through any prompts.

Note: Press button 2 to always go back.  Joystick Left and Right are not used.

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
Download and dump SimpsonsTriviaSMS.sms into Hex Editor, e.g. HxD, and modify bytes:
- 0x004F	Used in development => debugging.
- 0x0050	Non-zero value will show answers.
- 0x0051	Ask random questions during quiz.
- 0x0052	Music 0=music play otherwise off.
- 0x0053	Sound	0=sound on otherwise off.

###### CHEAT
Some of the questions may be tough so you can cheat if necessary!

Either hack the ROM [above] to show the answers for every quiz OR


Alternatively on the Title screen whenyou're prompted to "Press Start"

Press button 2 five times and you will have answers to current quiz!

###### CREDITS
Extra special thanks to: sverx for devkitSMS https://github.com/sverx/devkitSMS

Plus shout out to eruiz00 as I used some programming tricks from "Astro Force"


Special thanks to:

Maxim, Martin, Ville Helin, Steve Snake, Bock + the Emulicious devs


Also, I "borrowed" sound effects from Baluba Balok http://bit.ly/2nnSQJG Thanks!

Note: game complete screen has the "Flicky" game over music from SMS Power!


Reference to original Simpsons Trivia questions can be found here:

https://www.absurdtrivia.com/trivia/the-simpsons

###### OUTSTANDING
It would be nice to have more graphics of The Simpsons characters throughout the quiz.

Unfortunately, I only had enough time to import  one consistent image for everything...

###### DOCUMENTATION
Links to documentation on games written for the Sega Master System using devkitSMS:
http://steveproxna.blogspot.com/2017/09/devkitsms-programming-setup.html

http://steveproxna.blogspot.com/2017/11/devkitsms-programming-sample.html

http://steveproxna.blogspot.com/2018/03/devkitsms-programming-sample-ii.html

 
###### COMPANY BIO
StevePro Studios is an independent game developer that builds and publishes 80s retro arcade video games!

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
