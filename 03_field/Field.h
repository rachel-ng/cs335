#pragma once

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <algorithm>

class Field {
private:
    std::vector<std::vector<int>> _nums; 
    std::vector<std::vector<int>> _sums; 
    std::vector<std::vector<int>> _cost; 
public:
    Field( const std::vector<std::vector<int>> & into);
    Field( std::vector<std::vector<int>> && into);
    Field()=delete;
    int Weight( int x1, int y1, int x2, int y2 );
    int PathCost();
    void print();
    void print_sums();
    void print_cost();

};


