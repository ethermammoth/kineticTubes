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

class ktSettings
{
public:
    void setup();
    void exit();
    
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
    
    //IP Settings
    string mainIp;
    
};

#endif
