#include <iostream>
#include <type_traits>
#include <cstdint>
#include <vector>
#include <algorithm>

template <typename T>
T veryNiceByteSwap(T input){
    static_assert(std::is_integral<T>::value,"Input must be an int type");

    T result = 0;
    constexpr size_t byteCount = sizeof(T);

    for(size_t i = 0 ;i < byteCount; i++){
        uint8_t byte = (input >> (8 * i)) & 0xFF;
        result |= static_cast<T>(byte) << (8 * (byteCount - 1 - i));
    }

    return result;

}

template<typename T>
void byteSwapVector(std::vector<T>& vec){
    static_assert(std::is_integral<T>::value, "Element type must be an integral type.");
    for(auto& element : vec){
        element = veryNiceByteSwap(element);
    }
}



int main() {
    std::vector<uint32_t> data = {0x12345678, 0xAABBCCDD, 0x11223344, 0x11223344, 0x55667788, 0x91929394};
    std::vector<uint32_t> targetData = {0x78563412, 0xDDCCBBAA, 0x44332211, 0x44332211, 0x88776655, 0x94939291};

    byteSwapVector(data);

    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << "data[" << i << "]: 0x" << std::hex << data[i] << std::endl;
    }

        bool success = true;

    for(size_t i = 0; i < data.size(); i++){
        if(data[i] != targetData[i]){
            success = false;
            break;
        }
    }



    if (success) {
        std::cout << "GREJT SUKSES" << std::endl;
    } else {
        std::cout << "COS nie pyklo miszczu" << std::endl;
    }



    std::reverse(data.begin(),data.end());

     for (size_t i = 0; i < data.size(); ++i) {
        std::cout << "data reverse[" << i << "]: 0x" << std::hex << data[i] << std::endl;
    }
    return 0;
}

