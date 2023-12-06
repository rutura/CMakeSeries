#include <iostream>
#include "person.h"

int main() {
  Person p("John", 42);
  std::cout << p.getName() << " is " << p.getAge() << " years old."
            << std::endl;
  p.setName("Jane");
  p.setAge(43);
  std::cout << p.getName() << " is " << p.getAge() << " years old."
            << std::endl;
  return 0;
}