CXXFLAGS = -std=c++11

main: main.o SquareMatrix.o
	g++ -o main main.o 

tests: tests.o SquareMatrix.o
	g++ -o tests tests.o

main.o: main.cpp SquareMatrix.h SquareMatrix.hxx

SquareMatrix.o: SquareMatrix.hxx SquareMatrix.h

tests.o: tests.cpp SquareMatrix.h

clean:
	rm *.o main tests 

