#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(127);
    
    
    // Example 4,5
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableAlphaBlending();
    ofEnableDepthTest();
    foto.load("hanuman_avatar.png");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    iAng += .01;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /*
     
    // Example1
    ofSetColor(255, 0, 255);
    ofRotateZ(mouseX);
    ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    ofDrawRectangle(0, 0, 30, 30);
    */
    
    /*
    // Example 2
    ofBackground(mouseX/2, mouseY/2, 125);
    for (int i=0; i<ofGetWindowWidth(); i+=5){
        ofRotate(i*3.14);
        ofDrawLine(i, 0, i+5, 900);
    }
     */

    /*
    // Example 3
    ofBackground(mouseX/6, mouseY/4, 125);
    ofSetColor(0);
    for (int i=0; i<ofGetWindowWidth(); i+=25){
        for (int z=0; z<ofGetWindowHeight(); z+=25){
            ofSetColor(mouseX+i/6,mouseY+z/4,125);
            ofDrawRectangle(i, z, 15 ,15);
        }
    }
     */
    
    /*
    // Example 4
    ofPushMatrix();
    ofTranslate(mouseX, mouseY);
    for (int z=0; z<=100; z++){
        ofSetColor(z*mouseX/10, z+mouseY/7, z*5);
        ofScale(1.1,1.1);
        ofRotate(mouseX/3.14);
        ofDrawRectangle(0, 0, 40, 40);
    }
    ofPopMatrix();
    
    ofSetColor(0, 250, 0);
    ofDrawRectangle(0, 0, 100, 100);
     */
    
    /*
    // Example 5
    ang = iAng;
    for (int z=0; z<=ofGetWidth(); z+=15){
        float y = ofMap(sin(ang), -1, 1, 5, ofGetHeight()-20);
        ofSetColor(127, y+1, 0);
        ofDrawCircle(z, y, 15);
        ang+=vAng;
    }
     */
    
    
    
    // Example 4b
    ang = iAng;
    ofPushMatrix();
    ofTranslate(abs(sin(ang)*ofGetWidth()), abs(cos(ang)*ofGetHeight()));
    for (int z=0; z<=100; z++){
        ofScale(1.1,1.1);
        //ofRotate(mouseX/3.14);
        ofRotate(sin(ang*.1)*360);
        //ofDrawRectangle(0, 0, 40, 40);
        foto.draw(0, 0);
    }
    ofPopMatrix();
    
    ofSetColor(250, 250, 250);
    ofDrawRectangle(0, 0, 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='f'){
        ofToggleFullscreen();
    }
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
