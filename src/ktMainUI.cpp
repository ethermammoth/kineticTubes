//
//  ktMainUI.cpp
//  kineticTubes
//
//  Created by Rasmus on 7/4/13.
//
//

#include "ktMainUI.h"


void ktMainUI::setup(int _width, int _height, ktSettings& settingsref)
{
    settings = &settingsref;
    
    //colors
    mainTheme = OFX_UI_THEME_BERLIN;
    width = _width;
    height = _height;
    
    topHeightPerc = 0.1f;
    mainHeightPerc = 1.0f - topHeightPerc;
    
    mainView.x = 0;
    mainView.y = height * topHeightPerc;
    mainView.width = width;
    mainView.height = height * mainHeightPerc;
    
    /* ------TOPBAR------
     * All Settings and Buttons for the top bar
     * This which UI is shown and active
     */
    
    guiTopbar = new ofxUITabBar();
    guiTopbar->setWidth(width);
    guiTopbar->setHeight(height * topHeightPerc);
    guiTopbar->setFont("GUI/archivo.ttf");
    guiTopbar->setFontSize(OFX_UI_FONT_LARGE, 14);
    guiTopbar->setFontSize(OFX_UI_FONT_MEDIUM, 12);
    guiTopbar->setFontSize(OFX_UI_FONT_SMALL, 10);
    guiTopbar->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
    guiTopbar->setTheme(mainTheme);
    guiTopbar->setWidgetFontSize(OFX_UI_FONT_SMALL);
    
    //Topbar Buttons
    guiTopbar->addLabelButton("PREVIEW", false, 100.0f);
    guiTopbar->addLabelButton("SETTINGS", false, 100.0f);
    guiTopbar->addLabelButton("STATUS", false, 100.0f);
    
    ofAddListener(guiTopbar->newGUIEvent, this, &ktMainUI::guiTopbarEvent);
    
    /* ------Settings Page------
     * 
     * 
     */
    guiSettings = new ofxUICanvas(0, height * topHeightPerc, width, height * mainHeightPerc);
    guiSettings->setName("SETTINGS");
    guiSettings->setFont("GUI/archivo.ttf");
    guiSettings->setTheme(mainTheme);
    guiSettings->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
    guiSettings->addWidgetRight(new ofxUILabel(("SETTINGS"), OFX_UI_FONT_LARGE));
    guiSettings->addSpacer();
    guiSettings->addWidgetDown(new ofxUILabel(("Modules (4*4) XY"), OFX_UI_FONT_MEDIUM));
    
    //Sliders for Tile settings
    tilesX = new ofxUISlider("Tiles X", 1, 40, settings->getTilesX(), 200, 15);
    tilesY = new ofxUISlider("Tiles Y", 1, 40, settings->getTilesY(), 200, 15);
    changeButton = new ofxUILabelButton("APPLY", false, 80);
    overrideToggle = new ofxUIToggle("Override TCP", true, 15, 15);
    guiSettings->addWidgetDown(tilesX);    
    guiSettings->addWidgetRight(tilesY);
    guiSettings->addWidgetRight(overrideToggle);
    guiSettings->addWidgetRight(changeButton);
    
    guiSettings->setVisible(false);
    
    ofAddListener(guiSettings->newGUIEvent, this, &ktMainUI::guiSettingsEvent);
    
    /* ------Status Page------
     *
     *
     */
    guiStatus = new ofxUICanvas(0, height * topHeightPerc, width, height * mainHeightPerc);
    guiStatus->setName("STATUS");
    guiStatus->setTheme(mainTheme);
    guiStatus->addWidgetRight(new ofxUILabel(("status"), OFX_UI_FONT_MEDIUM));
    guiStatus->setVisible(false);
    
    /* ------Preview Page------
     *
     *
     */
    guiPreview = new ofxUICanvas(0, height * topHeightPerc, width, height * mainHeightPerc);
    guiPreview->setName("PREVIEW");
    guiPreview->setTheme(mainTheme);
    guiPreview->addWidgetRight(new ofxUILabel(("preview"), OFX_UI_FONT_MEDIUM));
    guiPreview->setVisible(true);
    
    activeView = "PREVIEW";
    
}

void ktMainUI::exit()
{
    guiTopbar->saveSettings("GUI/guiSettings.xml");
    
    delete guiTopbar;
    delete guiSettings;
    delete guiStatus;
    delete guiPreview;
}

void ktMainUI::guiTopbarEvent(ofxUIEventArgs &e)
{
    string name = e.widget->getName();
    int kind = e.widget->getKind();
    cout << "got event from: " << name << endl;
    
    if(name == "PREVIEW" && activeView != name)
    {
        activeView = name;
        guiPreview->setVisible(true);
        guiSettings->setVisible(false);
        guiStatus->setVisible(false);
    }
    else if(name == "SETTINGS" && activeView != name)
    {
        activeView = name;
        guiPreview->setVisible(false);
        guiSettings->setVisible(true);
        guiStatus->setVisible(false);
    }
    else if(name == "STATUS" && activeView != name)
    {
        activeView = name;
        guiPreview->setVisible(false);
        guiSettings->setVisible(false);
        guiStatus->setVisible(true);
    }
}

void ktMainUI::guiSettingsEvent(ofxUIEventArgs &e)
{
    string name = e.widget->getName();
    int kind = e.widget->getKind();
    cout << "got event from: " << name << endl;
    
    if(name == "APPLY")
    {
        ktEvent settingEvent;
        settingEvent.message = "SETTINGS";
        ofNotifyEvent(ktEvent::events, settingEvent);
    }
    
}

void ktMainUI::resize(int _width, int _height)
{
    mainView.y = _height * topHeightPerc;
    mainView.width = _width;
    mainView.height = _height * mainHeightPerc;
    
    guiTopbar->setDimensions(_width, _height * topHeightPerc);
    guiStatus->setPosition(0, _height * topHeightPerc);
    guiStatus->setDimensions(_width, _height * mainHeightPerc);
    guiSettings->setPosition(0, _height * topHeightPerc);
    guiSettings->setDimensions(_width, _height * mainHeightPerc);
    guiPreview->setPosition(0, _height * topHeightPerc);
    guiPreview->setDimensions(_width, _height * mainHeightPerc);
}

ofRectangle ktMainUI::getMainView()
{
    return mainView;
}