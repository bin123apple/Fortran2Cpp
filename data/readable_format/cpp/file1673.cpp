#include <iostream>
#include <string>

// Simulated version of the GtkHlAccelerator class without GTK dependency
class GtkHlAccelerator {
public:
    // Simulated method that prints out what would happen
    static void hl_gtk_widget_add_accelerator(const std::string& widget, const std::string& signal, const std::string& accel_group, const std::string& accel_key, int accel_mods = 0, int accel_flags = 0) {
        std::cout << "Adding accelerator to widget: " << widget << std::endl;
        std::cout << "Signal: " << signal << ", Accel Group: " << accel_group << std::endl;
        std::cout << "Accel Key: " << accel_key << ", Mods: " << accel_mods << ", Flags: " << accel_flags << std::endl;
    }
};

int main() {
    // Simulate adding an accelerator with default modifiers and flags
    GtkHlAccelerator::hl_gtk_widget_add_accelerator("window", "activate", "accel_group", "F");

    // Simulate adding an accelerator with custom modifiers and flags
    GtkHlAccelerator::hl_gtk_widget_add_accelerator("window", "activate", "accel_group", "G", 1, 1);

    return 0;
}