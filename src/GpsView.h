/*=======================================================
 Copyright (c) avp::ptr, 2010
=======================================================*/

#ifndef _GPSVIEW_H_
#define _GPSVIEW_H_


#include "Drawable.h"
#include "GpsData.h"
#include "Walk.h"


enum Position { NORTHWEST, NORTHEAST, SOUTHWEST, SOUTHEAST, NORTH, EAST, WEST, SOUTH, CENTER };


class GpsView : public Drawable
{
public:

	/**
	 * \brief Default constructor. 
	**/
	GpsView( const unsigned int screenWidth, const unsigned int screenHeight);

	/**
	 * \brief Destructor. 
	**/
	virtual ~GpsView( void);

	/**
	 * \brief Returns a GpsData object. 
	 * \return A GpsData pointer. 
	**/
	const GpsData& getGpsData() const { return *m_gpsData; }

	/**
	 * \brief Sets the GpsData.
	 * \param gpsData A GpsData pointer.
	**/
	void setGpsData( const GpsData* gpsData);
	void setWalk( Walk* walk);
	void setPosition( const Point2D positionCoordinates);
	void setPosition( const Position position);
	void setMargin( const float margin);
	void setDimensions( const float width, const float height);
	void setDimensions( const Point2D dimensions);
	void setBackgroundColor( const ColorRGBA backgroundColor);
	void setBorderColor( const ColorRGBA borderColor);
	void setScreenDimensions( const unsigned int screenWidth, const unsigned int screenHeight);
	void setFontForHistogram( const ofTrueTypeFont fontHistogram);

protected:
	const GpsData* m_gpsData;		///< Container for gps data.
	Walk* m_walk;

	// Visual members.

	Point2D m_positionCoordinates;
	Position m_position;
	float m_width;
	float m_height;
	float m_margin;
	unsigned int m_screenWidth;
	unsigned int m_screenHeight;
	int m_backgroundColor;
	int m_borderColor;
	ofTrueTypeFont m_fontHistogram;
};


#endif // _GPSVIEW_H_