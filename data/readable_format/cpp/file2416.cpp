#include <iostream>
#include <vector>
#include <iomanip>

struct Point {
    double x, y;
};

void grid1(int n, std::vector<Point>& List_points) {
    const double a = 2.0, b = 2.0, c = 1.0;
    double hx, hy;
    
    hx = a / static_cast<double>(n - 1);

    List_points.resize(n * n);

    for (int i = 0; i < n; ++i) {
        hy = (b - c * i * hx / a) / static_cast<double>(n - 1);
        for (int j = 0; j < n; ++j) {
            List_points[i * n + j].x = i * hx;
            List_points[i * n + j].y = j * hy + c * i * hx / a;
        }
    }
}

int main() {
    int n = 10; // Example value for n
    std::vector<Point> List_points;
    grid1(n, List_points);

    // Print the results
    for (const auto& point : List_points) {
        std::cout << std::fixed << std::setprecision(6) 
                  << "Point(" << point.x << ", " << point.y << ")";
        std::cout << std::endl;
    }

    return 0;
}