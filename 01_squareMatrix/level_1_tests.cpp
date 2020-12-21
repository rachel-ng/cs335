#define CATCH_CONFIG_MAIN  
// https://stackoverflow.com/questions/30407754/how-to-test-if-a-method-is-const
#include "catch_amalgamated.cpp"
#include "GradingHelpers.h"

TEST_CASE( "vectors can be initialized and resized", "[SquareMatrix]" ) {
    SquareMatrix<short> m;
    const int test_val = 4;
    SECTION( "size after init is zero" ) {
        REQUIRE( m.size() == 0 );
    }
    SECTION( "resizing changes size" ) {
        m.resize( test_val );
        REQUIRE( m.size() == test_val );
    }
}

TEST_CASE("Big Five copy", "[SquareMatrix]") {
  SECTION( "copy operators" ) {
    const int size = 5;
    SquareMatrix<double> cp_src;
    SetMatrix<double>(cp_src, size, 4.0);
    auto adr_of_src_elem = & cp_src.at(0,0);
    SquareMatrix<double> cp_ctord{cp_src};

    SECTION( "constructor equal" ) {
      REQUIRE( bool(cp_src == cp_ctord) );
    }
    SECTION( "values not moved" ) {
      auto adr_of_cp_elem = & cp_ctord.at(0,0);
      REQUIRE( cp_src.size() == size );
      REQUIRE_FALSE( adr_of_src_elem == adr_of_cp_elem );
    }

    SECTION( "assignment makes equal" ) {
      SetMatrix<double>(cp_src, 6, 5.0);
      auto cp_asgn = cp_src;
      REQUIRE( bool(cp_src == cp_asgn) );
    }
  }
}
