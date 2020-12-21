#include "AudioProcessor.h"
#include <stdexcept>
#include <vector> 


std::string print (std::vector<short> vec) {
    std::string s;
    for (const auto & n : vec) {
        s += std::to_string(n) + ", ";
    }

    return s + "\n";
}


int main () {
    AudioProcessor  processor;

    std::vector<short> A{ 1, 4, 25, 15, 0, -7, -40, 10 };
    std::vector<short> correctA{ 1, 4, 20, 13, 0, -7, -30, 10 };

    std::vector<short> outA;
    outA = processor.Compress(A, 10, 1.5 );

    std::cout << print(A) << std::endl;
    std::cout << print(correctA) << std::endl;

    std::cout << "\n" << std::endl;

    for (int i = 0; i < outA.size(); i++) {
        if (correctA[i] == outA[i]) {
            std::cout << "correct " << i << std::endl;
        }
        else {
            std::cout << "ERROR incorrect " << i << std::endl;
        }
    }

    std::cout << "\n" << std::endl;

    std::cout << print(outA) << std::endl;


    std::cout << "\n\n" << std::endl;
    std::cout << "\n\n" << std::endl;


    std::vector<short> B{1, -3, 10, 25, 56, -1, -2, -16, -20, -8, -1, 1, 7, 12};
    std::vector<short> correctB{25, 56, -1, -2, -16, -20, 12};

    std::vector<short> outB;
    outB = processor.CutOutSilence(B, 10, 3); 


    std::cout << print(B) << std::endl;
    std::cout << print(correctB) << std::endl;
    std::cout << print(outB) << std::endl;

    std::cout << "\n" << std::endl;

    for (int i = 0; i < outB.size(); i++) {
        if (correctB[i] == outB[i]) {
            std::cout << "correct " << i << std::endl;
        }
        else {
            std::cout << "ERROR incorrect " << i << std::endl;
        }
    }

    std::cout << "\n" << std::endl;

    std::cout << print(outB) << std::endl;


    std::cout << "\n\n" << std::endl;
    std::cout << "\n\n" << std::endl;


    std::vector<short> C{1, 4, 23, -2, -28, 10 };
    std::vector<short> correctC{1, 3, 4, 14, 23, 11, -2, -15, -28, -9, 10};

    std::vector<short> outC;
    outC = processor.StretchTwice(C); 


    std::cout << print(C) << std::endl;
    std::cout << print(correctC) << std::endl;
    std::cout << print(outC) << std::endl;

    std::cout << "\n" << std::endl;

    for (int i = 0; i < outC.size(); i++) {
        if (correctC[i] == outC[i]) {
            std::cout << "correct " << i << std::endl;
        }
        else {
            std::cout << "ERROR incorrect " << i << std::endl;
        }
    }

    std::cout << "\n" << std::endl;

    std::cout << print(outC) << std::endl;


    std::cout << "\n\n" << std::endl;
    std::cout << "\n\n" << std::endl;


    std::vector<short> D{1, 3, -2, 5, -4, 0};
    std::vector<short> correctD{2, 6, -4, 10, -8, 0};

    std::vector<short> outD;
    outD = processor.Normalize(D,10); 


    std::cout << "original\t" << print(D) << std::endl;
    std::cout << "correct\t" << print(correctD) << std::endl;
    std::cout << "processed\t"<< print(outD) << std::endl;

    std::cout << "\n" << std::endl;

    for (int i = 0; i < outD.size(); i++) {
        if (correctD[i] == outD[i]) {
            std::cout << "correct " << i << std::endl;
        }
        else {
            std::cout << "ERROR incorrect " << i << std::endl;
        }
    }

    std::cout << "\n" << std::endl;

    std::cout << print(outD) << std::endl;


    std::cout << "\n\n" << std::endl;
    std::cout << "\n\n" << std::endl;


    std::vector<short> E {-1, -30, 3, 15, 16, -7};
    std::vector<short> correctE {-1, -20, 2, 10, 11, -5};

    std::vector<short> outE;
    outE = processor.Normalize(E,20); 


    std::cout << "original\t" << print(E) << std::endl;
    std::cout << "correct\t" << print(correctE) << std::endl;
    std::cout << "processed\t" << print(outE) << std::endl;

    std::cout << "\n" << std::endl;

    for (int i = 0; i < outE.size(); i++) {
        if (correctE[i] == outE[i]) {
            std::cout << "correct " << i << std::endl;
        }
        else {
            std::cout << "ERROR incorrect " << i << std::endl;
        }
    }

    std::cout << "\n" << std::endl;

    std::cout << print(outE) << std::endl;


    std::vector<short> F{1};
    std::vector<short> correctF{1};

    std::vector<short> outF;
    outF = processor.StretchTwice(F); 


    std::cout << print(F) << std::endl;
    std::cout << print(correctF) << std::endl;
    std::cout << print(outF) << std::endl;




}


