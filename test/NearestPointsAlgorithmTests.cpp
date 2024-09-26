#include "gtest/gtest.h"
#include "static/NearestPointsAlgorithm.h"
#include "static/GeometryObjects.h"


TEST(NearestPointsAlgorithmTests, Example1) {
    std::vector<Point3D> points;
    points.push_back(Point3D {0.0, 0.0, 0.0});
    points.push_back(Point3D {1.0, 0.0, 0.0});
    points.push_back(Point3D {2.0, 1.0, 0.0});
    points.push_back(Point3D {3.0, 1.0, 1.0});

    Point3D given_point(2.0, 0.5, 0.5);

    Polyline3D poly(points);

    std::vector<std::pair<size_t, Point3D>> ans = FindNearestPointsToPolyline(poly, given_point);

    EXPECT_EQ(ans.size(), 2);
    EXPECT_EQ(ans[0].first, 1);
    EXPECT_NEAR(ans[0].second.GetX(), 1.75, eps);
    EXPECT_NEAR(ans[0].second.GetY(), 0.75, eps);
    EXPECT_NEAR(ans[0].second.GetZ(), 0.0, eps);

    EXPECT_EQ(ans[1].first, 2);
    EXPECT_NEAR(ans[1].second.GetX(), 2.25, eps);
    EXPECT_NEAR(ans[1].second.GetY(), 1.0, eps);
    EXPECT_NEAR(ans[1].second.GetZ(), 0.25, eps);
}

TEST(NearestPointsAlgorithmTests, Example2) {
    std::vector<Point3D> points;
    points.push_back(Point3D {0.0, 0.0, 0.0});
    points.push_back(Point3D {2.0, 0.0, 0.0});
    points.push_back(Point3D {2.0, 2.0, 0.0});
    points.push_back(Point3D {0.0, 2.0, 0.0});
    points.push_back(Point3D {0.0, 0.0, 0.0});

    Point3D given_point(1.0, 1.0, 1.0);

    Polyline3D poly(points);

    std::vector<std::pair<size_t, Point3D>> ans = FindNearestPointsToPolyline(poly, given_point);

    EXPECT_EQ(ans.size(), 4);
    EXPECT_EQ(ans[0].first, 0);
    EXPECT_NEAR(ans[0].second.GetX(), 1.0, eps);
    EXPECT_NEAR(ans[0].second.GetY(), 0.0, eps);
    EXPECT_NEAR(ans[0].second.GetZ(), 0.0, eps);

    EXPECT_EQ(ans[1].first, 1);
    EXPECT_NEAR(ans[1].second.GetX(), 2.0, eps);
    EXPECT_NEAR(ans[1].second.GetY(), 1.0, eps);
    EXPECT_NEAR(ans[1].second.GetZ(), 0.0, eps);

    EXPECT_EQ(ans[2].first, 2);
    EXPECT_NEAR(ans[2].second.GetX(), 1.0, eps);
    EXPECT_NEAR(ans[2].second.GetY(), 2.0, eps);
    EXPECT_NEAR(ans[2].second.GetZ(), 0.0, eps);

    EXPECT_EQ(ans[3].first, 3);
    EXPECT_NEAR(ans[3].second.GetX(), 0.0, eps);
    EXPECT_NEAR(ans[3].second.GetY(), 1.0, eps);
    EXPECT_NEAR(ans[3].second.GetZ(), 0.0, eps);
}

TEST(NearestPointsAlgorithmTests, Example3) {
    std::vector<Point3D> points;
    points.push_back(Point3D {0.0, 0.0, 0.0});
    points.push_back(Point3D {2.0, 0.0, 0.0});
    points.push_back(Point3D {2.0, 2.0, 0.0});
    points.push_back(Point3D {0.0, 2.0, 0.0});
    points.push_back(Point3D {0.0, 0.0, 0.0});

    Point3D given_point(3.0, 3.0, 3.0);

    Polyline3D poly(points);

    std::vector<std::pair<size_t, Point3D>> ans = FindNearestPointsToPolyline(poly, given_point);

    EXPECT_EQ(ans.size(), 1);
    EXPECT_TRUE(ans[0].first == 1 || ans[0].first == 2);
    EXPECT_NEAR(ans[0].second.GetX(), 2.0, eps);
    EXPECT_NEAR(ans[0].second.GetY(), 2.0, eps);
    EXPECT_NEAR(ans[0].second.GetZ(), 0.0, eps);
}

TEST(NearestPointsAlgorithmTests, Example4) {
    std::vector<Point3D> points;
    points.push_back(Point3D {2.0, -2.0, 0.0});
    points.push_back(Point3D {0.0, -1.0, 0.0});
    points.push_back(Point3D {0.0, 1.0, 0.0});
    points.push_back(Point3D {2.0, 2.0, 0.0});

    Point3D given_point(4.0, 0.0, 0.0);

    Polyline3D poly(points);

    std::vector<std::pair<size_t, Point3D>> ans = FindNearestPointsToPolyline(poly, given_point);

    EXPECT_EQ(ans.size(), 2);
    EXPECT_TRUE(ans[0].first == 0);
    EXPECT_NEAR(ans[0].second.GetX(), 2.0, eps);
    EXPECT_NEAR(ans[0].second.GetY(), -2.0, eps);
    EXPECT_NEAR(ans[0].second.GetZ(), 0.0, eps);

    EXPECT_TRUE(ans[1].first == 2);
    EXPECT_NEAR(ans[1].second.GetX(), 2.0, eps);
    EXPECT_NEAR(ans[1].second.GetY(), 2.0, eps);
    EXPECT_NEAR(ans[1].second.GetZ(), 0.0, eps);
}

TEST(NearestPointsAlgorithmTests, Example5) {
    std::vector<Point3D> points;
    points.push_back(Point3D {2.0, -2.0, 0.0});
    points.push_back(Point3D {2.0, -2.0, 0.0});
    points.push_back(Point3D {0.0, -1.0, 0.0});
    points.push_back(Point3D {0.0, 1.0, 0.0});
    points.push_back(Point3D {0.0, 1.0, 0.0});
    points.push_back(Point3D {0.0, 1.0, 0.0});
    points.push_back(Point3D {2.0, 2.0, 0.0});

    Point3D given_point(2.0, 2.0, 1.0);

    Polyline3D poly(points);

    std::vector<std::pair<size_t, Point3D>> ans = FindNearestPointsToPolyline(poly, given_point);

    EXPECT_EQ(ans.size(), 1);
    EXPECT_TRUE(ans[0].first == 5);
    EXPECT_NEAR(ans[0].second.GetX(), 2.0, eps);
    EXPECT_NEAR(ans[0].second.GetY(), 2.0, eps);
    EXPECT_NEAR(ans[0].second.GetZ(), 0.0, eps);
}