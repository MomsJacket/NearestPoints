#include <fstream>
#include <filesystem>
#include "static/GeometryObjects.h"
#include "static/3DMathOperations.h"
#include "static/NearestPointsAlgorithm.h"
#include <iostream>

int main(int argc, char* argv[])
{
    /// Check if the correct number of arguments is provided
    if (argc != 5){
        std::cerr << "Usage: " << argv[0] << "<filename> <x_coord> <y_coord> <z_coord>";
        return 1;
    }

    /// Get filename from command line
    std::filesystem::path dataDir = std::filesystem::path(argv[1]); 
    std::string filename = dataDir.string();

    try{
        /// Get coordinates of point from command line and convert to double
        auto point_x = std::stod(argv[2]);
        auto point_y = std::stod(argv[3]);
        auto point_z = std::stod(argv[4]);

        Point3D point(point_x, point_y, point_z);

        /// Read coordinates of Polyline from file
        std::ifstream file(filename);
        if (!file.is_open()){
            std::cerr << "Error opening file: " << filename;
            return 2;
        }
        Polyline3D poly;
        auto x = 0.0;
        auto y = 0.0;
        auto z = 0.0;
        while (file >> x >> y >> z){
            poly.AddPoint({x, y, z});
        }
        file.close();

        /// Find and display nearest points
        auto ans = FindNearestPointsToPolyline(poly, point);
        std::cout << "Found solutions: " << ans.size() << "\n";
        for (const auto& pair : ans){
            std::cout << "Segment " << pair.first + 1 << " : " << pair.second << "\n";
        }

    } catch (const std::invalid_argument& e){
        std::cerr << "Invalid argument for coordinates. Please enter valid numbers.\n";
        return 3;

    } catch (const std::out_of_range& e) {
        std::cerr << "One or more coordinates are out of range.\n";
        return 4;
    }

    return 0;
}
