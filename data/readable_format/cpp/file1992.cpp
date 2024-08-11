#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

int main() {
    std::string buf = "AbCdEf";
    int num = -2;
    std::ostringstream formattedNum;
    formattedNum << std::setw(3) << num;
    std::string numStr = formattedNum.str();
    buf.replace(1, 3, numStr);
    std::cout << "num = (" << buf << ")" << std::endl;
    return 0;
}