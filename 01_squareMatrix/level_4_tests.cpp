#define CATCH_CONFIG_MAIN  
// https://stackoverflow.com/questions/30407754/how-to-test-if-a-method-is-const
#include "catch_amalgamated.cpp"
#include "GradingHelpers.h"

TEST_CASE( "comparison operator", "[SquareMatrix]" ) {
    SquareMatrix<int> m;
    SquareMatrix<int> n;
    SECTION( "empty matrices are equal" ) {
        REQUIRE( (m == n) );
    }
    
    SetMatrix(m, 2, 3);
    SetMatrix(n, 2, 3);
    SECTION( "equal matrices are equal" ) {
        REQUIRE( (m == n) );
    }
    SetMatrix(n, 3, 3);
    SECTION( "equal matrices of different sizes are unequal" ) {
        REQUIRE_FALSE( (m == n));
    }
    SetMatrix(m, 3, 4);
    SECTION( "same size different values are unequal" ) {
        REQUIRE_FALSE( (m == n));
    }
}

TEST_CASE( "addition operator" , "[SquareMatrix]" ) {
  SECTION( "equal size addition correct" ) {
    SquareMatrix<int> m,n,o;
    SetMatrix(m, 6,1);
    SetMatrix(n, 6,2);
    SetMatrix(o, 6,3);
    REQUIRE_NOTHROW( m+n );
    auto sum = m+n;
    bool equal = sum == o;
    REQUIRE( equal );
  }
}
