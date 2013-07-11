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
    ofSetSmoothLighting(true);
    ofEnableSmoothing();
    
    //Light Settings
    mainLight.setDiffuseColor(ofColor(180.f, 180.f, 180.f));
	mainLight.setSpecularColor(ofColor(255.f, 255.f, 255.f));
	mainLight.setPointLight();
	//mainLight.setOrientation( ofVec3f(0, 90, 0) );
    mainLight.setPosition(10, -10, 30);
    
    //Material Setting
    tubeEnabledMat.setShininess(20);
    tubeEnabledMat.setDiffuseColor(ofColor(0.f, 255.f, 0.f));
    tubeEnabledMat.setSpecularColor(ofColor(255.f, 255.f, 255.f));
    
    tubeDisabledMat.setShininess(20);
    tubeDisabledMat.setDiffuseColor(ofColor(255.f, 0.f, 0.f));
    tubeDisabledMat.setSpecularColor(ofColor(255.f, 255.f, 255.f));
    
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = 200.0f;
    viewport.height = 200.0f;
    
    camera.setDistance(20);
    camera.setPosition(10, -10, 20);
    camera.setTarget(ofVec3f(10, -10, 0));
    camera.disableMouseInput();
    
    //Default settings
    tubeScale = ofPoint(1, 1, 5);
    tubesCenter = ofPoint(0.f, 0.f, 0.f);
    
}

void ktPreviewGL::draw(string _activeView, vector<Tube> _tubes)
{
    if(_activeView == "PREVIEW")
    {
        ofPushStyle();
        ofEnableLighting();
        mainLight.enable();
        camera.begin(viewport);
        
        //ground box
        ofPushMatrix();
        ofTranslate(tubesCenter);
        ofScale(20, 20, 0.1f);
        ofBox(0.f, 0.f, 2.5f, 1.f);
        ofPopMatrix();
        
        drawTubes(_tubes);
        camera.end();
        ofDisableLighting();
        ofPopStyle();
    }
}

void ktPreviewGL::drawTubes(vector<Tube>& _tubes)
{
    ofMaterial mat;
    for(int x=0; x < tubePositions.size(); x++)
    {
        if (_tubes[x].enabled)
            mat = tubeEnabledMat;
        else
            mat = tubeDisabledMat;
        
        ofSetColor(mat.getDiffuseColor());
        //mat.begin();
        ofPushMatrix();
        ofTranslate(tubePositions[x].x, tubePositions[x].y, ofMap(_tubes[x].value, 0.f, 1.f, -2.f, 2.5f) );
        ofScale(tubeScale.x, tubeScale.y, tubeScale.z);
        ofBox(0, 0, 0, 1);
        ofPopMatrix();
        //mat.end();
    }
}

void ktPreviewGL::setViewport(ofRectangle _viewport)
{
    viewport = _viewport;
}


void ktPreviewGL::setTubes(ktSettings _settings)
{
    tubeScale = _settings.getScale();
    initPositions(_settings.getTilesX(), _settings.getTilesY(), _settings.getTileSizeX(), _settings.getTileSizeY(), _settings.getSpacing());
}

void ktPreviewGL::initPositions(int _x, int _y, int _xx, int _yy, float _spacing)
{
    int xAmount = _x * _xx;
    int yAmount = _y * _yy;
    
    for(int y=0; y < yAmount; y++)
    {
        for(int x=0; x < xAmount; x++)
        {
            ofPoint pos = ofPoint(x + _spacing, (y + _spacing) * -1.f, 0);
            tubesCenter.x += pos.x;
            tubesCenter.y += pos.y;
            tubePositions.push_back(pos);
        }
    }
    
    tubesCenter.x = tubesCenter.x / tubePositions.size();
    tubesCenter.y = tubesCenter.y / tubePositions.size();
    
    camera.setPosition(tubesCenter.x, tubesCenter.y, 20.f);
    camera.setTarget(ofVec3f(tubesCenter.x, tubesCenter.y, 0.f));
    
    mainLight.setPosition(tubesCenter.x, tubesCenter.y, 30.f);
    
}

void ktPreviewGL::exit()
{
    
}