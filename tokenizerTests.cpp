#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include "tokenMaker.cpp"

using namespace std;

TEST_CASE("tokenMaker Tests"){

    SUBCASE("Unique ID for each word"){

    int a = token_from_string("space");
    int b = token_from_string("spade");
    int c = token_from_string("space");

    CHECK(a != b);
    CHECK(b != c);
    CHECK(a == c);
    cout << a << " " << endl;
    cout << b << " " << endl;
    }

    SUBCASE("Value Check"){
    int a = token_from_string("space");
    int b = token_from_string("spade");
    CHECK(a == 1053714310);
    CHECK(b == -1722020655);
    }
}