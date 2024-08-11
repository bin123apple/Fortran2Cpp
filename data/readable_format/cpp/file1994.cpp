#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include <type_traits>

// A helper to check if a type is a container (simplified, consider more traits for production)
template<typename T>
struct is_container {
    private:
        template<typename U>
        static auto check(U* ptr) -> decltype(std::begin(*ptr), std::end(*ptr), std::true_type());

        template<typename>
        static std::false_type check(...);

    public:
        static constexpr bool value = decltype(check<T>(nullptr))::value;
};

template<typename T>
void inner(T& dummy) {
    if constexpr (is_container<T>::value) {
        std::cout << "Processing a container" << std::endl;
        for (auto& element : dummy) {
            std::cout << "Element: " << element << std::endl;
        }
    } else {
        std::cout << "Processing a single value: " << dummy << std::endl;
    }
}

template<typename Container1, typename Container2, typename T>
void s(Container1& arg1, Container2& arg2, T& arg3) {
    inner(arg1);
    inner(arg2);
    inner(arg3);
}

TEST(SFunctionTest, HandlesDifferentTypes) {
    std::vector<int> vecInt = {1, 2, 3};
    std::vector<double> vecDouble = {1.1, 2.2, 3.3};
    int singleInt = 10;

    EXPECT_NO_THROW(s(vecInt, vecDouble, singleInt));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}