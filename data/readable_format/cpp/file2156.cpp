#include <vector>

struct BalanceColorsSimple {
    int NGLOB;
    int NSPEC;
    std::vector<std::vector<std::vector<std::vector<int>>>> IBOOL;
    std::vector<bool> IS_ON_A_SLICE_EDGE;
    std::vector<bool> ISPEC_IS_D;
    int MYRANK;
    std::vector<int> COLOR;
    int NB_COLORS_OUTER_ELEMENTS;
    int NB_COLORS_INNER_ELEMENTS;
    int NSPEC_OUTER;
    int NSPEC_INNER;
    std::vector<bool> MASK_IBOOL;

    BalanceColorsSimple(int nglob, int nspec) 
        : NGLOB(nglob), NSPEC(nspec), 
          IBOOL(5, std::vector<std::vector<std::vector<int>>>(5, std::vector<std::vector<int>>(5, std::vector<int>(NSPEC)))),
          IS_ON_A_SLICE_EDGE(NSPEC), ISPEC_IS_D(NSPEC), COLOR(NSPEC), MASK_IBOOL(NGLOB) {}
    
    void balance_colors_simple() {
        // Implement the logic of the subroutine here
    }
};

int main() {
    int nglob = /* ... initialize appropriately ... */;
    int nspec = /* ... initialize appropriately ... */;
    
    BalanceColorsSimple balancer(nglob, nspec);
    balancer.balance_colors_simple();
    
    return 0;
}