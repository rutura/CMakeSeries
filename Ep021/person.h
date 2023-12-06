#include <string>

class Person {
 private:
  std::string name;
  int age;

 public:
  // Constructor
  Person(const std::string& name, int age);

  // Getter for name
  std::string getName() const;

  // Setter for name
  void setName(const std::string& newName);

  // Getter for age
  int getAge() const;

  // Setter for age
  void setAge(int newAge);
};
