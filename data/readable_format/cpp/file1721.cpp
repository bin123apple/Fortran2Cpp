#include <iostream>
#include <array>
#include <cmath>

void distance_point_line_2D(const std::array<double, 2>& P0, 
                            const std::array<double, 2>& P1_line, 
                            const std::array<double, 2>& P2_line, 
                            double& dis, 
                            std::array<double, 2>& normal) {
    double a, b, c;
    a = P2_line[1] - P1_line[1];
    b = -(P2_line[0] - P1_line[0]);
    c = -(a * P1_line[0] + b * P1_line[1]);
    normal[0] = a / sqrt(pow(a, 2) + pow(b, 2));
    normal[1] = b / sqrt(pow(a, 2) + pow(b, 2));
    dis = (a * P0[0] + b * P0[1] + c) / sqrt(pow(a, 2) + pow(b, 2));
}

int main() {
    std::array<double, 2> P0, P1_line, P2_line, normal;
    double dis;

    // Test Case 1: Point on the line
    P0 = {2.0, 2.0};
    P1_line = {1.0, 1.0};
    P2_line = {3.0, 3.0};
    distance_point_line_2D(P0, P1_line, P2_line, dis, normal);
    std::cout << "Test 1 - Distance: " << dis << " Normal: [" << normal[0] << ", " << normal[1] << "]" << std::endl;

    // Test Case 2: Point to the left of the line
    P0 = {1.0, 2.0};
    distance_point_line_2D(P0, P1_line, P2_line, dis, normal);
    std::cout << "Test 2 - Distance: " << dis << " Normal: [" << normal[0] << ", " << normal[1] << "]" << std::endl;

    // Test Case 3: Point to the right of the line
    P0 = {3.0, 4.0};
    distance_point_line_2D(P0, P1_line, P2_line, dis, normal);
    std::cout << "Test 3 - Distance: " << dis << " Normal: [" << normal[0] << ", " << normal[1] << "]" << std::endl;

    return 0;
}