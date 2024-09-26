#include "static/GeometryObjects.h"
#include "static/3DMathOperations.h"
#include <cmath>


double ScalarProduct(const Vector3D& vec1, const Vector3D& vec2){
    return vec1.GetX() * vec2.GetX() +
           vec1.GetY() * vec2.GetY() + 
           vec1.GetZ() * vec2.GetZ();
}

double LengthOfVector(const Vector3D& vec){
    return std::sqrt(vec.GetX() * vec.GetX() + 
                     vec.GetY() * vec.GetY() + 
                     vec.GetZ() * vec.GetZ());
}

double DistanceBetweenPoints(const Point3D& point1, const Point3D& point2){
    return std::sqrt((point2.GetX() - point1.GetX()) * (point2.GetX() - point1.GetX()) +
                     (point2.GetY() - point1.GetY()) * (point2.GetY() - point1.GetY()) +
                     (point2.GetZ() - point1.GetZ()) * (point2.GetZ() - point1.GetZ()));
}

Vector3D NormalizedVector(const Vector3D& vec){
    double length = LengthOfVector(vec);
    if (std::abs(length) < eps) return vec;
    return Vector3D{vec.GetX() / length,
                    vec.GetY() / length,
                    vec.GetZ() / length}; 
}

Vector3D VectorMultipliedByScalar(const Vector3D& vec, double a){
    return Vector3D{vec.GetX() * a,
                    vec.GetY() * a,
                    vec.GetZ() * a};
}


Point3D PointProjectionOnLineThroughSegment(const Point3D& point, const Segment3D& seg){
    Vector3D StartToP (seg.GetStart(), point);
    Vector3D StartToEndNorm = NormalizedVector(Vector3D {seg.GetStart(), seg.GetEnd()} );
    Vector3D StartToProj = VectorMultipliedByScalar(StartToEndNorm, 
                                                    ScalarProduct(StartToEndNorm, StartToP)) ;
    return Point3D {seg.GetStart().GetX() + StartToProj.GetX(),
                    seg.GetStart().GetY() + StartToProj.GetY(),
                    seg.GetStart().GetZ() + StartToProj.GetZ()};
}