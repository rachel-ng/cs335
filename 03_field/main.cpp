#include <iostream>
#include <stdexcept>
#include <vector>
#include "Field.h"

int main() {
    std::vector<std::vector<int>> a; 
    std::vector<int> b;
    std::cout << "yoinks" <<std::endl;

    for (int c = 1; c < 7; c++) {
        b.push_back(c);
    }

    for (int r = 0; r < 5; r++) {
        a.push_back(b);
    }

    for (auto& y : a) {
        for (auto& x : y) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    
    Field f (a);

    std::cout << "\nnums" << std::endl;
    f.print();
    std::cout << "\nsums" << std::endl;
    f.print_sums();
    std::cout << "\ncost" << std::endl;
    f.print_cost();

    std::cout << "\n";
    std::cout << 42 << "\t" << f.Weight(1,2,4,0) << std::endl;
    std::cout << "\n";
    std::cout << 25 << "\t" << f.PathCost() << std::endl;


    std::vector<std::vector<int>> v1= {
        {1,3,5,7},
        {2,4,6,8},
        {3,5,7,9},
        {4,6,8,10},
    };

    Field f1 = v1;
    std::cout << 10 << "\t" << f1.Weight(0,0,0,3) << std::endl;
    
    Field f2({
        {1,3,5,7},
        {2,4,6,8},
        {3,5,7,9},
        {4,6,8,10},
    });
    std::cout << 10 << "\t" << f2.Weight(0,0,0,3) << std::endl;
}
