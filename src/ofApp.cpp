#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	grow.setup("lifeisgood.svg");
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    grow.update(ofMap(mouseX, 0, ofGetWidth(), 0, 1));
}

//--------------------------------------------------------------
void ofApp::draw(){
//    cam.begin();
    grow.draw();
//    ofPushMatrix();
//    ofTranslate(400, 0);
//    ofScale(-1, 1);
//    grow.draw();
//    ofPopMatrix();
//    cam.end();
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
