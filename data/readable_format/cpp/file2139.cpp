#include <iostream>
#include <vector>
#include <algorithm>

class PpmUtil {
public:
    static std::vector<int> invertList(const std::vector<int>& list) {
        std::vector<int> invertedList = list;
        std::reverse(invertedList.begin(), invertedList.end());
        return invertedList;
    }
};

int main() {
    std::vector<int> myList = {1, 2, 3, 4, 5};
    std::vector<int> invertedList = PpmUtil::invertList(myList);

    std::cout << "Original List: ";
    for (int num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Inverted List: ";
    for (int num : invertedList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}