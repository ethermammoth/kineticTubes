#include "kineticTubes.h"

//--------------------------------------------------------------
void kineticTubes::setup()
{
    ofBackground(10, 10, 10);
    mainSettings = new ktSettings();
    mainSettings->setup();
    
    mainUI = new ktMainUI();
    mainUI->setup( ofGetWindowWidth(), ofGetWindowHeight(), *mainSettings);
    
    previewGL = new ktPreviewGL();
    previewGL->setup();
    previewGL->setViewport(mainUI->getMainView());
    previewGL->setTubes(*mainSettings);
    
    testData = new ktData();
    testData->setup(*mainSettings);
    
    ofAddListener(ktEvent::events, this, &kineticTubes::guiSettingsEvent);
    
}

//--------------------------------------------------------------
void kineticTubes::update()
{
    if( mainUI->getActive() == "PREVIEW" )
    {
        testData->update();
    }
}

//--------------------------------------------------------------
void kineticTubes::draw()
{
    previewGL->draw(mainUI->getActive(), testData->getData());
    string posStr = "FPS: " + ofToString(ofGetFrameRate(), 0);
    ofDrawBitmapStringHighlight(posStr, 700, 20);
}

void kineticTubes::guiSettingsEvent(ktEvent &e)
{
    string name = e.message;
    cout << "kinetic Tubes: " << name << endl;
}

//--------------------------------------------------------------
void kineticTubes::keyPressed(int key)
{

}

//--------------------------------------------------------------
void kineticTubes::keyReleased(int key)
{

}

//--------------------------------------------------------------
void kineticTubes::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void kineticTubes::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void kineticTubes::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void kineticTubes::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void kineticTubes::windowResized(int w, int h)
{
    mainUI->resize(w, h);
    previewGL->setViewport(mainUI->getMainView());
}

//--------------------------------------------------------------
void kineticTubes::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void kineticTubes::dragEvent(ofDragInfo dragInfo)
{

}

//--------------------------------------------------------------
void kineticTubes::exit()
{
    mainUI->exit();
    previewGL->exit();
    mainSettings->exit();
    
    delete mainUI;
    delete previewGL;
    delete mainSettings;
}