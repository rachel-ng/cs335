CXXFLAGS = -std=c++11

main: main.o SquareMatrix.o
	g++ -o main main.o 

tests: tests.o SquareMatrix.o
	g++ -o tests tests.o

test: test.o 
	g++ -std=c++11 -Wall -g -fsanitize=address test.cpp -o test

main.o: main.cpp SquareMatrix.h 

SquareMatrix.o: SquareMatrix.h

tests.o: tests.cpp SquareMatrix.h

test.o: test.cpp SquareMatrix.h

clean:
	rm *.o main tests test 

