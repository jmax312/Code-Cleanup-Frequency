//This code was written by Andreas Muller as part of his Noise Workshop. 
//The .h file has been separated into a .h and .cpp and the code has been commented by Joni, but otherwise remains the same. 
//This has been done for educational purposes.

#include "ofApp.h"

		// --------------------------------
		void ofApp::setup()
		{
			fontSmall.loadFont("Fonts/DIN.otf", 8 ); //this loads a specific font to be used
		}
	
		// --------------------------------
		void ofApp::draw()
		{
			ofBackgroundGradient( ofColor(55), ofColor(0), OF_GRADIENT_CIRCULAR ); //this makes the background a nicer shade/gradient of gray
			
			ofEnableAlphaBlending(); //this turns on blending (of colors, I'm guessing?)
			
			// As we are feeding values measured in pixels, the frequency value will be pretty small
			float frequency = ofMap( ofGetMouseX(),  0, ofGetWidth(),  0.0001, 0.05 ); //this maps the frequency to the x position of the mouse

			// Draw ticks at each unit edge
			int numTicks = ceil(ofGetWidth() * frequency); //this will limit the number of ticks based on the width of the window and the frequency (see above)
			float areaCovered = numTicks; //this matches the area covered to the number of ticks
			if( numTicks <= 5 ) { numTicks *= 10; } //if the number of ticks is less than five, multiply it by ten
			
			for( int i = 0; i < numTicks; i++ ) //for as long as i is less than the number of ticks...
			{
				float noisePos = ofMap( i, 0, numTicks, 0, areaCovered); //map the noise position (?) to numTicks[i]
				float screenX = noisePos * (1.0/frequency); //something to do with the x axis relating to noisePos and frequency?
				ofVec2f top( screenX, 0); //top coordinate for the straight, vertical lines (see below)
				ofVec2f bot( screenX, ofGetHeight()); //bottom coordinate for the straight, vertical lines (see below)
			
				// Brighter white lines at unit edges (0,1,2) and less bright at fractionals (0.1,0.2, etc), but only if we are zoomed in enough
				if( (abs(fmodf(noisePos, 1.0)) <= 0) && areaCovered < 18 )  { ofSetColor( ofColor::white, 90 ); } else { ofSetColor( ofColor::white, 30 );  }

				ofLine( top, bot); //these are the parallel lines behind the noise
				
				ofVec2f textPos = top + ofVec2f(4,20); //this will position the text as it moves with the lines
				fontSmall.drawString( ofToString(noisePos), textPos.x, textPos.y ); //this writes the numbers seen at the top
			}
			
			// Compute a noise position for each pixels x position, taking a frequency value into account
			float noiseMagnitude = 300; //a float that is used for multiplication down below
			ofMesh mesh; //makes a mesh
			mesh.setMode( OF_PRIMITIVE_LINE_STRIP ); //sets the mesh mode
			int res = ofGetWidth(); //an integer tied to the width of the screen and used for mapping and the for loop below
			for( int i = 0; i < res; i++ ) //for as long as i is less than res...
			{
				ofVec2f pos = ofVec2f( ofMap( i, 0, res, 0, ofGetWidth() ), ofGetHeight() * 0.5f ); //a position vector mapped to res[i] and using the width and height of the screen
				
				float noisePos = (pos.x * frequency); //the noisePos equals the x positon of pos times the frequency (linked to x position of mouse)
				float noiseValue = ofSignedNoise( noisePos ); // ofSignedNoise gives us a value -1..1
				
				ofVec2f drawPos = pos + ofVec2f(0,noiseValue * noiseMagnitude); //the pos (position?) that will be drawn on the mesh now that it's been signed and multiplied
				
				mesh.addVertex( drawPos ); //adds vertexes based on x movement of mouse (see everything above)
			}

			ofSetColor( ofColor::white ); //sets the color for the mesh (noise line)
			mesh.draw(); //draw the mesh line
		}
	
		// --------------------------------
		void ofApp::keyPressed( int _key )
		{
			if( _key == ' ' ) //if the space bar is hit...
			{ //...do nothing, apparently...
			}
		}
	

