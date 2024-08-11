#include <gtest/gtest.h>
#include <string>

// Directly define the ModReport class in this file
class ModReport {
public:
    int tests = 0;
    int nfailed = 0;
    int npassed = 0;
    int reportfileu = 0;
    std::string reportfilename;
    std::string testplan_name;
    std::string tdirectory;
    std::string testunitname;
    std::string inputf;
    std::string outputf;

    // Constructor, destructor, and other member functions as needed
    ModReport() = default;
    ~ModReport() = default;
};

// Unit tests for ModReport
TEST(ModReportTest, Initialization) {
    ModReport mr;
    
    EXPECT_EQ(mr.tests, 0);
    EXPECT_EQ(mr.nfailed, 0);
    EXPECT_EQ(mr.npassed, 0);
    EXPECT_EQ(mr.reportfileu, 0);
    EXPECT_TRUE(mr.reportfilename.empty());
    EXPECT_TRUE(mr.testplan_name.empty());
    EXPECT_TRUE(mr.tdirectory.empty());
    EXPECT_TRUE(mr.testunitname.empty());
    EXPECT_TRUE(mr.inputf.empty());
    EXPECT_TRUE(mr.outputf.empty());
}

TEST(ModReportTest, Modification) {
    ModReport mr;
    
    mr.tests = 5;
    mr.nfailed = 1;
    mr.npassed = 4;
    mr.reportfileu = 10;
    mr.reportfilename = "report.txt";
    mr.testplan_name = "main plan";
    mr.tdirectory = "/tmp";
    mr.testunitname = "unit1";
    mr.inputf = "input.txt";
    mr.outputf = "output.txt";

    EXPECT_EQ(mr.tests, 5);
    EXPECT_EQ(mr.nfailed, 1);
    EXPECT_EQ(mr.npassed, 4);
    EXPECT_EQ(mr.reportfileu, 10);
    EXPECT_EQ(mr.reportfilename, "report.txt");
    EXPECT_EQ(mr.testplan_name, "main plan");
    EXPECT_EQ(mr.tdirectory, "/tmp");
    EXPECT_EQ(mr.testunitname, "unit1");
    EXPECT_EQ(mr.inputf, "input.txt");
    EXPECT_EQ(mr.outputf, "output.txt");
}

// Main function for the test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}