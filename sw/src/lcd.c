

#include "lcd.h"

/*
Draws the background of the overll display
*/
void drawBackground(uint16_t color){
	ST7735_FillScreen(color);
}


/*
This is the root of drawing the analog clock, it takes the time to display as an input and 
draws it.
*/
void drawAClock(time_t currTime){
	
	
}


/*
This is the root of drawing the digital clock, it takes the time to display as an input
and draws it
*/
void drawDClock(time_t currTime){
	
	
}


/*
This draws the background rectangle given a color for the background to be
*/
void drawSetTimeBack(uint16_t setTimeColor){
	
}


/*
This draws the text for the set time. This should always be "Set Time"
*/
void drawSetTimeText(){
	
	
}
	
/*
This is the root function for drawing the set time square
*/
void drawSetTime(uint16_t setTimeColor){
	drawSetTimeBack(setTimeColor);
	drawSetTimeText();
}

/*
This draws the background for the set alarm rectangle, it takes a color as an input 
which will serve as the color drawn for the rectangle
*/
void drawSetAlarmBack(uint16_t setAlarmColor){
	
	
}

/*
This draws the text for the set alarm block, should always be "Set Alarm"
*/
void drawSetAlarmText(){
	
	
}
	
	/*
 This draws the entire set alarm block, calls helper functions to accomplish this. 
Takes a color as an input to give to the drawSetAlarmBack function for drawing the background
of the rectangle
*/
void drawSetAlarm(uint16_t setAlarmColor){
	drawSetAlarmBack(setAlarmColor);
	drawSetAlarmText();
}


/*
This function will draw a basic message box (with the intention to alert the user to an alarm).
This message can be at most 30 chars to fit in the box, otherwise no message will be shown anyways.
*/
void drawMessage(char* message, uint8_t length, uint8_t show){
	if (show && length <= 30) {
		
	}
}

/*
This is the overall function used to draw the entire screen. It takes a screenInputs object and 
then calls all of the relevent functions to draw the screen.
*/
void drawEntireScreen(screenInputs_t inputs){
	drawBackground(inputs.backgroundColor);
	drawAClock(inputs.ATime);
	drawDClock(inputs.DTime);
	drawSetTime(inputs.setTimeColor);
	drawSetAlarm(inputs.setAlarmColor);
	drawMessage(inputs.message, 30, inputs.showMessage);
}

