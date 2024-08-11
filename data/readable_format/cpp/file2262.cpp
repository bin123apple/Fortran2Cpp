#include <iostream>

class PpmModuleTopoGet {
public:
    void ppmTopoGet() {
        // Placeholder for ppmTopoGet implementation
        std::cout << "ppmTopoGet called" << std::endl;
    }
    
    template <typename T>
    void ppmTopoGetDecomp() {
        // Placeholder for ppmTopoGetDecomp implementation
        // Specialize this template function for float and double
        std::cout << "ppmTopoGetDecomp called with type " << typeid(T).name() << std::endl;
    }
    
    void ppmTopoGetMeshinfo() {
        // Placeholder for ppmTopoGetMeshinfo implementation
        std::cout << "ppmTopoGetMeshinfo called" << std::endl;
    }
};

// Specializations for ppmTopoGetDecomp for float and double
template<>
void PpmModuleTopoGet::ppmTopoGetDecomp<float>() {
    std::cout << "ppmTopoGetDecomp (float) called" << std::endl;
    // Actual float-specific implementation here
}

template<>
void PpmModuleTopoGet::ppmTopoGetDecomp<double>() {
    std::cout << "ppmTopoGetDecomp (double) called" << std::endl;
    // Actual double-specific implementation here
}

int main() {
    PpmModuleTopoGet module;
    module.ppmTopoGet();
    module.ppmTopoGetDecomp<float>();
    module.ppmTopoGetDecomp<double>();
    module.ppmTopoGetMeshinfo();
    
    return 0;
}