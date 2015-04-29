//This code was written by Andreas Muller as part of his Noise Workshop. 
//The .h file has been separated into a .h and .cpp and the code has been commented by Joni, but otherwise remains the same. 
//This has been done for educational purposes.

#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
	public:
		void setup(); //this lets us have a setup function
		void draw(); //this lets us have a draw function
		void keyPressed( int _key ); //this lets us have a keyPressed function

		ofTrueTypeFont fontSmall; //this is a font that will be used through multiple functions so must be declared here
	
};
