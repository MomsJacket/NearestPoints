#pragma once

#include "GeometryObjects.h"
#include "3DMathOperations.h"
#include <vector>


bool IsProjectionInSegment(const Point3D& point, const Segment3D& seg);

std::vector<std::pair<size_t, Point3D>> FindNearestPointsToPolyline(const Polyline3D& poly, const Point3D& point);