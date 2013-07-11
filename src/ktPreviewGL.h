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
#include "ktSettings.h"
#include "ktData.h"

class ktPreviewGL
{
public:
    void setup();
    void draw(string _activeView, vector<Tube>);
    void exit();
    void setViewport(ofRectangle _viewport);
    void setTubes(ktSettings _settings);
    
private:
    void drawTubes(vector<Tube>&);
    void initPositions(int _x, int _y, int _xx, int _yy, float _spacing);
    ofRectangle viewport;
    ofEasyCam camera;
    vector <ofPoint> tubePositions;
    ofPoint tubeScale;
    
    ofPoint tubesCenter;
    
    ofLight mainLight;
    ofMaterial tubeEnabledMat;
    ofMaterial tubeDisabledMat;
    
};


#endif
