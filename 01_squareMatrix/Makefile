CXXFLAGS = -std=c++17

test1: level_1_tests.o
	g++ -o test1 level_1_tests.o

test2: level_2_tests.o
	g++ -o test2 level_2_tests.o

test3: level_3_tests.o
	g++ -o test3 level_3_tests.o

test4: level_4_tests.o
	g++ -o test4 level_4_tests.o

level_1_tests.o: level_1_tests.cpp catch_amalgamated.cpp GradingHelpers.h
level_2_tests.o: level_2_tests.cpp catch_amalgamated.cpp GradingHelpers.h
level_3_tests.o: level_3_tests.cpp catch_amalgamated.cpp GradingHelpers.h
level_4_tests.o: level_4_tests.cpp catch_amalgamated.cpp GradingHelpers.h
