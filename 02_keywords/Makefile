CXXFLAGS = -std=c++11 -fsanitize=address 

main: KeywordsInFile.o main.o
	g++ -std=c++11 -fsanitize=address -o main KeywordsInFile.o main.o

KeywordsInFile.o: KeywordsInFile.cpp KeywordsInFile.h

main.o: main.cpp KeywordsInFile.h

clean:
	rm -f *.o main tests

