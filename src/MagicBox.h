/*==========================================================
 Copyright (c) avp::ptr, 2010
 ==========================================================*/

#ifndef _MAGICBOX_H_
#define _MAGICBOX_H_

#include "GpsData.h"

class MagicBox
{
public:

    MagicBox(AppSettings* settings, double size, double padding);
    ~MagicBox();

    bool isInBox(const ofxPoint<double> utmPoint);

    const ofxPoint<double> getDrawablePoint(const UtmPoint& utmPoint);

    void setupBox(ofxPoint<double> currUtm, double lon0);
    void setupBoxStatic(ofxPoint<double> currUtm, double lon0, double width, double height);

    void updateBoxIfNeeded(const ofxPoint<double> utmPoint);

    void updateBoxSize(double size);

    void addToBoxSize(double sizeToAdd);

    void setSize(double newSize);
    void setCenter(double x, double y);

    const ofxRectangle<double>& getTheBox() const { return m_theBox; }
    const ofxRectangle<double> getNormalizedBox();
    const ofxRectangle<double>& getPaddedBox() const { return m_theBox; }
    const ofxRectangle<double> getNormalizedPaddedBox();
    const ofxPoint<double>& getCenter() const {return m_centerUtm; }
    const GpsPoint getCenterGps() const;
    const double getSize() const { return m_currentSize; }

    void toggleZoomLevel(unsigned int zoomLevel);

    void goUp(double val);
    void goDown(double val);
    void goLeft(double val);
    void goRight(double val);

private:

    bool isInPaddedBox(const ofxPoint<double> utmPoint);

    void setBoxes();
    // ist auch m_lon0
    ofxPoint<double> m_centerUtm;

    ofxRectangle<double> m_theBox;
    ofxRectangle<double> m_paddedBox;

    AppSettings* m_settings;
    double m_currentSize;

    double m_padding;

    static double m_zoomLevels[4];

    double m_defaultSize;

    static int m_boxNum;

    int m_boxId;
};

#endif // _MAGICBOX_H_
