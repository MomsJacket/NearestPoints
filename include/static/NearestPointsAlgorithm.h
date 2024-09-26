#pragma once

#include "GeometryObjects.h"
#include "3DMathOperations.h"
#include <vector>

/**
 * @brief Checks if the projection of a point lies within the given 3D segment.
 * 
 * This function checks if the projected point is within the segment boundaries.
 * It is understood that the projected point lies on the line formed by the segment.
 *
 * @param point Projection is to be checked.
 * @param seg The 3D segment used for projection.
 * @return True if the projection lies within the segment, false otherwise.
 */
bool IsProjectionInSegment(const Point3D& point, const Segment3D& seg);


/**
 * @brief Finds the points on a 3D polyline that are closest to a given point.
 * 
 * In the case when the nearest point coincides on different segments, 
 * the minimum number of the segment is taken.
 * 
 * For each segment of the polyline, this function computes the point of closest approach 
 * to the given point and stores the result. The function returns a vector of pairs, 
 * where each pair contains the index of the segment and the closest point to given point
 * on that segment.
 *
 * @param poly The 3D polyline consisting of multiple segments.
 * @param point The point for which the nearest points on the polyline are being found.
 * @return A vector of pairs, where each pair contains:
 *         - The index of the polyline segment.
 *         - The 3D point on that segment that is closest to the given point.
 * @note The returned vector of pairs is sorted by segment index.
 */
std::vector<std::pair<size_t, Point3D>> FindNearestPointsToPolyline(const Polyline3D& poly, const Point3D& point);