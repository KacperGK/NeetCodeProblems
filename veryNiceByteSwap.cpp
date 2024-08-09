#include <iostream>
#include <type_traits>
#include <cstdint>

template <typename T>
T veryNiceByteSwap(T input){
    static_assert(std::is_integral<T>::value,"Input must be an int type");

    T result = 0;
    constexpr size_t byteCount = sizeof(T);
    
/*
Działanie pętli
i = 0: byte = 0x78, shift = 24 → result = 0x78000000
i = 1: byte = 0x56, shift = 16 → result = 0x78560000
i = 2: byte = 0x34, shift = 8 → result = 0x78563400
i = 3: byte = 0x12, shift = 0 → result = 0x78563412
*/ 
    for(size_t i = 0; i < byteCount; i++){
        uint8_t byte = (input >> (8 * i)) & 0xFF;
        result |= byte << (8 * (byteCount - 1 - i));
    }
    return result;
}

int main(){
    uint32_t currentData = 0x12345678;
    uint32_t targetData = 0x78563412;

    uint16_t resultSwap = veryNiceByteSwap(currentData);

    std::cout << "currentData: 0x" << std::hex << currentData << std::endl;
    std::cout << "targetData: 0x" << std::hex << targetData << std::endl;
    std::cout << "resultSwap: 0x" << std::hex << resultSwap << std::endl;

    if (resultSwap == targetData) {
        std::cout << "GREJT SUKSES" << std::endl;
    } else {
        std::cout << "COS nie pyklo miszczu" << std::endl;
    }

    return 0;
}



