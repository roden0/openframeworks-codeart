#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    pdfS = false;
    pdfD = false;
    
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(30);
    ofSetCurveResolution(ofRandom(3,5));
    ofEnableAlphaBlending();
    
    for (int i=0; i<10; i++) {
        individuos[i].x = ofRandomWidth();
        individuos[i].y = ofRandomHeight();
        individuos[i].vx = ofRandom(-10,10);
        individuos[i].vy = ofRandom(-10,10);
        individuos[i].Radio = ofRandom(10, 60);
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<10; i++) {
        
        individuos[i].x = individuos[i].x + individuos[i].vx;
        individuos[i].y = individuos[i].y + individuos[i].vy;
        
        if (individuos[i].x<0 || individuos[i].x > ofGetWidth()) {
            individuos[i].vx = -individuos[i].vx;
        }
        
        if (individuos[i].y<0 || individuos[i].y > ofGetHeight()) {
            
            individuos[i].vy = -individuos[i].vy;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int tiempo= ofGetElapsedTimef();
    
    if(pdfS){
        ofBeginSaveScreenAsPDF("scn_"+ofGetTimestampString()+".pdf",false);
    }
    ofSetColor(0,55);
    
    ofNoFill();
    ofSetColor(0, 150, 0);
    for (int i=0; i<10; i++) {
        if(tiempo % 3 == 0){
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
            individuos[i].Radio += ofRandom(-10,10);
        }
        if(tiempo % 11 == 0){
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
            individuos[i].Radio += ofRandom(-10,10);
        }
        ofDrawCircle(-individuos[i].x, -individuos[i].y, individuos[i].Radio+2);
        ofDrawCircle(individuos[i].x, individuos[i].y, individuos[i].Radio);
    }
    if(pdfS){
        ofEndSaveScreenAsPDF();
        pdfS = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(!pdfD && key=='s'){
        pdfS = true;
    }
    if(key=='g'){
        pdfD = !pdfD;
        if(pdfD){
            ofSetFrameRate(15);
            ofBeginSaveScreenAsPDF("rec-"+ofGetTimestampString()+".pdf",true);
        }else{
            ofEndSaveScreenAsPDF();
            ofSetFrameRate(60);
            
        }
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
