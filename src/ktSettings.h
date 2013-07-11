//
//  ktSettings.h
//  kineticTubes
//
//  Created by Rasmus on 7/5/13.
//
//

#ifndef kineticTubes_ktSettings_h
#define kineticTubes_ktSettings_h

#include "ofMain.h"
#include "ktEvent.h"

class ktSettings
{
public:
    void setup();
    void exit();
    void setTiles(int _tilesX, int _tilesY);
    
    void guiSettingsEvent(ktEvent &e);
    
    //getters
    int getTilesX() { return tilesX; };
    int getTilesY() { return tilesY; };
    int getTileSizeX() { return tileSizeX; };
    int getTileSizeY() { return tileSizeY; };
    int getTileTotalSize() { return arraySize; };
    ofPoint getScale() { return ofPoint(tubeScaleX, tubeScaleY, tubeHeight); };
    float getSpacing() { return tubeSpacing; };
    float getMaxHeight() { return tubeMaxHeight; };
    
private:
    
    /* ------Module Data Settings------ */
    //How many modules do we have (X*Y)
    int tilesX;
    int tilesY;
    //Each tiles Size
    //This is for future changes if
    //it should change in the hardware
    int tileSizeX;
    int tileSizeY;
    //The resulting array size
    int arraySize;
    
    //soft settings for tubes
    float tubeSpacing;
    float tubeHeight;
    float tubeScaleX;
    float tubeScaleY;
    float tubeMaxHeight;
        
    //IP Settings
    string mainIp;
    
};

#endif
