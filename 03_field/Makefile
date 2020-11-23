CXXFLAGS = -std=c++11 -fsanitize=address 

main: Field.o main.o
	g++ -std=c++11 -fsanitize=address -o main Field.o main.o

Field.o: Field.cpp Field.h

main.o: main.cpp Field.h

clean:
	rm -f *.o main tests

