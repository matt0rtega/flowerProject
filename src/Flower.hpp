//
//  Flower.hpp
//  flowerProject
//
//  Created by Matthew Ortega on 11/6/17.
//

#ifndef Flower_hpp
#define Flower_hpp

#include "ofMain.h"


class Flower {
    
public: // place public functions or variables declarations here
    
    // methods, equivalent to specific functions of your class objects
    void setup(float _size, ofColor co, float _x, float _y);    // setup method, use this to setup your object's initial state
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    Boolean isDead();
    
    // variables
    float fade;
    float target = 255;
    float lifespan;
    float x, y, x1, y1, x2, y2;
    float size = 0;
    ofColor basecolor;
    ofVec2f location;
    float easing;
    float offset, offset1, f;
    
    // Circle Direction
    #define CDIRECT 10
    //int circleDirect [CDIRECT];
    int circleDirect[CDIRECT];
    
    // Moving speeds
    #define CSPEEDS 3
    float speeds [CSPEEDS];
    
    //Color array
    #define CCOLORS 3
    ofColor colors [CCOLORS];
    
    
    Flower();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
private: // place private functions or variables declarations here
    
}; // don't forget the semicolon!
#endif /* Flower_hpp */
