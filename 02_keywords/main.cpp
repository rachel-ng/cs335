#include <iostream>
#include "KeywordsInFile.cpp"

using namespace std;

int main(){
    KeywordsInFile a("test.txt", "texts.txt");
    cout << a;
}

