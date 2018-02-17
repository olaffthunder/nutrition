#pragma once
#include "dependencies/strong_types/strong_types.h"
#include "dependencies/weigths/weigths.h"

namespace calorie_calculator
{
    using Calories = StrongType<int, struct CalorieParameters>;
    using Kilogramm = Weight::Unit<long double, std::kilo>;

    //TODO use dimensions for height
    Calories harris_benedict_equation(const Kilogramm &weight, int height, int age);
}