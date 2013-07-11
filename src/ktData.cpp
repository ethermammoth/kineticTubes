//
//  ktTestData.cpp
//  kineticTubes
//
//  Created by Rasmus on 7/8/13.
//
//

#include "ktData.h"


void ktData::setup(ktSettings _settings)
{
    for(int x=0; x<_settings.getTileTotalSize(); x++)
    {
        bool en = false;
        float s = ofRandom(0.f, 1.f);
        
        if(s > 0.5f)
            en = true;
        
        Tube tub = { 0.f, en };
        tubes.push_back(tub);
    }
    
    startVal = 0.f;
    stopVal = 1.f;
    val = 0.f;
    up = true;
}

void ktData::update()
{
    //manipulate the data in some way
    for(int x=0; x<tubes.size(); x++)
    {
        if(tubes[x].enabled)
        {
            if(up)
                val += 0.001f * (ofGetLastFrameTime());
            else
                val -= 0.001f * (ofGetLastFrameTime());
            
            tubes[x].value = ofLerp(startVal, stopVal, val);
            
            if(val >= 1.f)
                up = false;
            
            if(val <= 0.f)
                up = true;
        }
    }
}

vector<Tube> ktData::getData()
{
    return tubes;
}