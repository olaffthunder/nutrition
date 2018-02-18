#include "calorie_calculator/inc/algorithm.h"

namespace calorie_calculator
{
    Calories harris_benedict_equation(const Kilogramm &weight, int height, int age)
    {
        return Calories(66.5 + (13.75 * weight.weight()) + (5.003 * height) - (6.755 * age));
    }
}