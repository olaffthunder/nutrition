#pragma once
#include "dependencies/strong_types/strong_types.h"

namespace calorie_calculator
{
    namespace age
    {
        //TODO: think of a better solution
        struct Age : StrongType<int, struct AgeParameters>
        {
            constexpr explicit Age(const int value) :
                StrongType<int, struct AgeParameters>(value) {}
            constexpr explicit Age(const double value) :
                StrongType<int, struct AgeParameters>(static_cast<int>(value)) {}
            constexpr explicit Age(const long double value) :
                StrongType<int, struct AgeParameters>(static_cast<int>(value)) {}
            constexpr explicit Age(const unsigned long long value) :
                StrongType<int, struct AgeParameters>(static_cast<int>(value)) {}

            //bool operator < (const Age &rhs)
            //{
            //    return get() < rhs.get();
            //}
            //bool operator > (const Age &rhs)
            //{
            //    return rhs < *this;
            //}
            //bool operator <= (const Age &rhs)
            //{
            //    return !(*this > rhs);
            //}
            //bool operator >= (const Age &rhs)
            //{
            //    return !(*this < rhs);
            //}

            //friend bool operator < (const Age &lhs, const Age &rhs)
            //{
            //    return lhs.get() < rhs.get();
            //}
            //friend bool operator > (const Age &lhs, const Age &rhs)
            //{
            //    return rhs < lhs;
            //}
            //friend bool operator <= (const Age &lhs, const Age &rhs)
            //{
            //    return !(lhs > rhs);
            //}
            //friend bool operator >= (const Age &lhs, const Age &rhs)
            //{
            //    return !(lhs < rhs);
            //}

            //friend Age operator * (const Age &lhs, const Age &rhs)
            //{
            //    return Age{ lhs.get() * rhs.get() };
            //}

            //friend double operator * (const Age &lhs, const double &rhs)
            //{
            //    return lhs.get() * rhs ;
            //}
            //
            //friend double operator * (const double &lhs, const Age &rhs)
            //{
            //    return rhs * lhs;
            //}
        };

        namespace literals
        {
            // Literal operators, always one for integers and one
            // for floating-point values.
            constexpr Age operator""_a(const unsigned long long age)
            {
                return Age(age);
            }

            //TODO is this really necessary?
            constexpr Age operator""_a(const long double age)
            {
                return Age(age);
            }
        }
    }
}