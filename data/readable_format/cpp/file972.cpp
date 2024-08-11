#include <gtest/gtest.h>
#include <memory>

// Define the `line_search` class directly in this file
class line_search {
public:
    // Constructor, Destructor, and any other necessary member functions
    line_search() = default;
    virtual ~line_search() = default;
};

// Define the `line_search_solver` class directly in this file
class line_search_solver {
private:
    std::unique_ptr<line_search> m_lineSearch;
    bool m_useLineSearch;

public:
    // Constructors, etc.
    line_search_solver() : m_useLineSearch(false) {}

    void get_line_search(std::unique_ptr<line_search>& ls) const {
        if (m_lineSearch) {
            ls = std::make_unique<line_search>(*m_lineSearch);
        }
    }

    void set_line_search(const line_search& ls) {
        m_lineSearch = std::make_unique<line_search>(ls);
    }

    void set_default() {
        line_search ls; // Assuming default constructible
        set_line_search(ls);
    }

    bool is_line_search_defined() const {
        return m_lineSearch != nullptr;
    }

    bool get_use_search() const {
        return m_useLineSearch;
    }

    void set_use_search(bool x) {
        m_useLineSearch = x;
    }
};

// Now, directly integrate tests into this file
// Test setting and getting a line search object
TEST(LineSearchSolverTest, SetAndGetLineSearch) {
    line_search_solver solver;
    std::unique_ptr<line_search> ls = std::make_unique<line_search>();
    solver.set_line_search(*ls);

    std::unique_ptr<line_search> ls_out;
    solver.get_line_search(ls_out);

    EXPECT_TRUE(ls_out != nullptr);
}

// Test if a line search is defined
TEST(LineSearchSolverTest, IsLineSearchDefined) {
    line_search_solver solver;

    EXPECT_FALSE(solver.is_line_search_defined());

    line_search ls; // Assuming default constructible
    solver.set_line_search(ls);

    EXPECT_TRUE(solver.is_line_search_defined());
}

// Test toggling the usage of line search
TEST(LineSearchSolverTest, SetUseSearch) {
    line_search_solver solver;
    solver.set_use_search(true);

    EXPECT_TRUE(solver.get_use_search());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}