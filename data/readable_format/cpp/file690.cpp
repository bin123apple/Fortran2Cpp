#include <iostream>

struct FcnParms {
    int i;
};

namespace type_decl {
    struct FcnParms {
        int i;
    };
}

class Test {
public:
    using FuncPtr = float (*)(const FcnParms&);
    using FuncPtrTypeDecl = float (*)(const type_decl::FcnParms&);

    static void sim_1(FuncPtr func, const FcnParms& params) {
        std::cout << "Calling sim_1 with i = " << params.i << std::endl;
        std::cout << "Result from func1: " << func(params) << std::endl;
    }

    static void sim_2(FuncPtr func, const FcnParms& params) {
        std::cout << "Calling sim_2 with i = " << params.i << std::endl;
        std::cout << "Result from func2: " << func(params) << std::endl;
    }
};

void sim_3(Test::FuncPtrTypeDecl func, const type_decl::FcnParms& params) {
    std::cout << "Calling sim_3 with i = " << params.i << std::endl;
    std::cout << "Result from func3: " << func(params) << std::endl;
}

float exampleFunc1(const FcnParms& params) {
    return params.i * 2.0f;
}

float exampleFunc3(const type_decl::FcnParms& params) {
    return params.i * 2.0f;
}

int main() {
    FcnParms params1 {10};
    type_decl::FcnParms params2 {10};

    Test::sim_1(exampleFunc1, params1);
    Test::sim_2(exampleFunc1, params1);
    sim_3(exampleFunc3, params2);

    return 0;
}