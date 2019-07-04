#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void draw();
		void makePoint(int posx, int posy);
		ofMesh mesh;
};
