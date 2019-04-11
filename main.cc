#include <iostream>
#include "backtrack.hh"

int main(){
    NameGenerator x;
    std::cout << x.generateName(4) << std::endl;
    x.printAllDislikedName();
    return 0;
}