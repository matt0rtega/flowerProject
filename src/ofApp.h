#pragma once

#include "ofMain.h"
#include "Flower.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void reloadColors();
        void loadPoints();
        int randomSelect();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int tileCount;
        int gridSize;
        int numFlowers;
        int flowerSelector;
    
        // Equivalent of ArrayList
        vector <Flower> flowers;
        Flower flower;
    
        ofImage img;
        vector <ofImage> imgs;
        int selectedImg = 0;
    
        vector <ofVec2f> points;
        vector <ofColor> colors;
		
    
};
