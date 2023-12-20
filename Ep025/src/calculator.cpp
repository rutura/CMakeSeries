#include "calculator.h"
#include <iostream>

int Calculator::add (int a, int b) {
    return a + b;
}

int Calculator::sub (int a, int b) {
    return a - b;
}

int Calculator::mul (int a, int b) {
    return a * b;
}

int Calculator::div (int a, int b) {
    return a / b;
}

int Calculator::mod (int a, int b) {
    return a % b;
}

void Calculator::print_description() {
    std::cout << "This is a simple calculator class that can add, subtract, multiply, divide, and mod two numbers." << std::endl;
}