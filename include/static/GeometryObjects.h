#pragma once

#include <iostream>
#include <vector>

/// Small tolerance value to account for floating point errors.
constexpr auto eps = 1e-9;

/**
 * @class Primitive3D
 * @brief Represents a primitive point in 3D space.
 */
class Primitive3D{
protected:
    double x; ///< X coordinate
    double y; ///< Y coordinate
    double z; ///< Z coordinate
public:
    /// Default constructor. Initializes point to (0, 0, 0).
    Primitive3D();

    /**
     * @brief Constructs a 3D point with given coordinates.
     * @param _x X coordinate.
     * @param _y Y coordinate.
     * @param _z Z coordinate.
     */
    Primitive3D(double _x, double _y, double _z);

    /**
     * @brief Get the X coordinate of the point.
     * @return X coordinate.
     */
    double GetX() const;

    /**
     * @brief Get the Y coordinate of the point.
     * @return Y coordinate.
     */
    double GetY() const;

    /**
     * @brief Get the Z coordinate of the point.
     * @return Z coordinate.
     */
    double GetZ() const;

    /**
     * @brief Set the X coordinate of the point.
     * @param Xvalue New X coordinate.
     */
    void SetX(double Xvalue);

    /**
     * @brief Set the Y coordinate of the point.
     * @param Yvalue New Y coordinate.
     */
    void SetY(double Yvalue);

    /**
     * @brief Set the Z coordinate of the point.
     * @param Zvalue New Z coordinate.
     */
    void SetZ(double Zvalue);

    /**
     * @brief Less-than operator for comparing two points with a small tolerance.
     * @param other Another Primitive3D object to compare.
     * @return True if this point is less than the other.
     * @note The comparison is first on the X coordinate, then on the Y coordinate, then on the Z coordinate.
     */
    bool operator<(const Primitive3D& other) const;

    /**
     * @brief Equality operator for comparing two points with a small tolerance.
     * @param other Another Primitive3D object to compare.
     * @return True if the points are approximately equal.
     */
    bool operator==(const Primitive3D& other) const;

    /**
     * @brief Output stream operator for printing a Primitive3D object.
     * @param os Output stream.
     * @param primitive Primitive3D object to print.
     * @return The modified output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Primitive3D& primitive) noexcept;
};

/**
 * @class Point3D
 * @brief Represents a point in 3D space, inherits from Primitive3D.
 */
class Point3D : public Primitive3D{
public:
    /// Default constructor. Initializes point to (0, 0, 0).
    Point3D() : Primitive3D() {};

    /**
     * @brief Constructs a 3D point with given coordinates.
     * @param _x X coordinate.
     * @param _y Y coordinate.
     * @param _z Z coordinate.
     */
    Point3D(double _x, double _y, double _z) : Primitive3D(_x, _y, _z) {};
};

/**
 * @class Vector3D
 * @brief Represents a vector in 3D space, inherits from Primitive3D.
 */
class Vector3D : public Primitive3D{
public: 
    /// Default constructor. Initializes vector to (0, 0, 0).
    Vector3D() : Primitive3D() {};;

    /**
     * @brief Constructs a 3D vector with given components.
     * @param _x X component.
     * @param _y Y component.
     * @param _z Z component.
     */
    Vector3D(double _x, double _y, double _z) : Primitive3D(_x, _y, _z) {};

    /**
     * @brief Constructs a vector from two points.
     * @param pointA Starting point of the vector.
     * @param pointB Ending point of the vector.
     */
    Vector3D(const Point3D& pointA, const Point3D& pointB);
};

/**
 * @class Segment3D
 * @brief Represents a line segment in 3D space, defined by two points.
 */
class Segment3D{
private:
    Point3D start; ///< Start point of the segment.
    Point3D end; ///< End point of the segment.
public:
    /// Default constructor. Initializes segment with start and end at (0, 0, 0).
    Segment3D();

    /**
     * @brief Constructs a 3D line segment with given start and end points.
     * @param point1 Start point.
     * @param point2 End point.
     */
    Segment3D(const Point3D& point1, const Point3D& point2);

    /**
     * @brief Get the start point of the segment.
     * @return Start point.
     */
    Point3D GetStart() const;

    /**
     * @brief Get the end point of the segment.
     * @return End point.
     */
    Point3D GetEnd() const;

    /**
     * @brief Set the start point of the segment.
     * @param point New start point.
     */
    void SetStart(const Point3D& point);

    /**
     * @brief Set the end point of the segment.
     * @param point New end point.
     */
    void SetEnd(const Point3D& point);
};

/**
 * @class Polyline3D
 * @brief Represents a polyline in 3D space, consisting of a sequence of points.
 */
class Polyline3D{
private:
    std::vector<Point3D> nodes; ///< Nodes of the polyline.
public:
    /// Default constructor. Initializes an empty polyline.
    Polyline3D();

    /**
     * @brief Constructs a polyline with a given set of points.
     * @param points Vector of points defining the polyline.
     */
    Polyline3D(const std::vector<Point3D>& points);

    /**
     * @brief Constructs a polyline by moving a set of points.
     * @param points Rvalue reference to a vector of points.
     */
    Polyline3D(std::vector<Point3D>&& points) noexcept;

    /**
     * @brief Get the number of nodes in the polyline.
     * @return Number of nodes.
     */
    size_t GetNodesCount() const {return nodes.size();}

    /**
     * @brief Set the nodes of the polyline.
     * @param points New set of points.
     */
    void SetNodes(const std::vector<Point3D>& points);

    /**
     * @brief Get the nodes of the polyline.
     * @return Vector of points representing the nodes.
     */
    std::vector<Point3D> GetNodes() const;

    /**
     * @brief Add a point to the polyline.
     * @param point Point to add.
     */
    void AddPoint(const Point3D& point);
};

