#include <iostream>

// Assuming UVM-like functionality is available in the C++ environment
void uvm_set_type_override(const std::string& original_type, const std::string& new_type) {
    // This is a placeholder for the real functionality
    std::cout << "Overriding " << original_type << " with " << new_type << std::endl;
}

int main() {
    uvm_set_type_override("wb_dma_transfer_seq", "wb_dma_infact_single_transfer_seq");
    uvm_set_type_override("wb_dma_config_seq", "wb_dma_infact_fields_config_seq");
    return 0;
}