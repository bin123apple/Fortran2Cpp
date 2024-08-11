#include <iostream>
#include <cmath>
#include <limits>
#include <cassert>

class GeohashMod {
public:
    static int geohash(float lon, float lat) {
        const float scale = 120.0f;
        const float offset = 0.5f;
        const int rowlen = static_cast<int>(std::round(scale * 360.0f));
        int i = static_cast<int>(std::round(offset + scale * (lon + 180.0f)));
        int j = static_cast<int>(std::round(offset + scale * (lat + 90.0f)));
        return i + rowlen * (j - 1);
    }
};

void testGeohash() {
    std::cout << "Geohash(0, 0) = " << GeohashMod::geohash(0.0f, 0.0f) << std::endl;
    std::cout << "Geohash(180, 90) = " << GeohashMod::geohash(180.0f, 90.0f) << std::endl;
    std::cout << "Geohash(-180, -90) = " << GeohashMod::geohash(-180.0f, -90.0f) << std::endl;
    std::cout << "Geohash(45.0, 45.0) = " << GeohashMod::geohash(45.0f, 45.0f) << std::endl;
}

int main() {
    testGeohash();
    return 0;
}