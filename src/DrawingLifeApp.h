/*=======================================================
 Copyright (c) avp::ptr, 2010
=======================================================*/

#ifndef _DRAWINGLIFEAPP_H_
#define _DRAWINGLIFEAPP_H_


#include "ofMain.h"
#include "ofxXmlSettings.h"

#include "Logger.h"
#include "DBReader.h"

/**
 *  \brief Main application class.
 */

class DrawingLifeApp : public ofBaseApp{
	
public:
	
	~DrawingLifeApp();
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);
	
	
	ofxXmlSettings m_settings;
	DBReader* m_dbReader;
	GpsData* m_gpsData;
};

#endif // _DRAWINGLIFEAPP_H_