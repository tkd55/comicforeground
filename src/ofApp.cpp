#include "ofApp.h"

#define MOVIE_INPUT_WSIZE   320
#define MOVIE_INPUT_HSIZE   240

#define MOVIE_INPUT_WSIZE_640   640
#define MOVIE_INPUT_HSIZE_480   480

//--------------------------------------------------------------
void ofApp::setup(){
    cam.initGrabber(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    
    colorImg.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    grayImage.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    
    //lets load in our face xml file
    haarFinder.setup("haarcascade_frontalface_alt2.xml");
    
    // 顔ハメ看板画像の読み込み
    myPicture.loadImage("0001.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    // カメラ入力の更新
    cam.update();
    
    // 取り込んだフレームを画像としてキャプチャ
    colorImg.setFromPixels(cam.getPixels(), MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    
    // グレースケール変換に変換
    grayImage = colorImg;
    
    // 検分器にグレースケール変換を読み込み
    haarFinder.findHaarObjects(grayImage, 10, 10);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0xffffff);
    
    // Face
    colorImg.draw(0, 0, MOVIE_INPUT_WSIZE_640, MOVIE_INPUT_HSIZE_480);
    
    //******************************
    // Face
    //******************************
    int numFace = haarFinder.blobs.size();
    float x, y, w, h;

    for(int i = 0; i < numFace; i++){
        x = haarFinder.blobs[i].boundingRect.x;
        y = haarFinder.blobs[i].boundingRect.y;
        w = haarFinder.blobs[i].boundingRect.width;
        h = haarFinder.blobs[i].boundingRect.height;
        
        glTranslatef(x-w/2, y-h, 0);
        ofEnableAlphaBlending();
        
        myPicture.draw(x, y, 290, 267);
        ofDisableAlphaBlending();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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