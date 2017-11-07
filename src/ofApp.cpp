#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    //ofEnableSmoothing();
    ofEnableAlphaBlending(); // Remember if we are using transparency, we need to let openFrameworks know
    ofBackground(255, 255, 255);
    ofSetFrameRate(120);
    flower.setup(100, 255, ofGetWidth()/2, ofGetHeight()/2);
    
    img.load("img.png");
    //img.resize(ofGetWidth(), ofGetHeight());
    
    tileCount = 50;
    gridSize = ofGetWidth()/tileCount;
    
    //printf(gridSize);
    cout << gridSize << endl;
    numFlowers = tileCount * tileCount;
    
    
    //points.reserve(numFlowers);
    //colors.reserve(numFlowers);
    flowers.reserve(1000);
    
    flowerSelector = randomSelect();
    
    loadPoints();
    reloadColors();
    
    cout << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    flower.update();
    
    for(int i=0; i<1000; i++){
            int randomPoint = (int)ofRandom(0, points.size());
            Flower tempFlower;
            
            tempFlower.setup(gridSize + mouseX, colors[randomPoint], points[randomPoint].x, points[randomPoint].y);
            flowers.push_back(tempFlower);
    }
    
    cout << flowers.size() << endl;
    
    for (int i = 0 ; i<flowers.size(); i++) {
        flowers[i].update();
        
        if(flowers[i].isDead()){
            flowers.erase(flowers.begin()+i);
            //cout << "Dead as a doornail" << endl;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    flower.draw();
    
    for (int i = 0 ; i<flowers.size(); i++) {
        flowers[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::reloadColors(){
    
    for (int x=0; x<tileCount; x++){
        for (int y=0; y<tileCount; y++){
            int posx = x * gridSize;
            int posy = y * gridSize;
            
            ofColor co = img.getColor(posx, posy);
            colors.push_back(co);
            
        }
    }

}

void ofApp::loadPoints(){
    
    for(int x=0; x<tileCount; x++){
        for(int y=0; y<tileCount; y++){
            int posx = x * gridSize;
            int posy = y * gridSize;
            
            ofVec2f point = ofVec2f(posx, posy);
            points.push_back(point);
        }
    }
}

int ofApp::randomSelect(){
    int randomSelector = int(ofRandom(0, flowers.size()));
    return randomSelector;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    loadPoints();
    reloadColors();
    
    flower.setup(100, colors[0], ofGetWidth()/2, ofGetHeight()/2);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
