/*	simple Hello World, for cc65, for NES
 *  writing to the screen with rendering disabled
 *	using neslib
 *	Doug Fraker 2018
 */	
 
 
 
#include "LIB/neslib.h"
#include "LIB/nesdoug.h" 

#define BLACK 0x0f
#define DK_GY 0x00
#define LT_GY 0x10
#define WHITE 0x30
// there's some oddities in the palette code, black must be 0x0f, white must be 0x30
 
 
 
#pragma bss-name(push, "ZEROPAGE")

// GLOBAL VARIABLES
// all variables should be global for speed
// zeropage global is even faster

unsigned char i;
unsigned char x;
unsigned char y;
unsigned char cidx;

const unsigned char *greet="Hello Gudakdong!"; // zero terminated c string
const unsigned char *title="Special Thanks to";
const unsigned char *text[]={
	"Zero",
	"JJ3rd",
	"HSFather",
	"AhnSoBest",
	"Soo9",
	"HStoree",
	"Orion g",
	"Min",
	"King's Father",
	"NeoSoul",
	"Unfamilar Freedom",
	"FuranC",
	"UltraS92"
};
const unsigned char size = 13;

const unsigned char *footer = "And You...";


const unsigned char palette[]={
BLACK, DK_GY, LT_GY, WHITE,
0,0,0,0,
0,0,0,0,
0,0,0,0
}; 

void print(const unsigned char *s) {
	cidx = 0;
	vram_adr(NTADR_A(x, y));
	while (s[cidx]) {
		vram_put(s[cidx]);
		++cidx;
	}
	y++;
};

void main (void) {
	x = 5;
	y = 3;
	ppu_off(); // screen off

	pal_bg(palette); //	load the BG palette
		
	// set a starting point on the screen
	//vram_adr(NTADR_A(10,14)); // screen is 32 x 30 tiles
	print(greet);
	y++;
	print(title);
	y++;
	for (i = 0; i < size; i++) {
		print(text[i]);
	}
	y++;
	print(footer);
	
	// vram_adr and vram_put only work with screen off
	// NOTE, you could replace everything between i = 0; and here with...
	// vram_write(text,sizeof(text));
	// does the same thing
	
	ppu_on_all(); //	turn on screen
	
	
	while (1){
		// infinite loop
		// game code can go here later.
	}
}
	
	
