#define CATCH_CONFIG_MAIN  
// https://stackoverflow.com/questions/30407754/how-to-test-if-a-method-is-const
#include "catch_amalgamated.cpp"
#include "GradingHelpers.h"


TEST_CASE( "at() method", "[SquareMatrix]" ) {
    SquareMatrix<short> m;
    SetMatrix(m, 1, (short)0);
    const int test_val = 4;

    SECTION( "at read op throws when m is empty" ) {
        REQUIRE_THROWS_AS( m.at(5,5) , std::out_of_range );
    }

    SECTION( "at read and write correct" ) {
        m.resize(test_val);
        m.at(0,0) = test_val;
        REQUIRE( m.at(0,0) == test_val );
    }
}