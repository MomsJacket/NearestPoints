#pragma once

#include <iostream>
#include <vector>

constexpr auto eps = 1e-9;

class Primitive3D{
protected:
    double x, y, z;
public:
    Primitive3D();
    Primitive3D(double _x, double _y, double _z);

    double GetX() const;
    double GetY() const;
    double GetZ() const;
    void SetX(double Xvalue);
    void SetY(double Yvalue);
    void SetZ(double Zvalue);
    bool operator<(const Primitive3D& other) const;
    bool operator==(const Primitive3D& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Primitive3D& primitive) noexcept;
};

class Point3D : public Primitive3D{
public:
    Point3D() : Primitive3D() {};
    Point3D(double _x, double _y, double _z) : Primitive3D(_x, _y, _z) {};
};

class Vector3D : public Primitive3D{
public: 
    Vector3D() : Primitive3D() {};;
    Vector3D(double _x, double _y, double _z) : Primitive3D(_x, _y, _z) {};
    Vector3D(const Point3D& pointA, const Point3D& pointB);
};

class Segment3D{
private:
    Point3D start;
    Point3D end;
public:
    Segment3D();
    Segment3D(const Point3D& point1, const Point3D& point2);
    Point3D GetStart() const;
    Point3D GetEnd() const;
    void SetStart(const Point3D& point);
    void SetEnd(const Point3D& point);
};

class Polyline3D{
private:
    std::vector<Point3D> nodes; 
public:
    Polyline3D();
    Polyline3D(const std::vector<Point3D>& points);
    Polyline3D(std::vector<Point3D>&& points) noexcept;

    size_t GetNodesCount() const {return nodes.size();}
    void SetNodes(const std::vector<Point3D>& points);
    std::vector<Point3D> GetNodes() const;
    void AddPoint(const Point3D& point);
};

