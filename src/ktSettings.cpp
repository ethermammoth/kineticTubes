//
//  ktSettings.cpp
//  kineticTubes
//
//  Created by Rasmus on 7/5/13.
//
//

#include "ktSettings.h"

void ktSettings::setup()
{
    //we set the tile size to 4x4
    tileSizeX = 4;
    tileSizeY = 4;
    //init to 5x5 by default - this will be set through TCP feedback
    setTiles(5, 5);
    
    //tube soft settings
    tubeSpacing = 1.0f;
    tubeScaleX = 0.6f;
    tubeScaleY = 0.6f;
    tubeHeight = 5.0f;
    tubeMaxHeight = 10.0f;
    
    ofAddListener(ktEvent::events, this, &ktSettings::guiSettingsEvent);
}

void ktSettings::exit()
{

}

void ktSettings::setTiles(int _tilesX, int _tilesY)
{
    tilesX = _tilesX;
    tilesY = _tilesY;
    
    arraySize = (tilesX * tileSizeX) * (tilesY * tileSizeY);
}

void ktSettings::guiSettingsEvent(ktEvent &e)
{
    cout << "ktSettings: " << e.message << endl;
}