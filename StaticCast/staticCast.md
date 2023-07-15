    static_cast: 用于执行基本类型之间的隐式转换，以及非多态类型之间的显式转换。它还可以用于向上转换和向下转换类层次结构中的指针或引用。
static_cast的常见用法包括：

* 在算术类型之间进行转换：例如，将int转换为double。
* 在指针之间进行转换：例如，将基类指针转换为派生类指针，或者将void*指针转换为具体类型指针。

下面是一个示例代码，展示了static_cast的用法：

```cpp
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
```
在上面的代码中，我们使用static_cast将int类型的变量转换为double类型，并将基类指针转换为派生类指针。

需要注意的是，static_cast并不提供运行时类型检查，因此如果执行了一个无效的转换，可能导致未定义行为。在进行指针转换时，建议使用dynamic_cast进行动态类型检查，以确保安全转换。