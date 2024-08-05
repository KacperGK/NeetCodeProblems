// Do a byte swap current -> CC8700FC expected -> 0xFC0087CC |CC|87|00|FC|.  FC -> FC|00 -> FC|00|87 -> FC|00|87|CC
// 1. Extract byte, shift towards left and then add new extracted byte

#include <iostream>
#include <cstdint>
#include <stdint.h>


uint32_t byteSwap(uint32_t input)
{
    uint32_t byte0 = (input & 0x000000FF) << 24;
    uint32_t byte1 = (input & 0x0000FF00) << 8;
    uint32_t byte2 = (input & 0x00FF0000) >> 8;
    uint32_t byte3 = (input & 0xFF000000) >> 24;

    return (byte0 | byte1 | byte2 | byte3);
}


int main()
{
    uint32_t currentData = 0x00CC8700FC;
    uint32_t targetData = 0xFC0087CC;

    uint32_t resultSwap = byteSwap(currentData);

    std::cout << "currentData: " << std::hex << currentData << std::endl;
    std::cout << "targerTada: " << std::hex << targetData << std::endl;
    std::cout << "resultSwap: " << std::hex << resultSwap << std::endl;

        if(resultSwap == targetData)
    {
        std::cout << "GREJT SUKSES";
    } else {
            std::cout <<"COS nie pyklo miszczu";
    }

    return 0;
}