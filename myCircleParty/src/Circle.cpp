#include "Circle.h"

Circle::Circle(){
}

//--------------------------------------------------------------
void Circle::setup(int _x, int _y){
	x = _x;
	y = _y;

	radius = 0;
	radioMax = ofRandom(1, 4.5);
	tasaCrec = ofRandom(0.2, 1.2);

	esRadioMax = false;
	esSuperpuesto = false;

	c.setHsb((x + 2 * y + ofGetFrameNum()) % 255, 191.25, 216.75);
}

//--------------------------------------------------------------
void Circle::update(){
	if(!esRadioMax && !esSuperpuesto){
		radius += tasaCrec;
		esRadioMax = radius >= radioMax;
	}
}

//--------------------------------------------------------------
void Circle::display(){
	ofFill();
	ofSetColor(c);
	ofDrawCircle(x, y, radius);
	ofNoFill();
	ofSetColor(0);

}

void Circle::superp(const vector <Circle *> circles){
	if(!esRadioMax && !esSuperpuesto){
		for(int i = 0; i < circles.size(); i++){
			if(circles[i] != this){
				if(ofDist(x, y, circles[i]->x, circles[i]->y) <= circles[i]->radius + radius + tasaCrec){
					esSuperpuesto = true;
				}
			}
		}
	}
}
