//
//  ktMainUI.h
//  kineticTubes
//
//  Created by Rasmus on 7/4/13.
//
//

#ifndef kineticTubes_ktMainUI_h
#define kineticTubes_ktMainUI_h

#include "ofMain.h"
#include "ofxUI.h"

class ktMainUI
{
public:
    
    void setup(int _width, int _height);
    void resize(int _width, int _height);
    void exit();
    string getActive(){ return activeView; }
    ofRectangle getMainView();
    
private:
    //functions
    void guiEvent(ofxUIEventArgs &e);
    
    //variables    
    int width, height;
    int mainTheme;
    string activeView;
    ofRectangle mainView;
    
    //Main Bar
    ofxUICanvas *guiTopbar;
    float topHeightPerc;
    
    //SUB UIs / canvas
    ofxUICanvas *guiSettings;
    ofxUICanvas *guiStatus;
    ofxUICanvas *guiPreview;
    float mainHeightPerc;
};



#endif
