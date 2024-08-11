#include <vector>
#include <cassert>
#include <iostream>

// Definitions of the structs directly in this file
struct irjc_square_matrix {
    int neqns; // Equates to integer(kind=kint) in Fortran
    int nttbr;
    int ndeg;
    std::vector<int> irow; // Replaces integer, pointer :: irow(:) in Fortran
    std::vector<int> jcol; // Replaces integer, pointer :: jcol(:) in Fortran
    std::vector<std::vector<double>> val; // Replaces real(kind=kreal), pointer :: val(:,:) in Fortran
};

struct irjc_mn_matrix {
    int nrows; // Equates to integer(kind=kint) in Fortran
    int ncols;
    int nttbr;
    int ndeg;
    std::vector<int> irow; // Replaces integer(kind=kint), pointer :: irow(:) in Fortran
    std::vector<int> jcol; // Replaces integer(kind=kint), pointer :: jcol(:) in Fortran
    std::vector<std::vector<double>> val; // Replaces real(kind=kreal), pointer :: val(:,:) in Fortran
};

// Main function including unit tests
int main() {
    irjc_square_matrix square_matrix;
    
    // Initialize some data
    std::vector<int> indices = {1, 2, 3};
    std::vector<std::vector<double>> matrix_values(3, std::vector<double>(3));
    for(int i = 0; i < 3; ++i) {
        matrix_values[i] = std::vector<double>{double(i+1), double(i+1), double(i+1)};
    }

    // Assign values to the square_matrix structure
    square_matrix.neqns = 3;
    square_matrix.nttbr = 2;
    square_matrix.ndeg = 1;
    square_matrix.irow = indices;
    square_matrix.jcol = indices;
    square_matrix.val = matrix_values;

    // Assertions to verify the correctness
    assert(square_matrix.neqns == 3);
    assert(square_matrix.nttbr == 2);
    assert(square_matrix.ndeg == 1);
    for(size_t i = 0; i < square_matrix.irow.size(); ++i) {
        assert(square_matrix.irow[i] == i + 1);
        assert(square_matrix.jcol[i] == i + 1);
    }
    for(size_t i = 0; i < square_matrix.val.size(); ++i) {
        for(size_t j = 0; j < square_matrix.val[i].size(); ++j) {
            assert(square_matrix.val[i][j] == i + 1);
        }
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}