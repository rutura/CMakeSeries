#include <iostream>
#include <vector>
#include "stats.h"
#include "supermath.h"
#include "information.h"

int main(int argc, char** argv){

   std::vector<int> v = {7, 5, 16, 9};

   int avg = mean(v.data(),v.size());
   std::cout << "mean : " << avg << std::endl;
   std::cout << "We are on " << Logging::getOsName() << std::endl;

    return 0;
}