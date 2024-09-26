#pragma once

#include "GeometryObjects.h"

// Calculating length of vector
double LengthOfVector(const Vector3D& vec);

double DistanceBetweenPoints(const Point3D& point1, const Point3D& point2);

double ScalarProduct(const Vector3D& vector1, const Vector3D& vector2);

Vector3D NormalizedVector(const Vector3D& vec);

Vector3D VectorMultipliedByScalar(const Vector3D& vec, double a);

Point3D PointProjectionOnLineThroughSegment(const Point3D& point, const Segment3D& seg);