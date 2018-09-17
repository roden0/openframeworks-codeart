#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(127, 127, 127);
    fbo_color = ofColor(0);
    ttf.load("adobo.ttf", 80);
    string s = "this is\n particleland\n the place where\n particles collide";
    
    ofFbo fbo;
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    pix.allocate(ofGetWidth(), ofGetHeight(), OF_PIXELS_RGBA);
    fbo.begin();
    ofClear(0, 0, 0, 0);
    ofRectangle r = ttf.getStringBoundingBox(s, 0, 0);
    ofVec2f offset = ofVec2f(floor(-r.x - r.width * 0.5f), floor(-r.y - r.height * 0.5f));
    ofSetColor(fbo_color);
    ttf.drawString(s, fbo.getWidth() / 2 + offset.x, fbo.getHeight() / 2 + offset.y);
    fbo.end();
    
    fbo.readToPixels(pix);
    
    pdfS = false;
    pdfD = false;

}

//--------------------------------------------------------------
void ofApp::update(){
    addCircles(200);
    for (int i=0; i< circles.size(); i++) {
        circles[i]->update();
        circles[i]->superp(circles);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(pdfS){
        ofBeginSaveScreenAsPDF("scn_"+ofGetTimestampString()+".pdf",false);
    }
    
    for (int i = 0; i < circles.size(); i++) {
        circles[i]->display();
    }
    
    if(pdfS){
        ofEndSaveScreenAsPDF();
        pdfS = false;
    }
}

//--------------------------------------------------------------
void ofApp::addCircles(int num){
    for(int i = 0; i < num; i++){
        
        int x = (int)ofRandom(ofGetWidth());
        int y = (int)ofRandom(ofGetHeight());
        
        ofColor c = pix.getColor(x, y);
        bool inText = (c == fbo_color);
        if(inText){
            bool overlap = false;
            for(int i = 0; i < circles.size(); i++){
                if(ofDist(x, y, circles[i]->x, circles[i]->y) <= circles[i]->radius + 2){overlap = true;
                    break;
                }
            }
            if(!overlap){
                Circle * c = new Circle();
                c->setup(x, y);
                circles.push_back(c);
            }
        }
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
