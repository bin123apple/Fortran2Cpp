#include <iostream>
#include <vector>
#include <numeric>

class Arrays {
public:
    static int array_in(int n, const std::vector<int>& x) {
        return std::accumulate(x.begin(), x.end(), 0);
    }

    static void array_out(int nx, int ny, std::vector<int>& x, std::vector<int>& y) {
        x.assign(nx, 20);
        y.assign(ny, 30);
    }

    static int inner_prod(int n, const std::vector<int>& a, const std::vector<int>& b) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += a[i] * b[i];
        }
        return result;
    }

    static int inner_prod_2(int n, const std::vector<int>& a, const std::vector<int>& b) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += a[i] * b[i];
        }
        return result;
    }
};

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    int sum = Arrays::array_in(a.size(), a);
    std::cout << "Test array_in: Expected 15, Got " << sum << std::endl;

    std::vector<int> x, y;
    Arrays::array_out(3, 2, x, y);
    std::cout << "Test array_out: Expected all 20s for x and all 30s for y. "
                 "Got x: ";
    for (int i : x) std::cout << i << " ";
    std::cout << ". Got y: ";
    for (int i : y) std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> b = {5, 4, 3, 2, 1};
    int dotProd = Arrays::inner_prod(a.size(), a, b);
    std::cout << "Test inner_prod: Expected 35, Got " << dotProd << std::endl;

    int dotProd2 = Arrays::inner_prod_2(a.size(), a, b);
    std::cout << "Test inner_prod_2: Expected 35, Got " << dotProd2 << std::endl;

    return 0;
}