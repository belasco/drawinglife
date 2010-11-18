/*=======================================================
 Copyright (c) avp::ptr, 2010
=======================================================*/

#include "HoursStatistics.h"


HoursStatistics::HoursStatistics( const unsigned int screenWidth, const unsigned int screenHeight) :
	LiveStatistics( screenWidth, screenHeight)
{
	// Initialize the hour histogram with zeros.
	for (unsigned int hourIndex = 0; hourIndex < HOURS_PER_DAY; ++hourIndex)
	{
		m_histogram[hourIndex] = 0;
	}
}


HoursStatistics::~HoursStatistics( void)
{
	// Nothing to delete.
}


void HoursStatistics::drawHistogram( void)
{
	// Draw a line for each hour.
	//---------------------------

	double top = m_positionCoordinates.y;
	double bottom = top + m_height;
	double left = m_positionCoordinates.x;
	double right = left + m_width;
	// Spacer line above the bottom.
	double yPosSpacerLine = bottom - MIN_HEIGHT;

	// General horizontal offset to evenly distribute lines and texts.
	double xOffset = m_width / ( HOURS_PER_DAY + 1);
	// Horizontal position of the line and the text.
	double xPosLine = left + xOffset;
	// Position of the text at the bottom of the line. Relative to the lower boundary of the view.
	double yPosTextBottom = bottom - 10;

	for( unsigned int hourIndex = 0; hourIndex < HOURS_PER_DAY; ++hourIndex)
	{
		// The actual value for the current hour.
		unsigned int val = m_histogram[ hourIndex];

		// Horizontal line above the bottom.
		ofSetColor( 0xff0000);
		glBegin(GL_LINE_STRIP);
		glVertex2d( left, yPosSpacerLine);
		glVertex2d( right, yPosSpacerLine);
		glEnd();

		ofSetColor( m_borderColor);

		glBegin(GL_LINE_STRIP);
		
		// Point at the bottom of the histogram line.
		glVertex2d( xPosLine, yPosSpacerLine - 1);
		
		// Point at the top of the histogram line.
		double yPosLineTop = yPosSpacerLine - 1 - val;
		glVertex2d( xPosLine, yPosLineTop);

		glEnd();

		// Centering the horizontal position of the text.		
		unsigned int xShiftValue = ( val < 10) ? 4 : ( val < 99) ? 7 : 10;
		unsigned int xShiftHour = ( hourIndex < 10) ? 4 : (hourIndex < 99) ? 7 : 10;

		// Text on top of the histogram line.
		// The actual histogram value.
		if( val > 0)
			m_fontHistogram.drawString( ofToString( (int)val), xPosLine - xShiftValue, yPosLineTop - 8);

		// Text on the bottom of the histogram line.
		// The hour value from 0 - 23.
		m_fontHistogram.drawString( ofToString( (int)hourIndex), xPosLine - xShiftHour, yPosTextBottom);
		
		// Shift horizontal position.
		xPosLine += xOffset;



	}
}


void HoursStatistics::updateHistogram( const tm date)
{
	// Create an hour histogram based on the time stamps.
	++m_histogram[ date.tm_hour];
}