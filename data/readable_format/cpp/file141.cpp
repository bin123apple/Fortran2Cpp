#include <gtest/gtest.h>
#include <iostream>

// DynamicArray3D definition
class DynamicArray3D {
private:
    float*** data;
    int xSize, ySize, zSize;
public:
    DynamicArray3D(int x, int y, int z) : xSize(x), ySize(y), zSize(z) {
        data = new float**[xSize];
        for (int i = 0; i < xSize; ++i) {
            data[i] = new float*[ySize];
            for (int j = 0; j < ySize; ++j) {
                data[i][j] = new float[zSize];
                for (int k = 0; k < zSize; ++k) {
                    data[i][j][k] = 0; // Initialize array elements to 0
                }
            }
        }
    }

    ~DynamicArray3D() {
        for (int i = 0; i < xSize; ++i) {
            for (int j = 0; j < ySize; ++j) {
                delete[] data[i][j];
            }
            delete[] data[i];
        }
        delete[] data;
    }

    float& operator()(int x, int y, int z) {
        return data[x][y][z];
    }

    void fill(float value) {
        for (int i = 0; i < xSize; ++i) {
            for (int j = 0; j < ySize; ++j) {
                for (int k = 0; k < zSize; ++k) {
                    data[i][j][k] = value;
                }
            }
        }
    }
};

// DynamicArray2D definition
class DynamicArray2D {
private:
    float** data;
    int xSize, ySize;
public:
    DynamicArray2D(int x, int y) : xSize(x), ySize(y) {
        data = new float*[xSize];
        for (int i = 0; i < xSize; ++i) {
            data[i] = new float[ySize];
            for (int j = 0; j < ySize; ++j) {
                data[i][j] = 0; // Initialize array elements to 0
            }
        }
    }

    ~DynamicArray2D() {
        for (int i = 0; i < xSize; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    float& operator()(int x, int y) {
        return data[x][y];
    }

    void fill(float value) {
        for (int i = 0; i < xSize; ++i) {
            for (int j = 0; j < ySize; ++j) {
                data[i][j] = value;
            }
        }
    }
};

// Test cases
TEST(DynamicArray3DTest, ElementAssignmentAndAccess) {
    DynamicArray3D array(10, 10, 10);
    array.fill(1311);
    array(2, 5, 8) = 42;

    EXPECT_EQ(array(2, 5, 8), 42);
    EXPECT_EQ(array(0, 0, 0), 1311);
}

TEST(DynamicArray3DTest, PointerReassignment) {
    DynamicArray3D vla1(10, 10, 10);
    DynamicArray3D vla2(7, 9, 23);

    DynamicArray3D* pvla = &vla1;
    pvla = &vla2;
    vla2(4, 3, 6) = 42;

    EXPECT_EQ((*pvla)(4, 3, 6), 42);
}

TEST(DynamicArray2DTest, FillAndAccess) {
    DynamicArray2D array(2, 2);
    array.fill(13);

    EXPECT_EQ(array(0, 0), 13);
    EXPECT_EQ(array(1, 1), 13);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}