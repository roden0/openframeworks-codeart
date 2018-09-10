#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Ejercicio 1");
    ofBackground(220,220,220);
    ofSetCurveResolution(7);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofSetFrameRate(15);
    radioC = 10;
    
    foto.load("img-2018-09-05-21-10-02-531.png");
    ttf.load("OpenSans-Regular.ttf", 25);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //ofNoFill();
        ofSetColor(255, 255, 255);
    ofDrawBitmapString("THIS IS NOT A COMPUTER GRAPHIC", 200, 200);
    
        ofFill();
        ofSetColor(120, 70, 70, 125);
        ofRotate(-35);
    ofDrawRectangle(250, 100, 200, 400);
    
        ofSetColor(50, 150, 150, 80);
    ofDrawCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, radioC);
    
        ofSetColor(50, 150, 150, 80);
    ofDrawTriangle(20, 250, 40, 350, 450, 50);
    
        ofSetColor(ofGetMouseX(), 250, 50, 120);
        ofNoFill();
        ofSetLineWidth(4);
        ofRotate(15);
    ofDrawRectRounded(ofGetMouseX(), ofGetMouseY(), 100, 80, 10);
    
        ofSetColor(255,0,0);
        ofSetLineWidth(2);
    ofDrawLine(ofGetMouseY(),100,900,600);
    
    if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)){
        radioC += 2;
        float randCol = ofRandom(0, 255);
        ofSetColor(randCol,ofRandom(0, 255),ofRandom(0, 255));
        ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 200, 400);
    }
    
    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(fpsStr, 100,100);
    ttf.drawString("Ejemplo 1", 450, 450);
    
    ofSetColor(255);
    foto.draw(mouseX, mouseY,50,50);

}

void ofApp::keyPressed(int key){
    if(key=='s'){
        glReadBuffer(GL_FRONT);
        ofSaveScreen("img-"+ofGetTimestampString()+".png");
    }
}
