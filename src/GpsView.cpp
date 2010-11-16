/*=======================================================
 Copyright (c) avp::ptr, 2010
=======================================================*/

#include "GpsView.h"


GpsView::GpsView(void) : 
	m_gpsData(0),
	m_walk(0)
{
}


GpsView::~GpsView(void)
{
	if(m_walk)
		m_walk = 0;
	if(m_gpsData)
		m_gpsData = 0;
}


void GpsView::setGpsData(GpsData* gpsData)
{
	m_gpsData = 0;
	m_gpsData = gpsData;
}


void GpsView::setWalk(Walk* walk)
{
	m_walk = walk;
}