//
//  ktMainUI.cpp
//  kineticTubes
//
//  Created by Rasmus on 7/4/13.
//
//

#include "ktMainUI.h"


void ktMainUI::setup(int _width, int _height)
{
    //colors
    colorFill = ofxUIColor(200);
    colorFillHighlight = ofxUIColor(255);
    colorBack = ofxUIColor(0,0,0,150);
    mainTheme = OFX_UI_THEME_HIPSTER;
    
    width = _width;
    height = _height;    
    
    topbar = new ofxUITabBar();
    topbar->setWidth(width);
    topbar->setHeight(height);
    topbar->setFont("GUI/archivo.ttf");
    topbar->setFontSize(OFX_UI_FONT_LARGE, 14);
    topbar->setFontSize(OFX_UI_FONT_MEDIUM, 12);
    topbar->setFontSize(OFX_UI_FONT_SMALL, 10);
    topbar->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
    topbar->setTheme(mainTheme);
    
    //content
    //SETTINGS
    guiSettings = new ofxUICanvas(0, height, width, ofGetWindowHeight() - height);
    guiSettings->setName("SETTINGS");
    guiSettings->setTheme(mainTheme);
    
    guiSettings->addWidgetRight(new ofxUILabel(("setting canvas"), OFX_UI_FONT_MEDIUM));
    
    //STATUS
    guiStatus = new ofxUICanvas(0, height, width, ofGetWindowHeight() - height);
    guiStatus->setName("STATUS");
    guiStatus->setTheme(mainTheme);
    
    guiStatus->addWidgetRight(new ofxUILabel(("setting status"), OFX_UI_FONT_MEDIUM));
    
    //PREVIEW
    guiPreview = new ofxUICanvas(0, height, width, ofGetWindowHeight() - height);
    guiPreview->setName("PREVIEW");
    guiPreview->setTheme(mainTheme);
    
    guiPreview->addWidgetRight(new ofxUILabel(("setting preview"), OFX_UI_FONT_MEDIUM));
    
    topbar->addCanvas(guiSettings);
    topbar->addCanvas(guiStatus);
    topbar->addCanvas(guiPreview);
    
}

void ktMainUI::exit()
{
    delete topbar;
}

void ktMainUI::guiEvent(ofxUIEventArgs &e)
{
    
}

void ktMainUI::resize(int _width, int _height)
{
    topbar->setDimensions(_width, _height);
}