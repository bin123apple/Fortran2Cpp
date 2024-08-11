#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <utility> // for std::pair

// Definition of ToxicityRelationships directly in this file
class ToxicityRelationships {
public:
    void addRelationship(const std::string& lessToxic, const std::string& moreToxic) {
        relationships.emplace_back(lessToxic, moreToxic);
    }

    bool isLessToxic(const std::string& substance1, const std::string& substance2) {
        for (const auto& relation : relationships) {
            if (relation.first == substance1 && relation.second == substance2) {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<std::pair<std::string, std::string>> relationships;
};

// Test Fixture for ToxicityRelationships
class ToxicityRelationshipsTest : public ::testing::Test {
protected:
    ToxicityRelationships tr;

    void SetUp() override {
        // Setup some basic relationships for testing:
        tr.addRelationship("q1", "dd1");
        tr.addRelationship("s1", "h1");
        tr.addRelationship("kk1", "jj1");
        tr.addRelationship("x1", "t1");
        // Add more as needed for comprehensive testing
    }
};

// Test cases
TEST_F(ToxicityRelationshipsTest, CorrectlyIdentifiesRelationship) {
    EXPECT_TRUE(tr.isLessToxic("q1", "dd1"));
    EXPECT_TRUE(tr.isLessToxic("s1", "h1"));
    EXPECT_FALSE(tr.isLessToxic("dd1", "q1")); // Reverse relationship should not exist
    EXPECT_FALSE(tr.isLessToxic("t1", "x1")); // Reverse relationship should not exist
}

TEST_F(ToxicityRelationshipsTest, ReturnsFalseForNonExistentRelationship) {
    EXPECT_FALSE(tr.isLessToxic("q1", "s1")); // No direct relationship defined
    EXPECT_FALSE(tr.isLessToxic("nonexistent1", "nonexistent2")); // Totally non-existent
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}