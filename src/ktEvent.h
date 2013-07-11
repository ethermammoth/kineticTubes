//
//  ktEvent.h
//  kineticTubes
//
//  Created by Rasmus on 7/9/13.
//
//

#ifndef kineticTubes_ktEvent_h
#define kineticTubes_ktEvent_h
#include "ofMain.h"

class ktEvent : public ofEventArgs
{
public:
    
    string message;
    
    ktEvent(){
        message = "";
    }
    
    ktEvent(string _message){
        message = _message;
    }
    
    
    static ofEvent<ktEvent> events;
};



#endif
