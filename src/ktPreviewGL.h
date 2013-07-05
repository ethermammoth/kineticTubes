//
//  ktPreviewGL.h
//  kineticTubes
//
//  Created by Rasmus on 7/5/13.
//
//

#ifndef kineticTubes_ktPreviewGL_h
#define kineticTubes_ktPreviewGL_h

#include "ofMain.h"

class ktPreviewGL
{
public:
    void setup();
    void draw(string _activeView);
    void exit();
    void setViewport(ofRectangle _viewport);
    
private:
    ofRectangle viewport;
    ofEasyCam camera;
};


#endif
