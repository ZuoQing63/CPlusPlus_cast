#include <iostream>

class MyClass
{
public:
    void modifyData()
    {
        data = 20;
    }

    void printData() const
    {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data = 10;
};

int main()
{
    const MyClass obj;

    // 修改常量对象
    MyClass &nonConstObj = const_cast<MyClass &>(obj);
    nonConstObj.modifyData();
    nonConstObj.printData();

    // 解决重载冲突
    const int value = 10;
    const int &constRef = value;
    int &nonConstRef = const_cast<int &>(constRef);
    nonConstRef = 20;
    std::cout << "Modified value: " << value << std::endl;

    return 0;
}