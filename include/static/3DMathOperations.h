#pragma once

#include "GeometryObjects.h"

/**
 * @brief Calculates the length (modulus) of a vector.
 * 
 * @param vec Vector for which the length is calculated.
 * @return Length of vector.
 */
double LengthOfVector(const Vector3D& vec);

/**
 * @brief Calculates the distance between two points in 3D space.
 * 
 * @param point1 First point.
 * @param point2 Second point.
 * @return Distance between two points.
 */
double DistanceBetweenPoints(const Point3D& point1, const Point3D& point2);

/**
 * @brief Calculates the scalar product of two vectors in 3D space.
 * 
 * @param vector1 First vector.
 * @param vector2 Second vector.
 * @return The scalar product of two vectors.
 */
double ScalarProduct(const Vector3D& vector1, const Vector3D& vector2);

/**
 * @brief Normalizes a vector (brings it to unit length).
 * 
 * @param vec A vector that needs to be normalized.
 * @return The normalized vector obtained from the incoming.
 * @note Does not change the incoming vector
 */
Vector3D NormalizedVector(const Vector3D& vec);

/**
 * @brief Multiplies a vector by a scalar.
 * 
 * @param vec Source vector.
 * @param a The scalar by which the vector is multiplied.
 * @return Vector obtained by multiplying the input by a scalar
 * @note Does not change the incoming vector
 */
Vector3D VectorMultipliedByScalar(const Vector3D& vec, double a);

/**
 * @brief Finds the projection of a point on a line through the segment.
 * 
 * @param point A point to be projected.
 * @param seg The segment through which the line passes.
 * @return The point of projection on a straight line.
 * @note The projection is on an infinite line through the segment. It may not be on the segment.
 */
Point3D PointProjectionOnLineThroughSegment(const Point3D& point, const Segment3D& seg);
