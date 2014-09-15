#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(32);
    
    // 画面内のランダムな場所と速度を円の数だけ指定
    for (int i = 0; i < CIRCLE_NUM; i++) {
        position[i].x = ofRandom(ofGetWidth());
        position[i].y = ofRandom(ofGetHeight());
        velocity[i].set(ofRandom(-10, 10), ofRandom(-10, 10));
        force[i].set(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // 力をリセット
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i].set(0, 0);
    }
    
    // 力の更新 (摩擦)
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i] -= velocity[i] * friction;
    }
    
    // 円の座標を全て更新
    for (int i = 0; i < CIRCLE_NUM; i++) {
        velocity[i] += force[i];
        position[i] += velocity[i];
    }
    
    // 画面からはみ出たらバウンドさせる
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (position[i].x < 0 || position[i].x > ofGetWidth()) {
            velocity[i].x *= -1;
        }
        if (position[i].y < 0 || position[i].y > ofGetHeight()) {
            velocity[i].y *= -1;
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    // 画面内のランダムな場所を円の数だけ描画
    for (int i = 0; i < CIRCLE_NUM; i++) {
        ofCircle(position[i], 5);
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
