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
private:
    //functions
    void guiEvent(ofxUIEventArgs &e);
    //variables
    ofxUITabBar *topbar;
    int width, height;
    int mainTheme;
    
    //color settings
    ofxUIColor colorFill;
    ofxUIColor colorFillHighlight;
    ofxUIColor colorBack;
    
    //SUB UIs / canvas
    ofxUICanvas *guiSettings;
    ofxUICanvas *guiStatus;
    ofxUICanvas *guiPreview;
};



#endif
