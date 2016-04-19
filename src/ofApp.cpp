#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0, 0);
    
    fboR.allocate(ofGetWidth(), ofGetHeight());
    fboR.begin();
    ofClear(0, 0, 0, 0);
    fboR.end();
    
    fboG.allocate(ofGetWidth(), ofGetHeight());
    fboG.begin();
    ofClear(0, 0, 0, 0);
    fboG.end();
    
    fboB.allocate(ofGetWidth(), ofGetHeight());
    fboB.begin();
    ofClear(0, 0, 0, 0);
    fboB.end();
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    ofClear(0, 0, 0, 0);
    fbo.end();
    
    blendMode = OF_BLENDMODE_ADD;
    blendModeString = "add";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableBlendMode(blendMode);
    
    ofDrawBitmapString("draw fboR/fboG/fboB", ofPoint(20, 20));
    fboR.begin();
    ofClear(0, 0, 0, 0);
    ofSetColor(255, 0, 0, 200);
    ofCircle(100, 100, 100);
    fboR.end();
    ofSetColor(255, 255, 255, 255);
    fboR.draw(0, 0);

    fboG.begin();
    ofClear(0, 0, 0, 0);
    ofSetColor(0, 255, 0, 200);
    ofCircle(150, 100, 100);
    fboG.end();
    ofSetColor(255, 255, 255, 255);
    fboG.draw(0, 0);

    fboB.begin();
    ofClear(0, 0, 0, 0);
    ofSetColor(0, 0, 255, 200);
    ofCircle(125, 150, 100);
    fboB.end();
    ofSetColor(255, 255, 255, 255);
    fboB.draw(0, 0);

    
    ofPushMatrix();
    ofTranslate(500, 0);
    
    ofDrawBitmapString("draw fboR/fboG/fboB INSIDE fbo", ofPoint(20, 20));
    fbo.begin();
    ofClear(0, 0, 0, 0);
    
    ofSetColor(255, 0, 0, 200);
    ofCircle(100, 100, 100);
    
    ofSetColor(0, 255, 0, 200);
    ofCircle(150, 100, 100);
    
    ofSetColor(0, 0, 255, 200);
    ofCircle(125, 150, 100);
    
    fbo.end();
    
    ofSetColor(255, 255, 255, 255);
    fbo.draw(0, 0);
    ofPopMatrix();
    
    
    ofDisableBlendMode();
    
    ofDrawBitmapString(blendModeString, ofPoint(10, 100));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 49:
            blendMode = OF_BLENDMODE_ALPHA;
            blendModeString = "Alpha";
            break;
        case 50:
            blendMode = OF_BLENDMODE_ADD;
            blendModeString = "Add";
            break;
        case 51:
            blendMode = OF_BLENDMODE_MULTIPLY;
            blendModeString = "multiply";
            break;
        case 52:
            blendMode = OF_BLENDMODE_SUBTRACT;
            blendModeString = "subtract";
            break;
        case 53:
            blendMode = OF_BLENDMODE_SCREEN;
            blendModeString = "screen";
            break;
        default:
            break;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
