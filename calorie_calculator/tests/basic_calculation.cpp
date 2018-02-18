#define CATCH_CONFIG_MAIN
#include "dependencies/catch/catch.hpp"
#include "dependencies/strong_types/strong_types.h"

#include "calorie_calculator/inc/algorithm.h"

TEST_CASE("BMR calculation")
{
    namespace cc = calorie_calculator;
    SECTION("harris_benedict_equation")
    {
        SECTION("all passed values 0")
        {
            cc::Kilogramm weight{ 0. };
            auto calories = cc::harris_benedict_equation(weight, 0, 0);
            REQUIRE(calories.get() == cc::Calories{ 66 }.get());
        }
        SECTION("weight == 1 - others 0")
        {
            cc::Kilogramm weight{ 1. };
            auto calories = cc::harris_benedict_equation(weight, 0, 0);
            INFO("Keep in mind: within the formular it's 66.5 + 13.75 which results in 80.25." 
                "Therefore it's 80 and not 79!");
            REQUIRE(calories.get() == cc::Calories{ 66.5 + 13.75 }.get());
        }
        SECTION("height == 1 - others 0")
        {
            cc::Kilogramm weight{ 0. };
            auto calories = cc::harris_benedict_equation(weight, 1, 0);
            REQUIRE(calories.get() == cc::Calories{ 66.5 + 5.003 }.get());
        }
        SECTION("age == 1 - others 0")
        {
            cc::Kilogramm weight{ 0. };
            auto calories = cc::harris_benedict_equation(weight, 0, 1);
            REQUIRE(calories.get() == cc::Calories{ 66.5 - 6.755 }.get());
        }
        SECTION("age && weigth == 1 - others 0")
        {
            cc::Kilogramm weight{ 1. };
            auto calories = cc::harris_benedict_equation(weight, 0, 1);
            REQUIRE(calories.get() == cc::Calories{ 66.5 + 13.75 - 6.755 }.get());
        }
        SECTION("age && weigth == 1 - others 0")
        {
            cc::Kilogramm weight{ 1. };
            auto calories = cc::harris_benedict_equation(weight, 1, 0);
            REQUIRE(calories.get() == cc::Calories{ 66.5 + 13.75 + 5.003 }.get());
        }\
        SECTION("all passed values == 1")
        {
            cc::Kilogramm weight{ 1. };
            auto calories = cc::harris_benedict_equation(weight, 1, 1);
            REQUIRE(calories.get() == cc::Calories{ 66.5 + 13.75 + 5.003 - 6.755 }.get());
        }
    }
}