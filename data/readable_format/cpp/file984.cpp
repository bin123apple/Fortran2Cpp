// Forward declaration of tens_signature_t to resolve circular dependency
class tens_signature_t;

class tens_signature_t {
public:
    ~tens_signature_t() {
        // Destructor body, if needed
    }
};

class tens_header_t {
public:
    tens_signature_t signature;

    ~tens_header_t() {
        // Destructor body, if needed
    }
};