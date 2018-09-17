#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(20, 20, 20);
    ofSetBackgroundAuto(true);
    
    //Example 1
//    ofVec2f initLoc = ofVec2f(ofGetWidth()/2,10);
//    particle = Particle(initLoc);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //example 2
    ofVec2f initLoc = ofVec2f(mouseX,mouseY);
    Particle p = Particle(initLoc);
    particles.push_back(p);

}

//--------------------------------------------------------------
void ofApp::draw(){
    //Example 1
//    particle.run();
//    if(particle.isDead()){
//        ofLog(OF_LOG_NOTICE,"dead particle");
//    }
    
    //Example 2
    for (std::vector<Particle>::iterator iter = particles.begin();
         iter != particles.end();
         ++iter) {
        (*iter).run();
        if((*iter).isDead()){
            particles.erase(iter);
        }
    }

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
