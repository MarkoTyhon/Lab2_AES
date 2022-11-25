#include <iostream>
#include <bitset>
#include <climits>

int main()
{
    union
    {
        float input; // assumes sizeof(float) == sizeof(int)
        int   output;
    } data;

    data.input = 1.0;

    std::bitset<sizeof(float)* CHAR_BIT> bits(data.output);
    std::cout << bits << std::endl;

    // or
    std::cout << "BIT 4: " << bits[4] << std::endl;
    std::cout << "BIT 7: " << bits[7] << std::endl;
}