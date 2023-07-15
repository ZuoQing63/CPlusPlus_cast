#include <iostream>

int main() {
    int value = 10;
    int* intPtr = &value;

    // 指针类型转换
    char* charPtr = reinterpret_cast<char*>(intPtr);
    std::cout << "Char value: " << *charPtr << std::endl;

    // 引用类型转换
    double& doubleRef = reinterpret_cast<double&>(value);
    std::cout << "Double value: " << doubleRef << std::endl;

    // 将指针转换为整数类型
    uint64_t intValue = reinterpret_cast<uint64_t>(intPtr);
    std::cout << "Int value as uint64_t: " << intValue << std::endl;

    // 将整数类型转换为指针
    int* intPtr2 = reinterpret_cast<int*>(intValue);
    std::cout << "Value at intPtr2: " << *intPtr2 << std::endl;

    return 0;
}