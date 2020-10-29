#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include "KeywordsInFile.h"

int main() {

    KeywordsInFile f ("keys.txt","text.txt");

    std::cout << f << std::endl;

    try {
        std::cout << "found moonlight? " << (f.KeywordFound("moonlight") ? "yes." : "no.") << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << "moonlight is not a keyword" << std::endl;
    }
    try {
        std::cout << "total occurrences? " << f.TotalOccurrences("moonlight") << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << "moonlight is not a keyword" << std::endl;
    }
    try {
        std::cout << "moonlight in line 10? " << f.KeywordInLine("moonlight",10) << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << "moonlight is not a keyword" << std::endl;
    }


    std::cout << std::endl;

    std::cout << "found sunshine? " << (f.KeywordFound("sunshine") ? "yes." : "no.") << std::endl;
    try {
        std::cout << "sunshine in line -10? " << f.KeywordInLine("sunshine",-10) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "line out of range" << std::endl;
    }
    try {
        std::cout << "sunshine in line 0? " << f.KeywordInLine("sunshine",0) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "line out of range" << std::endl;
    }
    std::cout << "sunshine in line 1? " << f.KeywordInLine("sunshine",1) << std::endl;
    std::cout << "sunshine in line 6? " << f.KeywordInLine("sunshine",4) << std::endl;
    std::cout << "sunshine in line 6? " << f.KeywordInLine("sunshine",6) << std::endl;
    std::cout << "total occurrences? " << f.TotalOccurrences("sunshine") << std::endl;


}

