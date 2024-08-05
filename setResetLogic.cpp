#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <bitset>

uint32_t setBit(uint32_t Data, uint8_t bitNumber)
{
    Data |= 1 << bitNumber;
    return Data;
}

uint32_t resetBit(uint32_t Data, uint8_t bitNumber)
{
    Data &= ~(1<<bitNumber);
    std::cout << "bitCompliment: " << std::bitset<8>(~(1<<bitNumber))  << std::endl;
    return Data;
}

uint32_t toggleBit(uint32_t Data, uint8_t bitNumber)
{
    Data ^= 1 << bitNumber;
    return Data;
}


int main()
{
    uint32_t input = 0x7;
    uint32_t output1 = setBit(input, 3);
    std::cout << "Input: " << std::bitset<8>(input) << std::endl;
    std::cout << "outputSet: " << std::bitset<8>(output1)  << std::endl;
    uint32_t output2 = resetBit(input, 0);
    std::cout << "outputReset: " << std::bitset<8>(output2)  << std::endl;
    uint32_t output3 = toggleBit(input, 7);
    std::cout << "outputToggleBit7: " << std::bitset<8>(output3)  << std::endl;
    output3 = toggleBit(output3, 7);
    std::cout << "outputToggleBit7: " << std::bitset<8>(output3)  << std::endl;
}