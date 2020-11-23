#include "Field.h"

Field::Field(const std::vector<std::vector<int>> & into){
    for (int r = 0; r < into.size(); r++) {
        std::vector<int> temp, temps, tempc;
        for (int c = 0; c < into[0].size(); c++) {
            temp.push_back(into[r][c]);
            if (c == 0) {
                if (r == 0) {
                    temps.push_back(into[r][c]);
                    tempc.push_back(into[r][c]);
                }
                else {
                    temps.push_back(_sums[r - 1][c] + into[r][c]);
                    tempc.push_back(_cost[r - 1][c] + into[r][c]);
                }
            }
            if (r == 0 and c != 0) {
                temps.push_back(temps[c - 1] + into[r][c]);
                tempc.push_back(tempc[c - 1] + into[r][c]);
            }
            if (c > 0 and r > 0) {
                temps.push_back(_sums[r - 1][c] + temps[c - 1] + into[r][c] - _sums[r - 1][c - 1]);
                tempc.push_back(std::min(_cost[r - 1][c],tempc[c - 1]) + into[r][c]);
            }
        }
        _nums.push_back(temp);
        _sums.push_back(temps);
        _cost.push_back(tempc);
    }
}

Field::Field(std::vector<std::vector<int>> && into): _nums(into) {
    for (int r = 0; r < into.size(); r++) {
        std::vector<int> temps, tempc;
        for (int c = 0; c < into[0].size(); c++) {
            if (c == 0) {
                if (r == 0) {
                    temps.push_back(into[r][c]);
                    tempc.push_back(into[r][c]);
                }
                else {
                    temps.push_back(_sums[r - 1][c] + into[r][c]);
                    tempc.push_back(_cost[r - 1][c] + into[r][c]);
                }
            }
            if (r == 0 and c != 0) {
                temps.push_back(temps[c - 1] + into[r][c]);
                tempc.push_back(tempc[c - 1] + into[r][c]);
            }
            if (c > 0 and r > 0) {
                temps.push_back(_sums[r - 1][c] + temps[c - 1] + into[r][c] - _sums[r - 1][c - 1]);
                tempc.push_back(std::min(_cost[r - 1][c],tempc[c - 1]) + into[r][c]);
            }
        }
        _sums.push_back(temps);
        _cost.push_back(tempc);
    }
}


int Field::Weight( int x1, int y1, int x2, int y2 ) {
    if ( y1 < 0 || y2 < 0 || x1 < 0 || x2 < 0) {
        throw std::out_of_range("invalid row and / or column");  
    }
    if (y1 > _nums.size() - 1 || y2 > _nums.size() - 1) {
        throw std::out_of_range("invalid row and / or column");  
    }
    if (x1 > _nums[0].size() - 1|| x2 > _nums[0].size() - 1) {
        throw std::out_of_range("invalid row and / or column");  
    }

    /*int mnx = x1 > x2 ? x2 : x1;
    int mny = y1 > y2 ? y2 : y1;
    int mxx = x1 < x2 ? x2 : x1;
    int mxy = y1 < y2 ? y2 : y1;*/

    int mny = std::min(y1,y2);
    int mnx = std::min(x1,x2);
    int mxy = std::max(y1,y2);
    int mxx = std::max(x1,x2);

    /*

    0 1 2
    3 4 5
    6 7 8 

    +   - 
       
    -   + 
    */

    int start = _sums[mxy][mxx]; // add 8
    start -= (mny - 1 >= 0) ? _sums[mny - 1][mxx] : 0; // subtract // 3 == 0
    start -= (mnx - 1 >= 0) ? _sums[mxy][mnx - 1] : 0; // subtract % 3 == 0
    start += (mny > 0 && mnx > 0) ? _sums[mny - 1][mnx - 1] : 0; // add 0
    return start;
}

int Field::PathCost() {
    if (_cost.size() < 1 || _cost[0].size() < 1) {
        throw(std::out_of_range("size 0 is invalid: there is no path cost"));
    }

    return _cost[_sums.size()-1][_sums[0].size()-1];
}

void Field::print () {
    for (auto& y : _nums) {
        for (auto& x : y) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

}

void Field::print_sums () {
    for (auto& y : _sums) {
        for (auto& x : y) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

}

void Field::print_cost () {
    for (auto& y : _cost) {
        for (auto& x : y) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

}

