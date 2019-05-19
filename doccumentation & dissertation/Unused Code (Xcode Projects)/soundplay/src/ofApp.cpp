#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //play.addListener(this, &ofApp::playPressed);
    //play.addListener(this, &ofApp::stopPressed);
    play.addListener(this, &ofApp::reversePressed);
    
    gui.setup();
    //gui.add(play.setup("play"));
    //gui.add(stop.setup("stop"));
    //gui.add(reverse.setup("stop"));
    //gui.add(reverse.setup("reverse"));
    gui.add(volume.setup("volume",1.0,0.0,1.0));
    gui.add(speed.setup("speed",1,-12,12));
    
    
    
    drums.load("FKI_kane_snare_clap_loop_120.wav");
    synth.load("oe_mus120_parama_ful_G#m.wav");
    
    drums.setLoop(true);
    synth.setLoop(true);
    
    drums.play();
    synth.play();



}

void ofApp::playPressed(){
    //drums.play();
    cout << "playing";
    //synth.play();
    
}
void ofApp::stopPressed(){
    drums.stop();
    synth.stop();
    
}

void ofApp::reversePressed(){
    //drums.stop();
    //synth.stop();
    speed = -speed;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    
    drums.setVolume(volume);
    synth.setVolume(volume);
    
    drums.setSpeed(ofMap(speed, -12, 12, 0.5, 2));
    
    synth.setSpeed(ofMap(speed, -12, 12, 0.5, 2));
    


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
