#define CATCH_CONFIG_MAIN  
// https://stackoverflow.com/questions/30407754/how-to-test-if-a-method-is-const
#include "catch_amalgamated.cpp"
#include "GradingHelpers.h"


TEST_CASE("Big Five move", "[SquareMatrix]") {
  const int size = 5;
  const double test_val = 7.0;

  SECTION( "move assig clears size" ) {
    SquareMatrix<double> mv_src;
    SetMatrix<double>(mv_src, size, test_val);
    auto moved = std::move(mv_src);
    REQUIRE( mv_src.size() == 0 );
  }

  SECTION( "move assig moves values" ) {
    SquareMatrix<double> mv_src;
    SetMatrix<double>(mv_src, size, test_val);
    const auto adr_of_src_elem = & mv_src.at(0,0);
    auto moved = std::move(mv_src);
    const auto adr_of_moved_elem = & moved.at(0,0);
    REQUIRE_THROWS_AS( mv_src.at(0,0) , std::out_of_range );
    REQUIRE( adr_of_src_elem == adr_of_moved_elem );
  }

  SECTION( "a=b=move(c)" ) {
    SquareMatrix<double> a,b,c;
    SetMatrix<double>(c, size, test_val);
    a = b = std::move(c);
    REQUIRE_NOTHROW( a.at(1,1)=5 );
    REQUIRE_NOTHROW( (a.at(4,4) == b.at(4,4)) );
  }
}

TEST_CASE("Big Five special", "[SquareMatrix]") {
  SECTION( "special operators" ) {
    const double test_val = 50.0;
    SECTION( "a=a" ) {
      SquareMatrix<double> a;
      SetMatrix<double>(a, 5, test_val);
      a = a;
      REQUIRE_NOTHROW( a.at(1,1) == test_val);
    }

    SECTION( "a=b=c" ) {
      SquareMatrix<double> a,b,c;
      SetMatrix<double>(c, 5, test_val);
      a = b = c;
      REQUIRE_NOTHROW( a.at(1,1) = test_val );
    }
  }
}
