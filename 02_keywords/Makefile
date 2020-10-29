CXXFLAGS = -std=c++11

main: KeywordsInFile.o main.o
	g++ -o main KeywordsInFile.o main.o

KeywordsInFile.o: KeywordsInFile.cpp KeywordsInFile.h

main.o: main.cpp KeywordsInFile.h

clean:
	rm -f *.o main tests

