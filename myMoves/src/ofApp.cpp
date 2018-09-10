#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(8);
    ofBackground(190, 100, 125);
    rot = 10;
    pdfS = false;
    pdfD = false;
    
    font.load("gem.ttf", 80,true);
    
    posi.x= ofGetWidth()/2;
    posi.y= ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
    rot++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if(pdfS){
        ofBeginSaveScreenAsPDF("scn_"+ofGetTimestampString()+".pdf",false);
    }
    ofBackgroundGradient(ofColor::white,ofColor::cyan);
    
    ofDrawCircle(posi, 30+rot);
    ofDrawCircle(posi, 40+rot);
    ofDrawCircle(posi, 50+rot);
    ofDrawCircle(posi, 60+rot);
    
    if(ofGetFrameNum()>=50){
        for(int i=0; i<=80; i+=10){
            ofSetColor(60, 250, 120);
            ofSetLineWidth(5);
            ofDrawCircle(posi, i+rot/2);
            
        }
    }
    
    ofFill();
    ofBeginShape();
    ofSetColor(127);
    ofVertex(720, 450);
    ofVertex(500, 20);
    ofVertex(400, 330);
    ofVertex(350, 70);
    ofVertex(560, 660);
    ofEndShape(false);
    
    ofNoFill();
    ofSetColor(50,0,120);
    ofSetLineWidth(3);
    ofBeginShape();
    
    ofCurveVertex(mouseX, mouseY);
    ofCurveVertex(720, 750);
    ofCurveVertex(500, 520);
    ofCurveVertex(500, 320);
    ofCurveVertex(400, 230);
    ofCurveVertex(300*sin(rot), 230);
    
    ofEndShape();
    
    ofSetColor(255, 0, 0);
//    font.drawString("superstrings", ofGetWidth()/2,ofGetHeight()/2);
    float a = ofRandom(0,sujeto.size());
    int elSuj = int (a);
    
    a = ofRandom(0,verbo.size());
    int elVer = int (a);
    
    a = ofRandom(0,pred.size());
    int elPred = int (a);
    
    string frase = sujeto[elSuj] + " " + verbo[elVer] + " " + pred[elPred];
    
    font.drawString(frase, 50, 250);
    
    ofSleepMillis(100);
    
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
