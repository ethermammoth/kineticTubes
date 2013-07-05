//
//  ktPreviewGL.cpp
//  kineticTubes
//
//  Created by Rasmus on 7/5/13.
//
//

#include "ktPreviewGL.h"

void ktPreviewGL::setup()
{
    glEnable(GL_DEPTH_TEST);
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = 200.0f;
    viewport.height = 200.0f;
    
    camera.setDistance(20);
    camera.disableMouseInput();
}

void ktPreviewGL::draw(string _activeView)
{
    if(_activeView == "PREVIEW")
    {
        camera.begin(viewport);
        ofDrawGrid();
        camera.end();
    }
}

void ktPreviewGL::setViewport(ofRectangle _viewport)
{
    viewport = _viewport;
}


void ktPreviewGL::exit()
{
    
}