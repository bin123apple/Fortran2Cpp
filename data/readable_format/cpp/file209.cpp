#include <iostream>
#include <vector>
#include <string>

class SimulatedMPIEnvironment {
public:
    SimulatedMPIEnvironment(int simulatedRank, int simulatedSize)
        : rank(simulatedRank), size(simulatedSize) {}

    int getRank() const { return rank; }
    int getSize() const { return size; }

    void allGather(int sendVal, std::vector<int>& recvVals) {
        recvVals.clear();
        for (int i = 0; i < size; i++) {
            recvVals.push_back(i);
        }
    }

    void broadcast(int& value, int rootRank) {
        value = 123; // Simulated value
    }

private:
    int rank;
    int size;
};

int main() {
    int simulatedRank = 0;
    int simulatedSize = 4;
    SimulatedMPIEnvironment env(simulatedRank, simulatedSize);

    int broadcastValue;
    std::vector<int> gatheredValues;

    env.allGather(env.getRank(), gatheredValues);
    env.broadcast(broadcastValue, 0);

    std::cout << "Simulated gather result: ";
    for (int val : gatheredValues) {
        std::cout << val << " ";
    }
    std::cout << std::endl; // Correcting the line break issue

    std::cout << "Simulated broadcast result: " << broadcastValue << std::endl;

    return 0;
}