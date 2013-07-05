#include "kineticTubes.h"

//--------------------------------------------------------------
void kineticTubes::setup()
{
    ofBackground(0);
    mainSettings = new ktSettings();
    mainSettings->setup();
    
    mainUI = new ktMainUI();
    mainUI->setup( ofGetWindowWidth(), ofGetWindowHeight() );
    
    previewGL = new ktPreviewGL();
    previewGL->setup();
    previewGL->setViewport(mainUI->getMainView());
}

//--------------------------------------------------------------
void kineticTubes::update()
{

}

//--------------------------------------------------------------
void kineticTubes::draw()
{
    previewGL->draw(mainUI->getActive());
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