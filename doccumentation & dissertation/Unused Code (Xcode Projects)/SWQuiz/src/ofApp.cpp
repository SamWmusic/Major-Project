#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBuffer buffer = ofBufferFromFile("yoda-corpus.csv");
    for (auto line : buffer.getLines()){
        linesOfTheFile.push_back(line);
    };
    
    
    cout  << linesOfTheFile[5] << endl ;
    
    cout  << linesOfTheFile.size() << endl ;
    
    string myString = linesOfTheFile[5];
    string myString2 = ",";
    
    for (int i=1; i < linesOfTheFile.size(); i++) {
        
        peices = ofSplitString(linesOfTheFile[i], ",");
        
        if (peices[peices.size()-1] != "action"){
            usefullLines.push_back(linesOfTheFile[i]);
        }
        
        peices.clear();
    }
    
    
    for (int i=1; i < usefullLines.size(); i++) {
        
        
        peices = ofSplitString(usefullLines[i], ",");
        
        
        
        p = peices[5][0];
        
        
        if(p == space){
            s = peices[4]+","+peices[5];
            quote.push_back(s);
        } else {
            quote.push_back(peices[4]);
        }
        
        character.push_back(peices[3]);
        
        //   cout << "Tasty veg = " << quote[i-1] << endl;
        
    }
    cout << "Tasty veg = " << quote.size() << endl;
    question = 4;
    cout << "Tasty veg = " << quote[question] << endl;
    cout << "Tasty veg = " << character[question] << endl;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
