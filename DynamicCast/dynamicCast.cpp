#include <iostream>

class Base
{
public:
    virtual void foo()
    {
        std::cout << "Base::foo()" << std::endl;
    }
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void foo() override
    {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main()
{
    Base *basePtr = new Derived();

    // 向上转换
    Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);
    if (derivedPtr != nullptr)
    {
        derivedPtr->foo();
    }
    else
    {
        std::cout << "Failed to perform dynamic_cast(UP)" << std::endl;
    }

    // 向下转换
    Base *anotherBasePtr = new Base();
    Derived *anotherDerivedPtr = dynamic_cast<Derived *>(anotherBasePtr);
    if (anotherDerivedPtr != nullptr)
    {
        anotherDerivedPtr->foo();
    }
    else
    {
        std::cout << "Failed to perform dynamic_cast(DOWN)" << std::endl;
    }

    delete basePtr;
    delete anotherBasePtr;
    return 0;
}