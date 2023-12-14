#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "Feet.hpp"


TEST_CASE("Feet", "[Feet]"){
    Feet feet = 49.75_in;
    Feet feet2 = 2_ft + 12_in + 1.14583333333333333333333333333333333333_ft;
    std::cout << feet << std::endl;
    std::cout << feet2 << std::endl;

    std::cout << std::boolalpha;
    std::cout << (feet == feet2) << std::endl;
    std::cout << (feet != feet2) << std::endl;
    std::cout << (feet < feet2) << std::endl;
    std::cout << (feet <= feet2) << std::endl;
    std::cout << (feet > feet2) << std::endl;
    std::cout << (feet >= feet2) << std::endl;

    REQUIRE(feet == feet2);

    Feet five = 5_ft;
    Feet five2 = 60_in;

    REQUIRE(five == five2);
    REQUIRE(five <= five2);
    REQUIRE(five >= five2);
    REQUIRE(five < five2 + 1_in);
    REQUIRE(five > five2 - 1_in);

    Feet three = 3_ft;
    Feet three2 = 36_in;

    REQUIRE(three + 2_ft == three2 + 24_in);
    REQUIRE(three - 2_ft == three2 - 24_in);
    REQUIRE(three * 2 == three2 * 2);
    REQUIRE(three / 2 == three2 / 2);

}
