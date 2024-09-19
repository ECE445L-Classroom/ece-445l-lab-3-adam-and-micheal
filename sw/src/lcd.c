

#include "lcd.h"
#include "pixelImages.h"

/*
Draws the background of the overll display
*/
void drawBackground(uint16_t color){
	ST7735_FillScreen(color);
}


/*
This is the function for drawing the back of the analog clock. This should always be drawn the same way.
So hopefully no issues with this part.
*/
void drawAClockBack(){

	for (int i = 40; i < 100; ++i){
		uint16_t width, xLocation;
		const uint16_t* pixels = obtainCirclePixels(&width, &xLocation, i-40);
		for (int j = 0; j < width; ++j){
			ST7735_DrawPixel(xLocation, i, pixels[j]);
		}	
	}	
}

/*
This function draws the second hand for the analog clock. This takes an input of the second to be drawn
and draws it accordingly.
*/
void drawAClockSecond(uint8_t second){
	
	
}

/*
This function draws the minute hand for the analog clock. This takes an input of the minute to be
drawn and draws it accordingly
*/
void drawAClockMinute(uint8_t minute){
	
}


/*
This function draws the hour hand for the analog clock. This takes an input of the hour to be
drawn and draws it accordingly
*/

void drawAClockHour(uint8_t hour){
	
	
}

/*
This is the root of drawing the analog clock, it takes the time to display as an input and 
draws it.
*/
void drawAClock(time_t currTime){
	drawAClockBack();
	drawAClockSecond(currTime.second);
	drawAClockMinute(currTime.minute);
	drawAClockHour(currTime.hour);
}

/*
This functions draws the background rectangle for the digital clock that will be in the 
top left corner of the screen
*/
void drawDClockBack(uint16_t color){
	
	
}


/*
This function draws the text for the time to be displayed on the digital clock.
It takes the current time that is to be drawn as an input and draws its text version
*/
void drawDClockTime(time_t currTime){
	
	
}


/*
This is the root of drawing the digital clock, it takes the time to display as an input
and draws it
*/
void drawDClock(time_t currTime, uint16_t color){
	drawDClockBack(color);
	drawDClockTime(currTime);
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
	drawDClock(inputs.DTime, inputs.DClockColor);
	drawSetTime(inputs.setTimeColor);
	drawSetAlarm(inputs.setAlarmColor);
	drawMessage(inputs.message, 30, inputs.showMessage);
}

