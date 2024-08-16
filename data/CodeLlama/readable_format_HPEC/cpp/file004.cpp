#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 180;
    std::vector<int> indexSet(N);
    std::vector<double> base(2025, 0.0); // Initialize with 0.0
    std::vector<double*> xa1(2), xa2(2);

    // Initialize indexSet with the given values
    indexSet = {521, 523, 525, 527, 529, 531, 547, 549, 
                551, 553, 555, 557, 573, 575, 577, 579, 581, 583, 599, 
                601, 603, 605, 607, 609, 625, 627, 629, 631, 633, 635, 
                651, 653, 655, 657, 659, 661, 859, 861, 863, 865, 867, 
                869, 885, 887, 889, 891, 893, 895, 911, 913, 915, 917, 
                919, 921, 937, 939, 941, 943, 945, 947, 963, 965, 967, 
                969, 971, 973, 989, 991, 993, 995, 997, 999, 1197, 1199, 
                1201, 1203, 1205, 1207, 1223, 1225, 1227, 1229, 1231, 
                1233, 1249, 1251, 1253, 1255, 1257, 1259, 1275, 1277, 
                1279, 1281, 1283, 1285, 1301, 1303, 1305, 1307, 1309, 
                1311, 1327, 1329, 1331, 1333, 1335, 1337, 1535, 1537, 
                1539, 1541, 1543, 1545, 1561, 1563, 1565, 1567, 1569, 
                1571, 1587, 1589, 1591, 1593, 1595, 1597, 1613, 1615, 
                1617, 1619, 1621, 1623, 1639, 1641, 1643, 1645, 1647, 
                1649, 1665, 1667, 1669, 1671, 1673, 1675, 1873, 1875, 
                1877, 1879, 1881, 1883, 1899, 1901, 1903, 1905, 1907, 
                1909, 1925, 1927, 1929, 1931, 1933, 1935, 1951, 1953, 
                1955, 1957, 1959, 1961, 1977, 1979, 1981, 1983, 1985, 
                1987, 2003, 2005, 2007, 2009, 2011, 2013};

    // Pointers to the beginning of each segment of base
    xa1[0] = &base[0];
    xa2[0] = &base[0];

    // Parallel loop to update base values
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; ++i) {
        int idx1 = indexSet[i] - 521;
        int idx2 = (indexSet[i] + 12) - 521;
        xa1[0][idx1] = 1.0;
        xa2[0][idx2] = 3.0;
    }

    // Check and print the updated values
    for (int i = 0; i < 2025; ++i) {
        if (base[i] == 4.0) {
            std::cout << "i= " << i + 521 << " base = " << base[i] << std::endl;
        }
    }

    // No need to explicitly deallocate or nullify in C++
    return 0;
}
