#include <iostream>
template<typename DATA_TYPE>
void print_array(int n, DATA_TYPE a[]) {
 for(int i = 0; i < n; i++) {
 std::cout << a[i] << " ";
 if (i % 20 == 19)
 std::cout << std::endl;
 }
 std::cout << std::endl;
}
