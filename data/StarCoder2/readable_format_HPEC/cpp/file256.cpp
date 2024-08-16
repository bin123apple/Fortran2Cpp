#include <vector>

// Assuming DATA_TYPE is a double for this example
using DATA_TYPE = double;

void init_array(int cz, int cxm, int cym, DATA_TYPE& mui, DATA_TYPE& ch, 
               std::vector<std::vector<std::vector<DATA_TYPE>>>& ex, 
               std::vector<std::vector<std::vector<DATA_TYPE>>>& ey, 
               std::vector<std::vector<std::vector<DATA_TYPE>>>& hz, 
               std::vector<std::vector<DATA_TYPE>>& ry, 
               std::vector<std::vector<DATA_TYPE>>& ax, 
               std::vector<DATA_TYPE>& cymh, 
               std::vector<DATA_TYPE>& cyph, 
               std::vector<DATA_TYPE>& cxmh, 
               std::vector<DATA_TYPE>& cxph, 
               std::vector<DATA_TYPE>& czm, 
               std::vector<DATA_TYPE>& czp) {
    
    mui = 2341;
    ch = 42;
    
    for (int i = 0; i <= cz; ++i) {
        czm[i] = (static_cast<DATA_TYPE>(i) + 1.0) / static_cast<DATA_TYPE>(cxm);
        czp[i] = (static_cast<DATA_TYPE>(i) + 2.0) / static_cast<DATA_TYPE>(cxm);
    }
    
    for (int i = 0; i <= cxm; ++i) {
        cxmh[i] = (static_cast<DATA_TYPE>(i) + 3.0) / static_cast<DATA_TYPE>(cxm);
        cxph[i] = (static_cast<DATA_TYPE>(i) + 4.0) / static_cast<DATA_TYPE>(cxm);
    }
    
    for (int i = 0; i <= cym; ++i) {
        cymh[i] = (static_cast<DATA_TYPE>(i) + 5.0) / static_cast<DATA_TYPE>(cxm);
        cyph[i] = (static_cast<DATA_TYPE>(i) + 6.0) / static_cast<DATA_TYPE>(cxm);
    }
    
    for (int i = 0; i <= cz; ++i) {
        for (int j = 0; j <= cym; ++j) {
            ry[j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) + 10.0) / static_cast<DATA_TYPE>(cym);
            ax[j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1)) + 11.0) / static_cast<DATA_TYPE>(cym);
            for (int k = 0; k <= cxm; ++k) {
                ex[k][j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 2)) + static_cast<DATA_TYPE>(k) + 1.0) / static_cast<DATA_TYPE>(cxm);
                ey[k][j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 3)) + static_cast<DATA_TYPE>(k) + 2.0) / static_cast<DATA_TYPE>(cym);
                hz[k][j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 4)) + static_cast<DATA_TYPE>(k) + 3.0) / static_cast<DATA_TYPE>(cz);
            }
        }
    }
}

int main() {
    // Example usage
    int cz = 10, cxm = 10, cym = 10;
    DATA_TYPE mui, ch;
    std::vector<std::vector<std::vector<DATA_TYPE>>> ex(cxm + 1, std::vector<std::vector<DATA_TYPE>>(cym + 1, std::vector<DATA_TYPE>(cz + 1)));
    std::vector<std::vector<std::vector<DATA_TYPE>>> ey(cxm + 1, std::vector<std::vector<DATA_TYPE>>(cym + 1, std::vector<DATA_TYPE>(cz + 1)));
    std::vector<std::vector<std::vector<DATA_TYPE>>> hz(cxm + 1, std::vector<std::vector<DATA_TYPE>>(cym + 1, std::vector<DATA_TYPE>(cz + 1)));
    std::vector<std::vector<DATA_TYPE>> ry(cym + 1, std::vector<DATA_TYPE>(cz + 1));
    std::vector<std::vector<DATA_TYPE>> ax(cym + 1, std::vector<DATA_TYPE>(cz + 1));
    std::vector<DATA_TYPE> cymh(cym + 1), cyph(cym + 1), cxmh(cxm + 1), cxph(cxm + 1), czm(cz + 1), czp(cz + 1);

    init_array(cz, cxm, cym, mui, ch, ex, ey, hz, ry, ax, cymh, cyph, cxmh, cxph, czm, czp);

    // Add further code to use the initialized arrays
    return 0;
}
