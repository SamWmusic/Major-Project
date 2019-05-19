#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    dimentions = 700;
    moveX=0;
    moveY=0;
    drag=false;
    check=false;
    returnSpeedX = returnSpeedY = 0;
    initialSpeed = 40;
    rotation = 0;
    
    
    currentX = ofGetWidth()/2-dimentions/2;
    currentY = ofGetHeight()/2-dimentions/2;
    desiredCx=ofGetWidth()/2-dimentions/2;
//    ofVec2f current(ofGetWidth()/2-dimentions/2,ofGetHeight()/2-dimentions/2);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    ofSetColor(col);
    
    counter ++;
    if (counter == 5){
        col.setHsb(0, 225, 0);
    }
    
    ofTranslate(mouseX,mouseY);
    ofRotateRad(rotation);
    ofTranslate(-mouseX,-mouseY);
    //ofRotate(50, 0, 0, 1);
    ofDrawRectangle(currentX, currentY, dimentions, dimentions);
    //ofRotate(-50, 0, 0, 1);
    ofTranslate(mouseX,mouseY);
    ofRotateRad(-rotation);
    ofTranslate(-mouseX,-mouseY);
    
    
    ofDrawLine(ofGetWidth()*0.65, 0, ofGetWidth()*0.65, ofGetHeight());
    ofDrawLine(ofGetWidth()*0.35, 0, ofGetWidth()*0.35, ofGetHeight());
    
    
    
    //desiredCy=ofGetHeight()/2-dimentions/2;
//
//    cout << "returnSpeedX is" << returnSpeedX << endl;
//    cout << "currentX is" << currentX << endl;
//    cout << "desiredCx is" << desiredCx-returnSpeedX << endl;
//
//    cout << "moveX is" << moveX << endl;
    
    
    
    //returnSpeedX+= 2;
    //(check && desiredCx-returnSpeedX/2 < currentX) ||
    
//    if ((check && desiredCx < currentX)){
//
//        currentX+= returnSpeedX;
//
//    }
    
//    else if (check && desiredCx > currentX){
//        currentX+= returnSpeedX;
//    }

//    if (desiredCx-returnSpeedX/2 < currentX && desiredCx+returnSpeedX/2+1 > currentX){
//        currentX= desiredCx;
//        moveX = 0;
//    }
//
//    if (check && desiredCy < currentY){
//        currentY-= returnSpeedY;
//    } else if (check && desiredCy > currentY){
//        currentY+= returnSpeedY;
//    }
//
//    if (check && desiredCy-returnSpeedY/2 < currentY && desiredCy+returnSpeedY/2+1 > currentY){
//        currentY= desiredCy;
//        moveY = 0;
//    }

//    if (moveX == 0 ){ // && moveY == 0
//        check = false;
//        //returnSpeedX = initialSpeed;
//        //returnSpeedY = initialSpeed;
//    }
    
    if(!drag){
        

  //       && currentX+dimentions/2 < ofGetWidth()*0.75
        if (moveX != 0 && currentX <= ofGetWidth()*0.65
            && currentX+dimentions >= ofGetWidth()*0.35){
            moveX-= (moveX/10);
        } else if (currentX > ofGetWidth()*0.65){ //moveX != 0 &&
            
            moveX= moveX+((ofGetWidth()-moveX)/10-16);
            
            if (currentX > ofGetWidth()){
                col.setHsb(100, 255, 205);
                moveX =0;
                counter = 0;
            }
        }
        
        else if (currentX+dimentions < ofGetWidth()*0.35){
            
            moveX= moveX+((ofGetWidth()-moveX)/10-189);
            
            if (currentX + dimentions < 0){
                col.setHsb(0, 255, 205);
                moveX =0;
                counter = 0;
            }
            
            
 //           cout << "heyy" << endl;
            
            
            
        //--------------------------------------------------------------
        //    moveX+= ((0+moveX)/10-30); // FIX THIS!!!
        //--------------------------------------------------------------
            
            
            
//            moveX--;
        }
        
        

        if (moveY != 0){
            moveY-= (moveY/10);
        }
        
    }
    
    currentX = moveX+ofGetWidth()/2-dimentions/2;
    currentY = moveY+ofGetHeight()/2-dimentions/2;
    

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if(drag){
        //rotation = -moveX/1000;
        
//        moveX+= x-ofGetPreviousMouseX();
//        moveY+= y-ofGetPreviousMouseY();
//        currentX = moveX+ofGetWidth()/2-dimentions/2;
//        currentY = moveY+ofGetHeight()/2-dimentions/2;
        
        
        
        
    }
    
    if(drag){
        moveX+= ofGetMouseX()-ofGetPreviousMouseX();
        moveY+= ofGetMouseY()-ofGetPreviousMouseY();
    }
    
    
    //moveY+= y-ofGetPreviousMouseY();
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if(currentX<x && x<currentX+dimentions
       && currentY<y && y<currentY+dimentions){
        drag=true;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

//    if (check==false){
//        returnSpeedX = (desiredCx - currentX)/initialSpeed;
//    }
    drag=false;
//    check=true;
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
