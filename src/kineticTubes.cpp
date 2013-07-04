#include "kineticTubes.h"

//--------------------------------------------------------------
void kineticTubes::setup()
{
    mainUI = new ktMainUI();
    mainUI->setup( ofGetWindowWidth(), 70 );
}

//--------------------------------------------------------------
void kineticTubes::update()
{

}

//--------------------------------------------------------------
void kineticTubes::draw()
{

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
    mainUI->resize(w, 70);
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
}