#include <iostream>
#include <string>
#include <vector>
#include <omp.h>

int main(int argc, char** argv)
{
    std::vector<int> input, output;
    int inLen = 1000, outLen = 1;

    if(argc == 1) 
    {
        std::cout << "No command line arguments provided.
";
        return 1;
    }

    try 
    {
        inLen = std::stoi(argv[1]);
    }
    catch(std::invalid_argument const &e)
    {
        std::cout << "Error, invalid integer value.
";
        return 1;
    }

    input.resize(inLen);
    output.resize(inLen);

    for(int i = 0; i < inLen; i++)
    {
        input[i] = i;
    }

    #pragma omp parallel for
    for(int i = 0; i < inLen; i++)
    {
        output[outLen] = input[i];
        outLen++;
    }

    std::cout << "output[0]=" << output[0] << "
";

    return 0;
}
