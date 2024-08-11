#include <algorithm> // For std::max

void stlest(int nleft, int nright, double& h) {
    h = std::max(static_cast<double>(nleft), static_cast<double>(nright));
}