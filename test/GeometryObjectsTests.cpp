#include "gtest/gtest.h"
#include "static/GeometryObjects.h"


// Primitive3D Tests

TEST(Primitive3DTest, DefaultConstructor) {
    Primitive3D p;
    EXPECT_NEAR(p.GetX(), 0.0, eps);
    EXPECT_NEAR(p.GetY(), 0.0, eps);
    EXPECT_NEAR(p.GetZ(), 0.0, eps);
}

TEST(Primitive3DTest, ParameterizedConstructor) {
    Primitive3D p(1.0, 2.0, 3.0);
    EXPECT_NEAR(p.GetX(), 1.0, eps);
    EXPECT_NEAR(p.GetY(), 2.0, eps);
    EXPECT_NEAR(p.GetZ(), 3.0, eps);
}

TEST(Primitive3DTest, Setters) {
    Primitive3D p;
    p.SetX(4.0);
    p.SetY(5.0);
    p.SetZ(6.0);

    EXPECT_NEAR(p.GetX(), 4.0, eps);
    EXPECT_NEAR(p.GetY(), 5.0, eps);
    EXPECT_NEAR(p.GetZ(), 6.0, eps);
}

TEST(Primitive3DTest, EqualityOperator) {
    Primitive3D p1(1.0, 2.0, 3.0);
    Primitive3D p2(1.0, 2.0, 3.0);
    Primitive3D p3(3.0, 2.0, 1.0);

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3); 
}

TEST(Primitive3DTest, LessThanOperator) {
    Primitive3D p1(1.0, 2.0, 3.0);
    Primitive3D p2(2.0, 2.0, 3.0);
    Primitive3D p3(1.0, 2.0, 4.0);

    EXPECT_TRUE(p1 < p2); 
    EXPECT_FALSE(p2 < p1); 
    EXPECT_TRUE(p1 < p3);   
    EXPECT_FALSE(p3 < p1);  
}

TEST(Primitive3DTest, OutputOperator) {
    Primitive3D p(1.0, 2.0, 3.0);
    std::stringstream ss;
    ss << p;

    EXPECT_EQ(ss.str(), "(1, 2, 3)");
}

//Point3D Tests

TEST(Point3DTests, DefaultConstructor) {
    Point3D point;
    EXPECT_NEAR(point.GetX(), 0.0, eps);
    EXPECT_NEAR(point.GetY(), 0.0, eps);
    EXPECT_NEAR(point.GetZ(), 0.0, eps);
}

TEST(Point3DTests, ParameterizedConstructor) {
    Point3D point(1.0, 2.0, 3.0);
    EXPECT_NEAR(point.GetX(), 1.0, eps);
    EXPECT_NEAR(point.GetY(), 2.0, eps);
    EXPECT_NEAR(point.GetZ(), 3.0, eps);
}

// Vector3D Tests

TEST(Vector3DTests, DefaultConstructor) {
    Vector3D vector;
    EXPECT_NEAR(vector.GetX(), 0.0, eps);
    EXPECT_NEAR(vector.GetY(), 0.0, eps);
    EXPECT_NEAR(vector.GetZ(), 0.0, eps);
}

TEST(Vector3DTests, ParameterizedConstructor) {
    Vector3D vector(1.0, 2.0, 3.0);
    EXPECT_NEAR(vector.GetX(), 1.0, eps);
    EXPECT_NEAR(vector.GetY(), 2.0, eps);
    EXPECT_NEAR(vector.GetZ(), 3.0, eps);
}

TEST(Vector3DTests, ConstructorFromPoints) {
    Point3D pointA(1.0, 2.0, 3.0);
    Point3D pointB(4.0, 5.0, 6.0);
    Vector3D vector(pointA, pointB);
    
    EXPECT_NEAR(vector.GetX(), 3.0, eps); 
    EXPECT_NEAR(vector.GetY(), 3.0, eps); 
    EXPECT_NEAR(vector.GetZ(), 3.0, eps);
}

//Segment3D Tests

TEST(Segment3DTests, DefaultConstructor) {
    Segment3D segment;
    EXPECT_NEAR(segment.GetStart().GetX(), 0.0, eps);
    EXPECT_NEAR(segment.GetStart().GetY(), 0.0, eps);
    EXPECT_NEAR(segment.GetStart().GetZ(), 0.0, eps);
    EXPECT_NEAR(segment.GetEnd().GetX(), 0.0, eps);
    EXPECT_NEAR(segment.GetEnd().GetY(), 0.0, eps);
    EXPECT_NEAR(segment.GetEnd().GetZ(), 0.0, eps);
}

TEST(Segment3DTests, ParameterizedConstructor) {
    Point3D point1(1.0, 2.0, 3.0);
    Point3D point2(4.0, 5.0, 6.0);
    Segment3D segment(point1, point2);
    EXPECT_NEAR(segment.GetStart().GetX(), 1.0, eps);
    EXPECT_NEAR(segment.GetStart().GetY(), 2.0, eps);
    EXPECT_NEAR(segment.GetStart().GetZ(), 3.0, eps);
    EXPECT_NEAR(segment.GetEnd().GetX(), 4.0, eps);
    EXPECT_NEAR(segment.GetEnd().GetY(), 5.0, eps);
    EXPECT_NEAR(segment.GetEnd().GetZ(), 6.0, eps);
}

TEST(Segment3DTests, SetStartAndEnd) {
    Point3D point1(1.0, 2.0, 3.0);
    Point3D point2(4.0, 5.0, 6.0);
    Segment3D segment;
    segment.SetStart(point1);
    segment.SetEnd(point2);
    EXPECT_NEAR(segment.GetStart().GetX(), 1.0, eps);
    EXPECT_NEAR(segment.GetStart().GetY(), 2.0, eps);
    EXPECT_NEAR(segment.GetStart().GetZ(), 3.0, eps);
    EXPECT_NEAR(segment.GetEnd().GetX(), 4.0, eps);
    EXPECT_NEAR(segment.GetEnd().GetY(), 5.0, eps);
    EXPECT_NEAR(segment.GetEnd().GetZ(), 6.0, eps);
}

// Polyline3D Tests

TEST(Polyline3DTests, DefaultConstructor) {
    Polyline3D polyline;
    EXPECT_EQ(polyline.GetNodesCount(), 0);
}

TEST(Polyline3DTests, ParameterizedConstructor) {
    std::vector<Point3D> points = { Point3D(1.0, 2.0, 3.0), Point3D(4.0, 5.0, 6.0) };
    Polyline3D polyline(points);
    EXPECT_EQ(polyline.GetNodesCount(), 2);
}

TEST(Polyline3DTests, MoveConstructor) {
    std::vector<Point3D> points = { Point3D(1.0, 2.0, 3.0), Point3D(4.0, 5.0, 6.0) };
    Polyline3D polyline(std::move(points));
    EXPECT_EQ(polyline.GetNodesCount(), 2);
}

TEST(Polyline3DTests, AddPoint) {
    Polyline3D polyline;
    Point3D point(1.0, 2.0, 3.0);
    polyline.AddPoint(point);
    EXPECT_EQ(polyline.GetNodesCount(), 1);
    EXPECT_NEAR(polyline.GetNodes()[0].GetX(), 1.0, eps);
    EXPECT_NEAR(polyline.GetNodes()[0].GetY(), 2.0, eps);
    EXPECT_NEAR(polyline.GetNodes()[0].GetZ(), 3.0, eps);
}

