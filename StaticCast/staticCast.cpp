#include <iostream>

class Base {
public:
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived : public Base {
public:
    void foo() override {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    // 基本类型转换
    int num = 10;
    double pi = static_cast<double>(num);
    std::cout << "pi: " << pi << std::endl;

    // 指针转换
    Base* basePtr = new Derived();
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->foo();

    delete basePtr;
    return 0;
}