#include <iostream>
#include <memory>
#include <gtest/gtest.h>

// Forward declaration of StateT in HydroState to be used in HydroFlow and MockState
class HydroState {
public:
    class StateT {
    public:
        virtual ~StateT() = default;
        virtual void assign(const StateT& that) = 0;
        StateT& operator=(const StateT& that) {
            if (this != &that) {
                assign(that);
            }
            return *this;
        }
    };
};

// MockState definition for testing
class MockState : public HydroState::StateT {
public:
    int value = 0;

    MockState(int val = 0) : value(val) {}
    MockState(const MockState& other) : value(other.value) {}

    void assign(const StateT& that) override {
        const MockState& mThat = dynamic_cast<const MockState&>(that);
        value = mThat.value;
    }
};

// HydroFlow declaration, now correctly aware of MockState
class HydroFlow {
public:
    class FlowT {
    public:
        std::unique_ptr<HydroState::StateT> st;

        void initComps(const std::shared_ptr<HydroState::StateT>& stPtr) {
            st = std::make_unique<MockState>(*dynamic_cast<const MockState*>(stPtr.get()));
        }
    };
};

// Unit tests using Google Test
TEST(HydroTest, TestAssign) {
    std::shared_ptr<HydroState::StateT> state1 = std::make_shared<MockState>(10);
    std::shared_ptr<HydroState::StateT> state2 = std::make_shared<MockState>(20);

    // Perform assignment
    *state1 = *state2;

    // Check if the assignment was successful
    EXPECT_EQ(dynamic_cast<MockState&>(*state1).value, 20);
}

TEST(HydroTest, TestInitComps) {
    std::shared_ptr<HydroState::StateT> state = std::make_shared<MockState>(30);
    HydroFlow::FlowT flow;

    // Initialize components
    flow.initComps(state);

    // Check if initComps worked correctly
    EXPECT_EQ(dynamic_cast<MockState&>(*flow.st).value, 30);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}