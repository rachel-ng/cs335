CXXFLAGS = -std=c++11

main: main.o KeywordsInFile.o 
	g++ -o main main.o KeywordsInFile.o 

tests: tests.o KeywordsInFile.o
	g++ -std=c++11 -o tests tests.o KeywordsInFile.o 

main.o: main.cpp KeywordsInFile.h

$(OBJS).o: KeywordsInFile.cpp KeywordsInFile.h

tests.o: tests.cpp KeywordsInFile.h

clean:
	rm -f *.o main tests

