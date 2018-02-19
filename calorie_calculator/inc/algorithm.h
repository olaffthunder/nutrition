#pragma once
#include "dependencies/weights/weights.h"
#include "calorie_calculator/inc/calories.h"
#include "calorie_calculator/inc/percentages.h"

namespace calorie_calculator
{
    using Kilogramm = Weight::Unit<long double, std::kilo>;

    /*
    references:
    https://en.wikipedia.org/wiki/Basal_metabolic_rate
    https://en.wikipedia.org/wiki/Harris%E2%80%93Benedict_equation

    How TDEE can be calculated
    http://www.fao.org/docrep/007/y5686e/y5686e07.htm

    Examples for TDEE
    https://www.wellbeing.com.au/community/natural-health-glossary/Weight-loss-concepts-What-is-BMR-What-is-PAL-What-is-TDEE.html
    */

    namespace basal_metabolic_estimation
    {
        //TODO use dimensions for height
        calories::Calories harris_benedict_equation_original(const Kilogramm &weight, const int height, const int age);
        calories::Calories harris_benedict_equation_revised(const Kilogramm &weight, const int height, const int age);
        calories::Calories world_health_organization_equation(const Kilogramm &weight, const int age);
        calories::Calories mifflin_st_jeor_equation(const Kilogramm &weight, const int height, const int age);
        calories::Calories katch_mc_ardle_formular(const Kilogramm &weight);
    }

    namespace body_fat_estimation
    {
        //TODO add genders
        percentage::Percentage get_adult_body_fat_percentage_by_bmi(const Kilogramm &weight, const int height, const int age);
    }
}