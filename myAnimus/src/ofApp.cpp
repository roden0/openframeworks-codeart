#include "ofApp.h"

const int N = 256;
float spectrum[N];
float Rad = 100;
float Vel = 0.5;
int bandRad = 2;
int bandVel = 100;

const int n = 100;
float tx[n], ty[n];
ofPoint p[n];
float time0 = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    sound.load("misiles.mp3");
    sound.setLoop(true);
    sound.play();
    
    for (int i=0; i<N; i++) {
        spectrum[i] = 0.0f;
    }
    
    for ( int j=0; j<n; j++ ) {
        tx[j] = ofRandom( 0, ofGetWidth() );
        ty[j] = ofRandom( 0, ofGetHeight() );
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    float *val = ofSoundGetSpectrum( N );
    
    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.09;    //Slow decreasing
        spectrum[i] = max( spectrum[i], val[i] );
    }
    
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp( dt, 0.0, 0.1 );
    time0 = time;
    
    Rad = ofMap(spectrum[bandRad], 1, 3, 400, 800);
    Vel= ofMap(spectrum[bandVel], 0, 0.1, 0, 1);
    
    for (int z=0; z<N; z++) {
        tx[z]+=Vel*dt;
        ty[z]+=Vel*dt;
        
        p[z].x= ofSignedNoise(tx[z])*Rad;
        p[z].y= ofSignedNoise(ty[z])*Rad;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 125);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //ofPushMatrix();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
    
    ofFill();
    for (int i=0; i<n; i++) {
        ofSetColor( ofRandom(50), 0, ofRandom(200),ofRandom(50));
        ofDrawCircle( p[i], 100 );
        
    }
    ofPopMatrix();

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
