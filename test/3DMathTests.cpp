#include "gtest/gtest.h"
#include "static/3DMathOperations.h"
#include "static/GeometryObjects.h"
#include <cmath>


TEST(LengthOfVectorTests, ZeroVector) {
    Vector3D vec(0.0, 0.0, 0.0);
    EXPECT_NEAR(LengthOfVector(vec), 0.0, eps);
}

TEST(LengthOfVectorTests, UnitVector) {
    Vector3D vec(1.0, 0.0, 0.0);
    EXPECT_NEAR(LengthOfVector(vec), 1.0, eps);
}

TEST(LengthOfVectorTests, NonUnitVector) {
    Vector3D vec(3.0, 4.0, 0.0);
    EXPECT_NEAR(LengthOfVector(vec), 5.0, eps);
}



TEST(DistanceBetweenPointsTests, SamePoint) {
    Point3D point1(1.0, 2.0, 3.0);
    Point3D point2(1.0, 2.0, 3.0);
    EXPECT_NEAR(DistanceBetweenPoints(point1, point2), 0.0, eps);
}

TEST(DistanceBetweenPointsTests, DifferentPoints) {
    Point3D point1(1.0, 2.0, 3.0);
    Point3D point2(4.0, 6.0, 8.0);
    EXPECT_NEAR(DistanceBetweenPoints(point1, point2), std::sqrt(50.0), eps); 
}

TEST(DistanceBetweenPointsTests, NegativeCoordinates) {
    Point3D point1(-1.0, -2.0, -3.0);
    Point3D point2(1.0, 2.0, 3.0);
    EXPECT_NEAR(DistanceBetweenPoints(point1, point2), std::sqrt(56.0), eps);
}


TEST(ScalarProductTests, SameVector){
    Vector3D vec1(1.0, 2.0, 3.0);
    Vector3D vec2(1.0, 2.0, 3.0);
    EXPECT_NEAR(ScalarProduct(vec1, vec2), 14.0, eps);
}

TEST(ScalarProductTests, ZeroVector) {
    Vector3D vec1(0.0, 0.0, 0.0);
    Vector3D vec2(1.0, 2.0, 3.0);
    EXPECT_NEAR(ScalarProduct(vec1, vec2), 0.0, eps);
}

TEST(ScalarProductTests, OrthogonalVectors) {
    Vector3D vec1(1.0, 1.0, 1.0);
    Vector3D vec2(1.0, -1.0, 0.0);
    EXPECT_NEAR(ScalarProduct(vec1, vec2), 0.0, eps);
}

TEST(ScalarProductTests, NonOrthogonalVectors) {
    Vector3D vec1(1.0, 2.0, 3.0);
    Vector3D vec2(4.0, 5.0, 6.0);
    EXPECT_NEAR(ScalarProduct(vec1, vec2), 32.0, eps); 
}


TEST(NormalizedVectorTests, NormalizeNonZeroVector) {
    Vector3D vec(3.0, 4.0, 0.0);
    Vector3D normalized = NormalizedVector(vec);

    double length = LengthOfVector(normalized);
    EXPECT_NEAR(length, 1.0, eps);

    EXPECT_NEAR(normalized.GetX(), 3.0 / 5.0, eps);
    EXPECT_NEAR(normalized.GetY(), 4.0 / 5.0, eps);
    EXPECT_NEAR(normalized.GetZ(), 0.0, eps);
}

TEST(NormalizedVectorTests, NormalizeZeroVector) {
    Vector3D vec(0.0, 0.0, 0.0);
    Vector3D normalized = NormalizedVector(vec);

    EXPECT_NEAR(normalized.GetX(), 0.0, eps);
    EXPECT_NEAR(normalized.GetY(), 0.0, eps);
    EXPECT_NEAR(normalized.GetZ(), 0.0, eps);
}

TEST(NormalizedVectorTests, NormalizeNegativeVector) {
    Vector3D vec(-3.0, -4.0, 0.0);
    Vector3D normalized = NormalizedVector(vec);

    double length = LengthOfVector(normalized);
    EXPECT_NEAR(length, 1.0, eps);

    EXPECT_NEAR(normalized.GetX(), -0.6, eps);
    EXPECT_NEAR(normalized.GetY(), -0.8, eps); 
    EXPECT_NEAR(normalized.GetZ(), 0.0, eps);          
}

TEST(NormalizedVectorTests, NormalizeUnitVector) {
    Vector3D vec(1.0, 0.0, 0.0);
    Vector3D normalized = NormalizedVector(vec);

    double length = LengthOfVector(normalized);
    EXPECT_NEAR(length, 1.0, eps);

    EXPECT_NEAR(normalized.GetX(), 1.0, eps);
    EXPECT_NEAR(normalized.GetY(), 0.0, eps);
    EXPECT_NEAR(normalized.GetZ(), 0.0, eps);
}


TEST(VectorMultipliedByScalarTests, MultiplyByPositiveScalar) {
    Vector3D vec(2.0, 3.0, 4.0);
    double scalar = 2.0;
    Vector3D result = VectorMultipliedByScalar(vec, scalar);

    EXPECT_NEAR(result.GetX(), 4.0, eps);
    EXPECT_NEAR(result.GetY(), 6.0, eps);
    EXPECT_NEAR(result.GetZ(), 8.0, eps);
}

TEST(VectorMultipliedByScalarTests, MultiplyByZeroScalar) {
    Vector3D vec(5.0, -3.0, 2.0);
    double scalar = 0.0;
    Vector3D result = VectorMultipliedByScalar(vec, scalar);

    EXPECT_NEAR(result.GetX(), 0.0, eps);
    EXPECT_NEAR(result.GetY(), 0.0, eps);
    EXPECT_NEAR(result.GetZ(), 0.0, eps);
}

TEST(VectorMultipliedByScalarTests, MultiplyByNegativeScalar) {
    Vector3D vec(1.0, -1.0, 3.0);
    double scalar = -2.0;
    Vector3D result = VectorMultipliedByScalar(vec, scalar);

    EXPECT_NEAR(result.GetX(), -2.0, eps);
    EXPECT_NEAR(result.GetY(), 2.0, eps);
    EXPECT_NEAR(result.GetZ(), -6.0, eps);
}

TEST(VectorMultipliedByScalarTests, MultiplyByOneScalar) {
    Vector3D vec(3.0, 4.0, 5.0);
    double scalar = 1.0;
    Vector3D result = VectorMultipliedByScalar(vec, scalar);

    EXPECT_NEAR(result.GetX(), 3.0, eps);
    EXPECT_NEAR(result.GetY(), 4.0, eps);
    EXPECT_NEAR(result.GetZ(), 5.0, eps);
}


TEST(PointProjectionOnLineThroughSegmentTests, ProjectionOnLine) {
    Segment3D seg(Point3D(0.0, 0.0, 0.0), Point3D(1.0, 1.0, 1.0));
    Point3D point(1.0, 0.0, 0.0);
    Point3D projected = PointProjectionOnLineThroughSegment(point, seg);
    EXPECT_NEAR(projected.GetX(), 1.0 / 3.0, eps);
    EXPECT_NEAR(projected.GetY(), 1.0 / 3.0, eps);
    EXPECT_NEAR(projected.GetZ(), 1.0 / 3.0, eps);
}

TEST(PointProjectionOnLineThroughSegmentTests, ProjectionOnSegmentEnd) {
    Segment3D seg(Point3D(0.0, 0.0, 0.0), Point3D(2.0, 2.0, 2.0));
    Point3D point(3.0, 3.0, 3.0);
    Point3D projected = PointProjectionOnLineThroughSegment(point, seg);
    EXPECT_NEAR(projected.GetX(), 3.0, eps);
    EXPECT_NEAR(projected.GetY(), 3.0, eps);
    EXPECT_NEAR(projected.GetZ(), 3.0, eps);
}

TEST(PointProjectionOnLineThroughSegmentTests, ProjectionOnSegmentStart) {
    Segment3D seg(Point3D(1.0, 1.0, 1.0), Point3D(3.0, 3.0, 3.0));
    Point3D point(0.0, 0.0, 0.0);
    Point3D projected = PointProjectionOnLineThroughSegment(point, seg);
    EXPECT_NEAR(projected.GetX(), 0.0, eps); 
    EXPECT_NEAR(projected.GetY(), 0.0, eps);
    EXPECT_NEAR(projected.GetZ(), 0.0, eps);
}