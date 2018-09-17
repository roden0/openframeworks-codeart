#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    glEnable(GL_DEPTH);
    
    ofSetSmoothLighting(true);
    ofSetSphereResolution(32);
    
    esfera.setRadius(100);
    punto.setDiffuseColor(ofFloatColor(.8,.8,.9));
    punto.setPosition(1,1,1);
    
    float wi = ofGetWidth();
    float he = ofGetHeight();
    
    stlImporter.loadSTL(ofToDataPath("faces.stl"));
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    punto.enable();
    
//    for (int i = 0; i<200; i+=10) {
//        for (int j = 0; j<100; j+=7) {
//            caja.setPosition(i*-10, j*-50, i*100);
//            caja.draw();
//            esfera.setPosition(i*40,j*40,i*40);
//            esfera.draw();
//            icosp.setPosition(j*20, i*-30, j*60);
//            icosp.draw();
//        }
//    }
    
    ofSetColor(120, 0, 70);
//    plano.setPosition(ofGetWidth()*.5, ofGetHeight()*.5, 0);
//    plano.rotate(sin(ofGetElapsedTimef()*.35f),1,0,0);
//    plano.drawWireframe();
    
    stlImporter.rescaleModel(1600);
    stlImporter.drawWireFrame();
    //stlImporter.drawFacets();
    
    cam.end();
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
