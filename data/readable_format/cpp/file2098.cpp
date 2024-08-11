#include <iostream>
#include <cstdint>

// Namespace containing the constants, directly in the source file
namespace fortium_defines {

    constexpr std::int64_t crypto_hash_sha512_BYTES = 64;

    constexpr std::int64_t crypto_auth_hmacsha512_BYTES = 64;
    constexpr std::int64_t crypto_auth_hmacsha512_KEYBYTES = 64;

    constexpr const char *crypto_auth_PRIMITIVE = "hmacsha512256";

    constexpr std::int64_t crypto_auth_hmacsha512256_BYTES = 32;
    constexpr std::int64_t crypto_auth_hmacsha512256_KEYBYTES = 32;
    constexpr std::int64_t crypto_auth_BYTES = crypto_auth_hmacsha512256_BYTES;
    constexpr std::int64_t crypto_auth_KEYBYTES = crypto_auth_hmacsha512256_KEYBYTES;

}

// Test code to verify the constants
int main() {
    using namespace std;
    cout << "Testing C++ constants..." << endl;
    cout << "crypto_hash_sha512_BYTES = " << fortium_defines::crypto_hash_sha512_BYTES << endl;
    cout << "crypto_auth_hmacsha512_BYTES = " << fortium_defines::crypto_auth_hmacsha512_BYTES << endl;
    cout << "crypto_auth_hmacsha512_KEYBYTES = " << fortium_defines::crypto_auth_hmacsha512_KEYBYTES << endl;
    cout << "crypto_auth_PRIMITIVE = " << fortium_defines::crypto_auth_PRIMITIVE << endl;
    cout << "crypto_auth_hmacsha512256_BYTES = " << fortium_defines::crypto_auth_hmacsha512256_BYTES << endl;
    cout << "crypto_auth_hmacsha512256_KEYBYTES = " << fortium_defines::crypto_auth_hmacsha512256_KEYBYTES << endl;
    cout << "crypto_auth_BYTES = " << fortium_defines::crypto_auth_BYTES << endl;
    cout << "crypto_auth_KEYBYTES = " << fortium_defines::crypto_auth_KEYBYTES << endl;
    return 0;
}