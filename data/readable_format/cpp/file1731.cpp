#include <gtest/gtest.h>
#include <string>

// Definition of the DataDiag class directly in this file
class DataDiag {
public:
    bool dump_mesh_info_files;
    bool dump_mesh_info_screen;
    bool dump_mesh_vtk;
    bool dump_1dmodel;
    bool only_suggest_ntheta;
    std::string diagpath;
    int lfdiag;

    // Constructor to initialize members
    DataDiag()
        : dump_mesh_info_files(false),
          dump_mesh_info_screen(false),
          dump_mesh_vtk(false),
          dump_1dmodel(false),
          only_suggest_ntheta(false),
          diagpath(""),
          lfdiag(0) {}
};

// Test cases for the DataDiag class
TEST(DataDiagTest, Initialization) {
    DataDiag dd;

    EXPECT_FALSE(dd.dump_mesh_info_files);
    EXPECT_FALSE(dd.dump_mesh_info_screen);
    EXPECT_FALSE(dd.dump_mesh_vtk);
    EXPECT_FALSE(dd.dump_1dmodel);
    EXPECT_FALSE(dd.only_suggest_ntheta);
    EXPECT_EQ(dd.diagpath, "");
    EXPECT_EQ(dd.lfdiag, 0);
}

TEST(DataDiagTest, VariableAssignment) {
    DataDiag dd;
    dd.dump_mesh_info_files = true;
    dd.dump_mesh_info_screen = false;
    dd.dump_mesh_vtk = true;
    dd.dump_1dmodel = false;
    dd.only_suggest_ntheta = true;
    dd.diagpath = "path/to/diagnostics";
    dd.lfdiag = 123;

    EXPECT_TRUE(dd.dump_mesh_info_files);
    EXPECT_FALSE(dd.dump_mesh_info_screen);
    EXPECT_TRUE(dd.dump_mesh_vtk);
    EXPECT_FALSE(dd.dump_1dmodel);
    EXPECT_TRUE(dd.only_suggest_ntheta);
    EXPECT_EQ(dd.diagpath, "path/to/diagnostics");
    EXPECT_EQ(dd.lfdiag, 123);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}