//
//  ktTestData.h
//  kineticTubes
//
//  Created by Rasmus on 7/8/13.
//
//  Generates some Test Data Just for Testing

#ifndef kineticTubes_ktTestData_h
#define kineticTubes_ktTestData_h
#include "ofMain.h"
#include "ktSettings.h"

struct Tube
{
    float value;
    bool enabled;
};

class ktData
{
public:
    void setup(ktSettings _settings);
    void update();
    
    vector<Tube> getData();
    
private:
    
    vector<Tube> tubes;
    float val;
    float startVal;
    float stopVal;
    bool up;
    
};


#endif
