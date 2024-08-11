#include <cfloat> // For LDBL_DIG

namespace aot_extdouble_top {

    // C++ doesn't directly allow specifying the precision like Fortran,
    // so we use `long double` as an approximation. This may not give
    // exactly 18 decimal digits of precision, depending on the implementation.
    using xdble_k = long double;

    // Alternatively, if you want to explicitly check the precision:
    // This constant is just an example. You should define what makes
    // sense for your application, possibly based on `LDBL_DIG` or other
    // properties of `long double`.
    constexpr int precision = LDBL_DIG; // This gives the number of decimal
                                         // digits of precision for `long double`.

    // You might use `static_assert` to enforce a minimum precision, if desired.
    // Example: Require at least 18 digits of precision, though note that
    // this might fail on some implementations.
    // static_assert(precision >= 18, "Precision of `long double` is less than 18 decimal digits.");
}

int main() {
    // Example usage
    aot_extdouble_top::xdble_k myVar = 0.0L; // Using `long double`
    
    // If you need to check precision
    int myPrecision = aot_extdouble_top::precision;
    
    return 0;
}