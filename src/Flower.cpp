//
//  Flower.cpp
//  flowerProject
//
//  Created by Matthew Ortega on 11/6/17.
//

#include "Flower.hpp"

Flower::Flower(){
    
}

void Flower::setup(float _size, ofColor _co, float _x, float _y){
    size = _size/2 - ofRandom(0, _size);
    
    fade = 0;
    lifespan = 255;
    basecolor = _co;
    
    colors[0] = ofColor(255, 0, 0);
    colors[1] = ofColor(0, 255, 0);
    colors[2] = ofColor(0, 0, 255);
    
    x = 0.0;
    y = 0.0;
    x1 = 0.0;
    y1 = 0.0;
    x2 = 0.0;
    y2 = 0.0;
    
//    x = 100;
//    y= 100;
//    x1 = 200;
//    y1 = 120;
//    x2 = 300;
//    y2 = 140;
//
    easing = ofRandom(0.01, 0.05);
    
    location = ofVec2f(_x, _y);
    // or location.set(x,y);
    
    offset = ofRandom(0, 1000);
    
    int rand[] = {-1, 1};
    
    for(int i=0; i<CDIRECT; i++){
        
        int randSelector = int(ofRandom(0, 2));
        
        circleDirect[i] = rand[randSelector];
        speeds[i] = ofRandom(0.01, 0.04);
    }
}

// Done
void Flower::update(){
    float time = ofGetElapsedTimeMillis() * 0.0633;

    //cout << time << endl;
    
    x = ofMap(sin(time * speeds[0] + offset), -1*circleDirect[0], 1*circleDirect[0], -size, size);
    y = ofMap(cos(time * speeds[0] + offset), -1, 1, -size, size);
    x1 = ofMap(sin(time * speeds[1]), -1*circleDirect[0], 1*circleDirect[0], -size, size);
    y1 = ofMap(cos(time * speeds[1] - 0.2), -1, 1, -size, size);
    x2 = ofMap(sin(time * speeds[2]), -1*circleDirect[0], 1*circleDirect[0], -size, size);
    y2 = ofMap(cos(time * speeds[2] - 0.002), -1, 1, -size, size);
    
    lifespan -= 0.3;
    // fade+=1;
    
    float fadeOffset = ofMap(lifespan, 255, 0, 0, 255);
    
    if(fade > 254){
        target = 0;
    }
    
    fade = ofLerp(fade, target, easing);
    
    fade = fade - fadeOffset;
    
    //fade = 255;
}

void Flower::draw(){
    
    ofPushMatrix();
    ofTranslate(size + location.x, size + location.y);
    ofSetColor(basecolor, fade);
    ofNoFill();
    ofDrawLine(0, 0, x, y);
    ofSetColor(basecolor, fade);
    ofDrawLine(0, 0, x1, y1);
    ofSetColor(basecolor, fade);
    ofDrawLine(0, 0, x2, y2);
    ofPopMatrix();

}

Boolean Flower::isDead(){
    if(lifespan<0){
        return true;
    } else {
        return false;
    }
}
