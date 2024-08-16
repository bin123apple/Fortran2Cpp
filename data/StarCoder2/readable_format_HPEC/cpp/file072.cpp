#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int dp = sizeof(double);
    const int n = 180;
    std::vector<double> base(2025);
    std::vector<double*> xa1(2025, nullptr), xa2(2025, nullptr);

    // In C++, vectors are 0-based, so we adjust the indices accordingly.
    // Also, we directly use the vector 'base' as xa1 and xa2 point to it.
    xa1 = &base;
    xa2 = &base;

    // Initialize base array
    for (int i = 0; i < 2025; ++i) {
        base[i] = 0.5 * (i + 1);
    }

    // Index set for the loop
    std::vector<int> indexSet = {
        520, 532, 524, 526, 528, 530, 546, 548,
        550, 552, 554, 556, 572, 574, 576, 578, 580, 582, 598,
        600, 602, 604, 606, 608, 624, 626, 628, 630, 632, 634,
        650, 652, 654, 656, 658, 660, 858, 860, 862, 864, 866,
        868, 884, 886, 888, 890, 892, 894, 910, 912, 914, 916,
        918, 920, 936, 938, 940, 942, 944, 946, 962, 964, 966,
        968, 970, 972, 988, 990, 992, 994, 996, 998, 1196, 1198,
        1200, 1202, 1204, 1206, 1222, 1224, 1226, 1228, 1230,
        1232, 1248, 1250, 1252, 1254, 1256, 1258, 1274, 1276,
        1278, 1280, 1282, 1284, 1300, 1302, 1304, 1306, 1308,
        1310, 1326, 1328, 1330, 1332, 1334, 1336, 1534, 1536,
        1538, 1540, 1542, 1544, 1560, 1562, 1564, 1566, 1568,
        1570, 1586, 1588, 1590, 1592, 1594, 1596, 1612, 1614,
        1616, 1618, 1620, 1622, 1638, 1640, 1642, 1644, 1646,
        1648, 1664, 1666, 1668, 1670, 1672, 1674, 1872, 1874,
        1876, 1878, 1880, 1882, 1898, 1900, 1902, 1904, 1906,
        1908, 1924, 1926, 1928, 1930, 1932, 1934, 1950, 1952,
        1954, 1956, 1958, 1960, 1976, 1978, 1980, 1982, 1984,
        1986, 2002, 2004, 2006, 2008, 2010, 2012
    };

    // Parallel loop with OpenMP
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        int idx1 = indexSet[i];
        int idx2 = indexSet[i] + 12;
        base[idx1] += 1.0;
        base[idx2] += 3.0;
    }

    // Print results
    std::cout << "xa1[998] = " << base[998] << " xa2[1284] = " << base[1284] << std::endl;

    // No need to explicitly deallocate xa1 and xa2 as they point to the same vector base
    return 0;
}
