#include <iostream>
#include <cstring>
#include <array>
#include <cstdint>

namespace NWTC_Base {

    constexpr std::size_t BITS_IN_ADDR = sizeof(std::intptr_t) * 8;
    constexpr std::size_t ErrMsgLen = 1024;
    
    constexpr std::intptr_t ChanLen = 10;
    constexpr std::intptr_t NWTC_Verbose = 10;
    constexpr std::intptr_t NWTC_VerboseLevel = 5;

    constexpr std::intptr_t ErrID_None = 0;
    constexpr std::intptr_t ErrID_Info = 1;
    constexpr std::intptr_t ErrID_Warn = 2;
    constexpr std::intptr_t ErrID_Severe = 3;
    constexpr std::intptr_t ErrID_Fatal = 4;

    std::intptr_t AbortErrLev = ErrID_Fatal;
    
    constexpr std::intptr_t NWTC_MAX_DLL_PROC = 3;

    struct DLL_Type {
        std::intptr_t FileAddr{};
        void* FileAddrX{nullptr};
        std::array<void(*)(), NWTC_MAX_DLL_PROC> ProcAddr{};
        char FileName[ErrMsgLen]{};
        std::array<char[ErrMsgLen], NWTC_MAX_DLL_PROC> ProcName{};

        DLL_Type() {
            std::memset(FileName, 0, ErrMsgLen);
            for (auto& name : ProcName) {
                std::memset(name, 0, ErrMsgLen);
            }
        }
    };
}

// Simple test function to verify initialization of DLL_Type members
void test_DLL_Type_initialization() {
    using namespace NWTC_Base;
    bool testsPassed = true;
    DLL_Type dll;

    if (dll.FileAddrX != nullptr) {
        std::cout << "FAIL: FileAddrX is not initialized to nullptr." << std::endl;
        testsPassed = false;
    }

    for (const auto& procAddr : dll.ProcAddr) {
        if (procAddr != nullptr) {
            std::cout << "FAIL: ProcAddr entry is not initialized to nullptr." << std::endl;
            testsPassed = false;
        } else {
            std::cout << "PASS: ProcAddr entry is initialized to nullptr." << std::endl;
        }
    }

    if (std::strlen(dll.FileName) != 0) {
        std::cout << "FAIL: FileName is not initialized to an empty string." << std::endl;
        testsPassed = false;
    } else {
        std::cout << "PASS: FileName is initialized to an empty string." << std::endl;
    }

    for (const auto& procName : dll.ProcName) {
        if (std::strlen(procName) != 0) {
            std::cout << "FAIL: ProcName entry is not initialized to an empty string." << std::endl;
            testsPassed = false;
        } else {
            std::cout << "PASS: ProcName entry is initialized to an empty string." << std::endl;
        }
    }

    if (testsPassed) {
        std::cout << "All tests PASSED." << std::endl;
    } else {
        std::cout << "Some tests FAILED." << std::endl;
    }
}

int main() {
    test_DLL_Type_initialization();
    return 0;
}