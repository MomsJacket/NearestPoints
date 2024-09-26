#include <limits>
#include <algorithm>
#include <map>
#include "static/GeometryObjects.h"
#include "static/3DMathOperations.h"
#include <vector>

bool IsProjectionInSegment(const Point3D& point, const Segment3D& seg){
    return std::min(seg.GetStart().GetX(), seg.GetEnd().GetX()) <= point.GetX() &&
           std::max(seg.GetStart().GetX(), seg.GetEnd().GetX()) >= point.GetX() &&
           std::min(seg.GetStart().GetY(), seg.GetEnd().GetY()) <= point.GetY() &&
           std::max(seg.GetStart().GetY(), seg.GetEnd().GetY()) >= point.GetY() &&
           std::min(seg.GetStart().GetZ(), seg.GetEnd().GetZ()) <= point.GetZ() &&
           std::max(seg.GetStart().GetZ(), seg.GetEnd().GetZ()) >= point.GetZ();
}

std::vector<std::pair<size_t, Point3D>> FindNearestPointsToPolyline(const Polyline3D& poly, const Point3D& point){
    auto n = poly.GetNodesCount();
    const auto nodes = poly.GetNodes();

    std::map<Point3D, std::pair<size_t, double>> distances;
    double min_distance = std::numeric_limits<double>::max();
    std::vector<std::pair<size_t, Point3D>> answer;

    if (n < 2)
        return answer;

    for (size_t i = 0; i < n - 1; ++i){
        if (nodes[i] == nodes[i + 1]) 
            continue;

        Segment3D SegI (nodes[i], nodes[i + 1]);
        auto proj = PointProjectionOnLineThroughSegment(point, SegI);

        if (IsProjectionInSegment(proj, SegI)){
            auto dist = DistanceBetweenPoints(proj, point);
            distances.insert({proj, std::pair{i, dist}});
            if (dist < min_distance) min_distance = dist;
        }
        else
        {
            auto dist1 = DistanceBetweenPoints(nodes[i], point);
            auto dist2 = DistanceBetweenPoints(nodes[i + 1], point);
            if (dist1 < dist2) {
                distances.insert({nodes[i], std::pair{i, dist1}});
                if (dist1 < min_distance) min_distance = dist1;
            }
            else
            {
                distances.insert({nodes[i + 1], std::pair{i, dist2}});
                if (dist2 < min_distance) min_distance = dist2;
            }
        }
    }
    for (const auto& pair : distances)
    {
        if (std::abs(pair.second.second - min_distance) < eps)
        {
            answer.push_back(std::pair{pair.second.first, pair.first});
        }
    }

    std::sort(answer.begin(), answer.end(),
     [](const auto& elem1, const auto& elem2){ 
        return elem1.first < elem2.first;
    });

    return answer;
}