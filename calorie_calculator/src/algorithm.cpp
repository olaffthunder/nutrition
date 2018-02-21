#include "calorie_calculator/inc/algorithm.h"

namespace calorie_calculator
{
    namespace basal_metabolic_estimation
    {
        //TODO add women too!
        //this is the original formular for men only
        calories::Calories harris_benedict_equation_original(const Kilogramm &weight, const int height, const age::Age &age)
        {
            return calories::Calories(66.5 + (13.75 * weight.weight()) + (5.003 * height) - (6.755 * (*age)));
        }

        calories::Calories harris_benedict_equation_revised(const Kilogramm &weight, const int height, const age::Age &age)
        {
            return calories::Calories(88.362 + (13.397 * weight.weight()) + (4.799 * height) - (5.677 * (*age)));
        }

        calories::Calories world_health_organization_equation(const Kilogramm &weight, const age::Age &age)
        {
            if (*age >= 3 && *age <= 9)
                return calories::Calories{ 22.7 * weight.weight() + 495 };
            if (*age >= 10 && *age <= 17)
                return calories::Calories{ 17.5 * weight.weight() + 651 };
            if (*age >= 18 && *age <= 29)
                return calories::Calories{ 15.3 * weight.weight() + 679 };
            if (*age >= 30 && *age <= 60)
                return calories::Calories{ 11.6 * weight.weight() + 879 };
            return calories::Calories{ 13.5 * weight.weight() + 487 };
        }

        calories::Calories mifflin_st_jeor_equation(const Kilogramm &weight, const int height, const age::Age &age)
        {
            return calories::Calories{ 10 * weight.weight() + 6.25 * height - 5 * (*age) + 5 };
        }

        calories::Calories katch_mc_ardle_formular(const Kilogramm &weight)
        {
            return calories::Calories(370 + (21.6 * weight.weight()));
        }
    }

    namespace body_fat_estimation
    {
        percentage::Percentage get_adult_body_fat_percentage_by_bmi(const Kilogramm &weight, const int height, const age::Age &age)
        {
            //TODO
            //int sex_factor = 0;
            //if (sex = male)
            //    sex_factor = 1;
            return percentage::Percentage((1.20 * weight.weight() / (height * height)) + (0.23 * (*age)) - (10.8 * 1.) - 5.4);
        }
    }
}