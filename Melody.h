#pragma once

const static Note melody[] PROGMEM = {
	/*
	// OPENING 1
	{NOTE_DS4, 650, 70},
	{NOTE_DS4, 650, 70},
	{NOTE_DS4, 650, 70},
	{NOTE_AS3, 650, 70},
	{NOTE_FS3, 650, 70},
	{NOTE_CS4, 300, 70},
	{NOTE_B3, 900, 1200}, 
	{NOTE_AS3, 350, 30},
	{NOTE_DS4, 700, 70},
	{NOTE_DS4, 950, 130},
	{NOTE_AS3, 300, 30},
	{NOTE_DS4, 600, 70},
	{NOTE_AS3, 600, 30},
	{NOTE_FS3, 700, 70},
	{NOTE_CS4, 900, 70},
	{NOTE_FS3, 1100, 2000}, // 147700

	// OPENING 2 // 13U = 5850
	
	{NOTE_FS4, 1300, 50},
	{NOTE_F4, 310, 30},
	{NOTE_DS4, 990, 20}, // 6U
	{NOTE_DS4, 400, 50},
	{NOTE_CS4, 400, 50},
	{NOTE_DS3, 450, 450}, // 4U
	{NOTE_CS4, 250, 200},
	{NOTE_FS4, 250, 75},
	{NOTE_DS4, 200, 1725}, // 3U

*/
/*
	// OPENING 3 + DRUMS // 8.5U = 3825
	{NOTE_FS4, 1300, 50},
	{NOTE_F4, 310, 30},
	{NOTE_DS4, 990, 20}, // 6U

	{NOTE_DS4, 400, 50},
	{NOTE_CS4, 400, 275}, // 2.5 (round to 3 in drums)


	// HAAA HAHAHAAAAAAAA // 7U = 3150

	{NOTE_FS5, 225, 0},
	{NOTE_DS5, 225, 0},
	{NOTE_CS5, 225, 0},
	{NOTE_DS5, 225, 0},
	{NOTE_FS5, 225, 0},
	{NOTE_DS5, 225, 0},
	{NOTE_CS5, 225, 0},
	{NOTE_DS5, 225, 0},
	{NOTE_CS5, 225, 0},
	{NOTE_AS4, 400, 50},
	{NOTE_AS5, 500, 400},
	


// OH I KNOW I LOVE YOU // 12U
{NOTE_AS4, 450, 225},
{NOTE_AS4, 200, 25}, 
{NOTE_AS4, 200, 250}, //3U

{NOTE_FS4, 200, 130},
{NOTE_F4, 170, 170},
{NOTE_DS4, 210, 250},

{NOTE_DS4, 150, 70},
{NOTE_DS4, 150, 70},
{NOTE_AS4, 150, 75},
{NOTE_GS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_GS4, 150, 300},

{NOTE_AS4, 150, 75}, 
{NOTE_AS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_DS4, 150, 75},

{NOTE_FS4, 250, 100}, 
{NOTE_DS4, 150, 1975}, 


//{NOTE_DS5, 10, 265},
// CAUSE I DON'T UNDERSTAND YOU /6U

{NOTE_DS5, 150, 75},
{NOTE_CS5, 150, 75},
{NOTE_DS5, 150, 75},
{NOTE_AS4, 300, 150},
{NOTE_AS4, 200, 137},
{NOTE_GS4, 125, 213},
{NOTE_AS4, 325, 800},


// OH YOU // 8U
{NOTE_AS4, 350, 100},
{NOTE_GS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_GS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_GS4, 150, 75},
{NOTE_DS3, 150, 75},
{NOTE_CS3, 150, 75},
{NOTE_DS3, 150, 1200},


//{NOTE_DS3, 1, 1574},

// WHEN WE FIRST MET
{NOTE_DS4, 56, 56}, // 0.25u 112
{NOTE_FS4, 150, 75}, // 0.50u
{NOTE_AS4, 300, 38}, // 338 0.75u  // 1.5U

{NOTE_AS4, 200, 925},

// I WILL NEVER FORGET
{NOTE_DS4, 56, 56}, 
{NOTE_CS4, 56, 57},
{NOTE_DS4, 56, 56}, 
{NOTE_FS4, 56, 57}, 
{NOTE_AS4, 56, 56}, 
{NOTE_AS4, 132, 1556},


// CAUSE EVEN THOUGH I DIDN'T KNOW YOU YET
{NOTE_AS4, 150, 75}, // 0.50u

{NOTE_GS4, 150, 75}, // 0.50u
{NOTE_FS4, 57, 56}, // 0.25u
{NOTE_FS4, 112, 112}, // 0.55u

{NOTE_GS4, 150, 75}, // 0.50u	
{NOTE_GS4, 150, 75}, // 0.50u
{NOTE_FS4, 150, 75}, // 0.50u
{NOTE_CS5, 150, 75}, // 0.50u
{NOTE_B4, 150, 75}, // 0.50u
{NOTE_AS4, 255, 983}, // 0.50u


// WE WERE BOUND TOGETHER
{NOTE_AS4, 400, 50},
{NOTE_GS4, 150, 75},

{NOTE_A4, 500, 175},
{NOTE_AS4, 150, 75}, // 0.50u
{NOTE_FS4, 57, 56}, // 0.25u
{NOTE_DS4, 250, 312}, // 0.25u

// THEN AND FOREVER
{NOTE_GS4, 400, 50},
{NOTE_GS4, 350, 100},
{NOTE_AS4, 150, 75},
{NOTE_FS4, 57, 56},
{NOTE_DS4, 250, 312},


// AND I COULD NEVER LET YOU GOOO
{NOTE_GS4, 400, 50},
{NOTE_GS4, 350, 100},
{NOTE_FS4, 150, 75},
{NOTE_AS4, 57, 56},
{NOTE_AS4, 250, 87},

{NOTE_AS4, 200, 137},
{NOTE_FS4, 250, 88},
{NOTE_DS4, 250, 1325},


// BABY! I CAN'T TO KNOW
{NOTE_DS5, 150, 75},
{NOTE_DS5, 400, 50},


// BASS
{NOTE_AS2, 150, 75},
{NOTE_CS3, 400, 50},
{NOTE_DS3, 250, 87},

{NOTE_DS5, 487, 76},
{NOTE_AS4, 400, 50},
{NOTE_FS4, 400, 50},


{NOTE_CS5, 287, 50},
//{NOTE_B4, 300, 712},
{NOTE_B4, 300, 150},

{NOTE_AS3, 150, 75},
{NOTE_AS3, 150, 189},

//{NOTE_GS3, 150, 75},
{NOTE_FS3, 300, 37},
{NOTE_CS4, 150, 75},
{NOTE_GS3, 300, 37},
{NOTE_AS3, 150, 75},


//{NOTE_AS4, 1, 224},

// WHAT DO YOU THINK ABOUT THINGS 
{NOTE_AS4, 150, 75},
{NOTE_GS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_GS4, 76, 36}, 
{NOTE_GS4, 77, 36},
{NOTE_FS4, 150, 75}, 
{NOTE_DS4, 150, 75}, 

// BELIEVE ME
{NOTE_DS4, 150, 75}, 


{NOTE_DS5, 150, 75}, 
{NOTE_DS5, 300, 150}, 


// BASS
{NOTE_AS2, 150, 75},
{NOTE_CS3, 450, 0},
//{NOTE_DS3, 150, 0},


// I WILL ALWAYS BE THERE SO	
{NOTE_GS4, 77, 36}, 
{NOTE_AS4, 150, 75}, 
{NOTE_DS5, 400, 162},

{NOTE_AS4, 400, 50},
{NOTE_FS4, 400, 50},
{NOTE_CS5, 300, 37},

{NOTE_B4, 713, 300},


// YOU CAN TELL ME ANYTHING AND I'LL LISTEN
{NOTE_AS4, 400, 50},
{NOTE_AS4, 400, 50},
{NOTE_GS4, 150, 75}, 
{NOTE_AS4, 150, 75},  
{NOTE_GS4, 150, 75}, 
{NOTE_FS4, 150, 75}, 
{NOTE_DS4, 76, 36}, 
{NOTE_DS4, 77, 36},
{NOTE_DS4, 150, 75},


{NOTE_FS4, 150, 75},

{NOTE_DS4, 150, 1200}, 


// SOLO
{NOTE_CS4, 300, 37},
{NOTE_D4, 300, 38},

{NOTE_DS4, 400, 50}, 
{NOTE_CS4, 76, 36}, 
{NOTE_DS4, 177, 161},

{NOTE_GS4, 400, 50}, 
{NOTE_FS4, 300, 38},
{NOTE_DS4, 200, 137},
{NOTE_GS4, 161, 177},
{NOTE_GS4, 160, 177},

{NOTE_GS4, 76, 36}, 
{NOTE_FS4, 77, 36},
{NOTE_GS4, 76, 36}, 
{NOTE_AS4, 117, 108},

{NOTE_CS4, 77, 36},
{NOTE_D4, 76, 36},
{NOTE_DS4, 127, 211},

{NOTE_FS4, 300, 37},
{NOTE_GS4, 300, 38},
{NOTE_AS4, 400, 50}, 

{NOTE_FS4, 150, 75},  
{NOTE_GS4, 76, 36}, 
{NOTE_DS4, 127, 211},

{NOTE_DS4, 76, 36}, 
{NOTE_AS3, 77, 36},
{NOTE_CS3, 76, 36}, 
{NOTE_DS4, 127, 211},

{NOTE_DS4, 76, 36}, 
{NOTE_AS3, 77, 36},
{NOTE_CS3, 76, 36}, 
{NOTE_DS4, 127, 211},

{NOTE_FS4, 76, 36}, 
{NOTE_DS4, 127, 211},

{NOTE_DS4, 150, 75},  
{NOTE_CS4, 76, 36}, 
{NOTE_DS4, 127, 211},



{NOTE_GS4, 400, 50}, 
{NOTE_AS4, 300, 38},
{NOTE_B4, 200, 137},

{NOTE_B4, 150, 75}, 
{NOTE_CS3, 77, 36},
{NOTE_D3, 76, 36}, 
{NOTE_DS4, 150, 75}, 



{NOTE_B4, 150, 75}, 
{NOTE_CS3, 77, 36},
{NOTE_D3, 76, 36}, 
{NOTE_DS4, 150, 75}, 

{NOTE_AS4, 76, 36}, 
{NOTE_GS4, 127, 211},

{NOTE_FS4, 300, 37},
{NOTE_GS4, 300, 38},


{NOTE_AS4, 400, 50}, 
{NOTE_CS5, 300, 38},
{NOTE_DS5, 300, 38},

{NOTE_DS4, 76, 36}, 
{NOTE_AS3, 77, 36},
{NOTE_CS3, 76, 36}, 
{NOTE_DS4, 127, 211},

{NOTE_DS4, 76, 36}, 
{NOTE_AS3, 77, 36},
{NOTE_CS3, 76, 36}, 
{NOTE_DS4, 127, 436},


// WHEN WE ARE TOGETHER 
{NOTE_AS4, 450, 225},
{NOTE_AS4, 200, 25}, 
{NOTE_AS4, 200, 250}, //3U

{NOTE_FS4, 200, 130},
{NOTE_F4, 170, 170},
{NOTE_DS4, 210, 250},


// THERE ISN'T ANYWHERE 
{NOTE_DS4, 150, 70},
{NOTE_DS4, 150, 70},
{NOTE_AS4, 150, 75},
{NOTE_GS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_GS4, 150, 300},

// THAT I WOULD RATHER BE
{NOTE_AS4, 150, 75}, 
{NOTE_AS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_CS4, 150, 75},
{NOTE_DS4, 150, 75},
{NOTE_DS4, 150, 1875}, 


// THREE BIRDS OF A FEATHER
{NOTE_DS5, 400, 50}, 
{NOTE_CS5, 400, 50}, 
{NOTE_AS4, 400, 50}, 

{NOTE_AS4, 295, 37},
{NOTE_GS4, 155, 75},
{NOTE_FS4, 300, 38},

{NOTE_AS4, 400, 275}, 


// I JUST HOPE YOU ENJOY OUR COMPANY

{NOTE_AS3, 150, 75}, 
{NOTE_CS4, 150, 75},
{NOTE_GS4, 350, 100},

{NOTE_AS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_AS3, 150, 75},
{NOTE_FS4, 150, 75},
{NOTE_DS4, 150, 75},



// IT'S BEEN SOME TIME
{NOTE_DS4, 400, 50}, 
{NOTE_FS4, 400, 50}, 
{NOTE_AS4, 400, 50}, 
{NOTE_AS4, 400, 50}, 

// AND THOUGH HARD TO DEFINE
{NOTE_DS4, 150, 75},
{NOTE_DS4, 150, 75},
{NOTE_FS4, 150, 75},
{NOTE_GS4, 150, 75},

{NOTE_AS4, 400, 50}, 
{NOTE_AS4, 400, 50}, 
{NOTE_GS4, 400, 50}, 
{NOTE_FS4, 400, 50}, 


// AS IF THE STARS HAVE STARTED TO ALIGN
{NOTE_AS4, 400, 50}, 
{NOTE_GS4, 150, 75}, 
{NOTE_FS4, 150, 75}, 
{NOTE_FS4, 150, 75}, 
{NOTE_GS4, 150, 75},
{NOTE_GS4, 150, 75},
{NOTE_FS4, 150, 75},
{NOTE_AS4, 150, 75}, 
{NOTE_GS4, 150, 75},
{NOTE_FS4, 76, 36},
{NOTE_DS4, 100, 913}, 



// WE ARE BOUND TOGETHER
{NOTE_AS4, 400, 50},
{NOTE_GS4, 150, 75},

{NOTE_A4, 500, 175},
{NOTE_AS4, 150, 75}, // 0.50u
{NOTE_FS4, 57, 56}, // 0.25u
{NOTE_DS4, 250, 312}, // 0.25u

// NOW AND FOREVER
{NOTE_GS4, 400, 50},
{NOTE_GS4, 350, 100},
{NOTE_AS4, 150, 75},
{NOTE_FS4, 57, 56},
{NOTE_DS4, 250, 312},


// AND I WILL NEVER LET YOU GOOO
{NOTE_GS4, 400, 50},
{NOTE_GS4, 350, 100},
{NOTE_FS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_CS5, 150, 75},
{NOTE_CS5, 400, 50},
{NOTE_CS5, 1125, 0},
{NOTE_D5, 350, 100},

*/
// BABY! I CAN'T TO KNOW
{NOTE_DS5, 150, 75},
{NOTE_DS5, 400, 50},


// BASS
{NOTE_AS2, 150, 75},
{NOTE_CS3, 400, 50},
{NOTE_DS3, 250, 87},

{NOTE_DS5, 487, 76},
{NOTE_AS4, 400, 50},
{NOTE_FS4, 400, 50},


{NOTE_CS5, 287, 50},
//{NOTE_B4, 300, 712},
{NOTE_B4, 300, 150},

{NOTE_AS3, 150, 75},
{NOTE_AS3, 150, 189},

//{NOTE_GS3, 150, 75},
{NOTE_FS3, 300, 37},
{NOTE_CS4, 150, 75},
{NOTE_GS3, 300, 37},
{NOTE_AS3, 150, 75},


//{NOTE_AS4, 1, 224},

// WHAT DO YOU THINK ABOUT THINGS 
{NOTE_AS4, 150, 75},
{NOTE_GS4, 150, 75},
{NOTE_AS4, 150, 75},
{NOTE_GS4, 76, 36}, 
{NOTE_GS4, 77, 36},
{NOTE_FS4, 150, 75}, 
{NOTE_DS4, 150, 75}, 

// BELIEVE ME
{NOTE_DS4, 150, 75}, 


{NOTE_DS5, 150, 75}, 
{NOTE_DS5, 300, 150}, 


// BASS
{NOTE_AS2, 150, 75},
{NOTE_CS3, 450, 0},
//{NOTE_DS3, 150, 0},


// I WILL ALWAYS BE THERE SO	
{NOTE_GS4, 77, 36}, 
{NOTE_AS4, 150, 75}, 
{NOTE_DS5, 400, 162},

{NOTE_AS4, 400, 50},
{NOTE_FS4, 400, 50},
{NOTE_CS5, 300, 37},

{NOTE_B4, 713, 300},


};


















