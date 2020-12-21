CXXFLAGS = -std=c++17 -fsanitize=address 

main: AudioProcessor.o main.o
	g++ -std=c++17 -fsanitize=address -o main AudioProcessor.o main.o

test: AudioProcessor.o test.o
	g++ -std=c++17 -fsanitize=address -o test AudioProcessor.o test.o

tests: AudioProcessor.o tests.o
	g++ -std=c++17 -fsanitize=address -o tests AudioProcessor.o tests.o

AudioProcessor.o: AudioProcessor.cpp AudioProcessor.h

main.o: main.cpp AudioProcessor.h

test.o: test.cpp AudioProcessor.h

tests.o: tests.cpp AudioProcessor.h

clean:
	rm -f *.o main test tests

