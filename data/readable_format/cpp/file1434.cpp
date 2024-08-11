#include <vector>
#include <gtest/gtest.h>
#include <omp.h>

// ScalarPool class definition
class ScalarPool {
private:
    std::vector<float> pool;
    omp_lock_t lock;

public:
    ScalarPool(int size) : pool(size, 0.0f) {
        omp_init_lock(&lock);
    }

    ~ScalarPool() {
        omp_destroy_lock(&lock);
    }

    void acquireResource(int id, float& resource) {
        omp_set_lock(&lock);
        if (id >= 0 && id < pool.size()) {
            resource = pool[id];
        } else {
            resource = -1.0f; // Indicate error
        }
        omp_unset_lock(&lock);
    }

    void releaseResource(int id, float resource) {
        omp_set_lock(&lock);
        if (id >= 0 && id < pool.size()) {
            pool[id] = resource;
        }
        omp_unset_lock(&lock);
    }
};

// Unit tests using Google Test
TEST(ScalarPoolTest, SuccessfulResourceAcquisition) {
    ScalarPool pool(10);
    float resource;
    pool.acquireResource(1, resource);
    EXPECT_EQ(resource, 0.0f); // Default value
}

TEST(ScalarPoolTest, ResourceAcquisitionOutOfBounds) {
    ScalarPool pool(10);
    float resource;
    pool.acquireResource(11, resource);
    EXPECT_EQ(resource, -1.0f); // Error indication
}

TEST(ScalarPoolTest, ProperResourceRelease) {
    ScalarPool pool(10);
    float resource = 5.0f;
    pool.releaseResource(1, resource);
    resource = 0.0f; // Reset resource
    pool.acquireResource(1, resource);
    EXPECT_EQ(resource, 5.0f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}