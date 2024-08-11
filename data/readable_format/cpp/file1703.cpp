#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::swap

void sro(
    int n, 
    std::vector<int>& ip, 
    std::vector<int>& ia, 
    std::vector<int>& ja, 
    std::vector<double>& a, 
    std::vector<int>& q, 
    std::vector<int>& r, 
    bool dflag
) {
    for (int i = 0; i < n; ++i) {
        q[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        int jmin = ia[i] - 1;
        int jmax = ia[i + 1] - 2;
        if (jmin > jmax) continue;

        for (int j = jmin; j <= jmax; ++j) {
            int k = ja[j] - 1;
            if (ip[k] < ip[i]) ja[j] = i + 1;
            if (ip[k] >= ip[i]) k = i;
            r[j] = k + 1;
            q[k]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        ia[i + 1] = ia[i] + q[i];
        q[i] = ia[i + 1];
    }

    int ilast = -1;
    int jmin = ia[0] - 1;
    int jmax = ia[n] - 2;
    int j = jmax;
    while (j >= jmin) {
        int i = r[j] - 1;
        if (!(dflag && ja[j] == (i + 1) && i != ilast)) {
            q[i]--;
            r[j] = q[i];
        } else {
            r[j] = ia[i];
            ilast = i;
        }
        --j;
    }

    for (int j = jmin; j <= jmax; ++j) {
        while (r[j] != (j + 1)) {
            int k = r[j] - 1;
            std::swap(r[j], r[k]);
            std::swap(ja[k], ja[j]);
            std::swap(a[k], a[j]);
        }
    }
}

void printVector(const std::vector<int>& vec, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void printVector(const std::vector<double>& vec, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 5;
    std::vector<int> ip = {1, 2, 3, 4, 5};
    std::vector<int> ia = {1, 2, 3, 4, 5, 6}; // Including extra element for n+1 indexing
    std::vector<int> ja = {1, 2, 3, 4, 5};
    std::vector<double> a = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<int> q(n, 0); // Initialize with 0
    std::vector<int> r(n, 0); // Initialize with 0
    bool dflag = true;

    sro(n, ip, ia, ja, a, q, r, dflag);
    
    printVector(q, "q");
    printVector(r, "r");
    printVector(ia, "ia");
    printVector(ja, "ja");
    printVector(a, "a");

    return 0;
}