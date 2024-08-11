#include <vector>

// Define the Synapse class
class Synapse {
public:
    float weight;
    float delta;

    Synapse() : weight(0.0f), delta(0.0f) {}
};

// Define the Neuron class
class Neuron {
public:
    std::vector<Synapse> synapses;
    int nextLayerSize;
    float output;
    int id;

    Neuron() : nextLayerSize(0), output(0.0f), id(0) {}
};

// Define the Layer class
class Layer {
public:
    int id;
    int layerSize;
    std::vector<Neuron> neurons;

    Layer() : id(0), layerSize(0) {}
};

// Define the Net class
class Net {
public:
    int numberOfLayers;
    std::vector<int> topology;
    std::vector<Layer> layers;

    Net() : numberOfLayers(0) {}
};

int main() {
    // Example usage
    Net neuralNetwork;
    neuralNetwork.numberOfLayers = 3;
    neuralNetwork.topology = { 2, 3, 1 };
    neuralNetwork.layers.resize(3);

    return 0;
}