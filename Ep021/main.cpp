#include <iostream>

#include "calculator.h"

int main () {
    Calculator calc;
    std::cout << "add(10,4): " << calc.add(10,4) << std::endl;
    std::cout << "sub(10,4): " << calc.sub(10,4) << std::endl;
    std::cout << "mul(10,4): " << calc.mul(10,4) << std::endl;
    std::cout << "div(10,4): " << calc.div(10,4) << std::endl;
    std::cout << "mod(10,4): " << calc.mod(10,4) << std::endl;
    return 0;
}