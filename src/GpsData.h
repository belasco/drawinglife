/*=======================================================
 Copyright (c) avp::ptr, 2010
 =======================================================*/

#ifndef _GPSDATA_H_
#define _GPSDATA_H_

#include "DrawingLifeIncludes.h"
#include <vector>
#include <string>
#include "GpsSegment.h"


/**
 * \brief Holds a vector with segments, user and min/max values for longitude/latitude.
 *
 */
class GpsData : public boost::enable_shared_from_this<GpsData>
{

public:
    GpsData(const AppSettings& settings);
	~GpsData();

	// -----------------------------------------------------------------------------
	// Set Gps data.
	// -----------------------------------------------------------------------------
	/**
	* \brief Set values of GpsData object.
	* \param segments vecor with GpsSegments.
	* \param minLon minimum longitude value.
	* \param maxLon maximum longitude value.
	* \param minLat minimum latitude value.
	* \param maxLat maximum  latitude value.
	* \param user string with user name.
	*/
    void setGpsData(const GpsSegmentVector& segments,
                    const ofxPoint<double>& minLonLat,
                    const ofxPoint<double>& maxLonLat,
					const std::string& user);
	// -----------------------------------------------------------------------------
	// Get members.
	// -----------------------------------------------------------------------------
	/**
	 * \brief Get GpsSegment objects.
	 * \return vector with GpsSegments.
	 */
    const GpsSegmentVector& getSegments() const { return m_segments; }
	/**
	* \brief Get minimum longitude value.
	* \return minimum longitude value.
	*/
    double getMinLon() const { return m_minLonLat.x; }
	/**
	* \brief Get maximum longitude value.
	* \return maximum longitude value.
	*/
    double getMaxLon() const { return m_maxLonLat.x; }
	/**
	* \brief Get minimum latitude value.
	* \return minimum latitude value.
	*/
    double getMinLat() const { return m_minLonLat.y; }
	/**
	* \brief Get maximum latitude value.
	* \return maximum latitude value.
	*/
    double getMaxLat() const { return m_maxLonLat.y; }
	// get UTM convertd min/max values
	/**
	* \brief Get minimum UTM X value.
	* \return minimum UTM X value.
	*/
    double getMinUtmX() const { return m_minUtm.x; }
	/**
	* \brief Get maximum UTM X value.
	* \return maximum UTM X value.
	*/
    double getMaxUtmX() const { return m_maxUtm.x; }
	/**
	* \brief Get minimum UTM Y value.
	* \return minimum UTM Y value.
	*/
    double getMinUtmY() const { return m_minUtm.y; }
	/**
	* \brief Get maximum UTM Y value.
	* \return maximum UTM Y value.
	*/
    double getMaxUtmY() const { return m_maxUtm.y; }

	// -----------------------------------------------------------------------------
	/**
	* \brief Clear GpsData values.
	*/
	void clear();
	// -----------------------------------------------------------------------------
	// Get Gps point.
	// -----------------------------------------------------------------------------
	/**
	* \brief Get longitude for given GpsSegment and GpsPoint.
	* \param segmentIndex index of a GpsSegment.
	* \param pointIndex index of a GpsPoint.
	* \return longitude for given GpsSegment and GpsPoint.
	*/
    double getLongitude(size_t segmentIndex, size_t pointIndex) const;
	/**
	* \brief Get latitude for given GpsSegment and GpsPoint.
	* \param segmentIndex index of a GpsSegment.
	* \param pointIndex index of a GpsPoint.
	* \return latitude for given GpsSegment and GpsPoint.
	*/
    double getLatitude(size_t segmentIndex, size_t pointIndex) const;
	/**
	* \brief Get elevation for given GpsSegment and GpsPoint.
	* \param segmentIndex index of a GpsSegment.
	* \param pointIndex index of a GpsPoint.
	* \return elevation for given GpsSegment and GpsPoint.
	*/
    double getElevation(size_t segmentIndex, size_t pointIndex) const;
	// -----------------------------------------------------------------------------
	/**
	* \brief Get UTM X for given GpsSegment and GpsPoint.
	* \param segmentIndex index of a GpsSegment.
	* \param pointIndex index of a GpsPoint.
	* \return UTM X for given GpsSegment and GpsPoint.
	*/
    double getUtmX(size_t segmentIndex, size_t pointIndex) const;
	/**
	* \brief Get UTM Y for given GpsSegment and GpsPoint.
	* \param segmentIndex index of a GpsSegment.
	* \param pointIndex index of a GpsPoint.
	* \return UTM Y for given GpsSegment and GpsPoint.
	*/
    double getUtmY(size_t segmentIndex, size_t pointIndex) const;

    UtmPoint getUtm(size_t segmentIndex, size_t pointIndex) const;
	// -----------------------------------------------------------------------------
	/**
	* \brief Get normalized UTM X for given GpsSegment and GpsPoint.
	* \param segmentIndex index of a GpsSegment.
	* \param pointIndex index of a GpsPoint.
	* \return normalized UTM X for given GpsSegment and GpsPoint.
	*/
    double getNormalizedUtmX(size_t segmentIndex, size_t pointIndex) const;
	/**
	* \brief Get normalized UTM Y for given GpsSegment and GpsPoint.
	* \param segmentIndex index of a GpsSegment.
	* \param pointIndex index of a GpsPoint.
	* \return normalized UTM Y for given GpsSegment and GpsPoint.
	*/
    double getNormalizedUtmY(size_t segmentIndex, size_t pointIndex) const;

    UtmPoint getNormalizedUtm(size_t segmentIndex, size_t pointIndex) const;
	// -----------------------------------------------------------------------------
	/**
	* \brief Get total number of GpsPoints.
	* \return number of all GpsPoints
	*/
	int getTotalGpsPoints() const;
	//------------------------------------------------------------------------------

    /**
    * \brief Get central meridian for projection.
    * \return central meridian double value.
    */
    double getProjectionCentralMeridian() const { return m_lon0; }
    /**
    * \brief Normalize all UtmPoints to a value between 0 and 1 with global min/max values.
    */
	void normalizeUtmPointsGlobal();
    /**
    * \brief Calculate UTM values for all GpsPoints with global lon0.
    */
    void calculateUtmPointsGlobalLon(bool regionsOn);
    static UtmPoint getUtmPointWithRegion(double lat, double lon,
                                          const AppSettings& settings);

    static GpsPoint getGpsPoint(const ofxPoint<double>& utmP);

    static void setGlobalValues(const ofxPoint<double>& minXY,
                                const ofxPoint<double>& maxXY,
                                double lon0);

    const UtmDataVector& getUTMPoints() const { return m_utmPoints; }
    const UtmDataVector& getNormalizedUTMPoints() const
    { return m_normalizedUtmPoints; }
    const UtmDataVector& getNormalizedUTMPointsGlobal() const
    { return m_normalizedUtmPointsGlobal; }


	// -----------------------------------------------------------------------------
	/**
	* \brief Get location for given GpsSegment and GpsPoint.
	* \param segmentIndex index of a GpsSegment.
	* \param pointIndex index of a GpsPoint.
	* \return location for given GpsSegment and GpsPoint.
	*/
    const std::string getGpsLocation(size_t segmentIndex, size_t pointIndex) const;

	double getLon0() const { return m_lon0; }

	static double getLon0Glogal() { return GpsData::m_lon0Global; }

	const std::string& getUser() const { return m_user; }

    /**
    * \brief Calculate UTM values for all GpsPoints.
    */
    void calculateUtmPoints(double lon0);

    const GpsDataIndexVector& getIndices() const { return m_indices; }

private:

    typedef boost::function<double(const GpsPoint&)> tFnGetGpsData;
    double getData(size_t segmentIndex, size_t pointIndex,
                   const tFnGetGpsData& fnGetGpsData) const;

    typedef boost::function<double(const UtmPoint&)> tFnGetUtmData;
    double getUtmData(size_t segmentIndex, size_t pointIndex,
                      const UtmDataVector& utmVec,
                      const tFnGetUtmData& fnGetUtmData) const;
    /**
    * \brief Normalize all UtmPoints to a value between 0 and 1.
    */
	void normalizeUtmPoints();

    void normalizeUtmPoints(UtmDataVector& utmDataVec);

    /**
    * \brief Set range of min/max values to be the same (square).
    */
	void setMinMaxRatioUTM();
    /**
    * \brief Set range of global min/max values to be the same (square).
    */
	void setGlobalMinMaxRatioUTM();
    /**
    * \brief Set UTM min/max values for all GpsPoints.
    */
	void setMinMaxValuesUTM();
    /**
    * \brief Calculate UTM values for all GpsPoints.
    */
    void calculateUtmPoints();

    static ofxPoint<double> drawMaxima;
    static ofxPoint<double> drawMinima;

    static double m_lon0Global;

    const AppSettings& m_settings;
    int m_gpsDataId;
    GpsSegmentVector m_segments;
	std::string m_user;

    ofxPoint<double> m_minLonLat;
    ofxPoint<double> m_maxLonLat;
    ofxPoint<double> m_minUtm;
    ofxPoint<double> m_maxUtm;

    UtmDataVector m_utmPoints;
    UtmDataVector m_normalizedUtmPoints;
    UtmDataVector m_normalizedUtmPointsGlobal;
    double m_lon0;

    GpsDataIndexVector m_indices;
};

#endif // _GPSDATA_H_
