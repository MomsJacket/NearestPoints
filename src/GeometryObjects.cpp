#include "static/GeometryObjects.h"
#include "static/3DMathOperations.h"
#include <vector>
#include <tuple>
#include <cmath>

// Defining Primitive3D constructors
// The Point3D and Vector3D constructors will use these constructors
Primitive3D::Primitive3D() : x(0.0), y(0.0), z(0.0) {}
Primitive3D::Primitive3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

// Defining Primitive3D setters and getters
double Primitive3D::GetX() const {return x;}
double Primitive3D::GetY() const {return y;}
double Primitive3D::GetZ() const {return z;}

void Primitive3D::SetX(double Xvalue) {x = Xvalue;}
void Primitive3D::SetY(double Yvalue) {y = Yvalue;}
void Primitive3D::SetZ(double Zvalue) {z = Zvalue;}

bool Primitive3D::operator<(const Primitive3D& other) const{
    if (std::abs(x - other.x) > eps) {
        return x < other.x;
    }
    if (std::abs(y - other.y) > eps) {
        return y < other.y;
    }
    if (std::abs(z - other.z) > eps) {
        return z < other.z;
    }
    return false;
}

bool Primitive3D::operator==(const Primitive3D& other) const{
    return std::abs(x - other.GetX()) < eps && 
           std::abs(y - other.GetY()) < eps && 
           std::abs(z - other.GetZ()) < eps;
}

// Streaming output operator for Primitive3D overload
std::ostream& operator<<(std::ostream& os, const Primitive3D& primitive) noexcept{
    os << '(' << primitive.x << ", " << primitive.y << ", " << primitive.z << ')'; 
    return os;
}

// Constructor of Vector3D supporting vector assignment by two Point3D
Vector3D::Vector3D(const Point3D& pointA, const Point3D& pointB){
    x = pointB.GetX() - pointA.GetX();
    y = pointB.GetY() - pointA.GetY();
    z = pointB.GetZ() - pointA.GetZ();
}

// Defining Polygon3D constructors
Polyline3D::Polyline3D() = default;
Polyline3D::Polyline3D(const std::vector<Point3D>& points) : nodes(points) {}
Polyline3D::Polyline3D(std::vector<Point3D>&& points) noexcept : 
                                    nodes(std::move(points)) {}

// Defining setter and getter for Polygon3D class
void Polyline3D::SetNodes(const std::vector<Point3D>& points){
    nodes = points;
}

std::vector<Point3D> Polyline3D::GetNodes() const {return nodes;}

void Polyline3D::AddPoint(const Point3D& point){nodes.push_back(point);}

// Defining Segment3D constructors
Segment3D::Segment3D() : start(Point3D()), end(Point3D()) {}
Segment3D::Segment3D(const Point3D& point1, const Point3D& point2) : start(point1), end(point2) {}

Point3D Segment3D::GetStart() const{return start;}
Point3D Segment3D::GetEnd() const{return end;}
void Segment3D::SetStart(const Point3D& point){start = point;}
void Segment3D::SetEnd(const Point3D& point){end = point;}
