#include "ValueLibrary/Value.h"

int main() {
    system("chcp 65001");

    Value a = "123123123{}123123123";
    std::cout << a.format({123123}) << std::endl;

    std::cout << a << std::endl;
    a = 1;
    std::cout << a << std::endl;

    a = {1,2,3};
    std::cout << a << std::endl;
    a.append("123123");
    a.append(123.123123);
    std::cout << a << std::endl;
    Value b = {a,11,23};
    std::cout << b << std::endl;

    Value c = DictValue();

    c.changeOrSetDefault("123",a);
    c.setDefault("123",a);


    c.changeOrSetDefault(1,a);
    std::cout << c << std::endl;

    a[0] = 123;
    std::cout << c << std::endl;

    /*
     *
     QVariant
     */

    return 0;
}

