#include "Feet.hpp"

#include <limits>
#include <cmath>


Feet::Feet(double value) : value(value) {}

Feet::Feet(const Feet& feet) = default;

double Feet::getValue() const{
    return value;
}

Feet Feet::operator+(const Feet& feet) const {
    return Feet{value + feet.value};
}

Feet Feet::operator-(const Feet& feet) const {
    return Feet{value - feet.value};
}

Feet Feet::operator*(const Feet& feet) const {
    return Feet{value * feet.value};
}

Feet Feet::operator/(const Feet& feet) const {
    return Feet{value / feet.value};
}

Feet Feet::operator+=(const Feet& feet){
    value += feet.value;
    return *this;
}

Feet Feet::operator-=(const Feet& feet){
    value -= feet.value;
    return *this;
}

Feet Feet::operator*=(const Feet& feet){
    value *= feet.value;
    return *this;
}

Feet Feet::operator/=(const Feet& feet){
    value /= feet.value;
    return *this;
}

Feet Feet::operator++(){
    value++;
    return *this;
}

Feet Feet::operator++(int){
    Feet temp = *this;
    value++;
    return temp;
}

Feet Feet::operator--(){
    value--;
    return *this;
}

Feet Feet::operator--(int){
    Feet temp = *this;
    value--;
    return temp;
}

Feet Feet::operator-() const {
    return Feet{-value};
}

bool Feet::operator==(const Feet& feet) const {
    return value == feet.value;
}

std::partial_ordering Feet::operator<=>(const Feet& feet) const {
    return value <=> feet.value;
}


std::ostream& operator<<(std::ostream& os, const Feet& feet) {
    if(feet.value == 0) os << "0 feet";
    else{
        int wholeFeet = static_cast<int>(feet.value);
        double remainingValue = feet.value - wholeFeet;

        if(wholeFeet != 0) os << wholeFeet << " ft";

        int wholeInches = static_cast<int>(remainingValue * 12);
        double fractionInches = remainingValue * 12 - wholeInches;

        if(wholeInches != 0 || wholeFeet != 0) os << ' ' << wholeInches;

        int denominator = 1;
        double closestFraction = 0.0;
        double minDifference = std::numeric_limits<double>::infinity();

        for(int power = 0; power <= 5; ++power){
            int currentDenominator = std::pow(2, power);
            double frac = std::round(fractionInches * currentDenominator) / currentDenominator;
            double difference = std::abs(fractionInches - frac);

            if(difference < minDifference){
                minDifference = difference;
                closestFraction = frac;
                denominator = currentDenominator;
            }
        }

        // Print the fraction in the form of numerator/denominator
        if(closestFraction != 0.0)
            os << ' ' << static_cast<int>(closestFraction * denominator) << '/' << denominator << " in";
        else if(wholeInches != 0)
            os << " in";
    }

    return os;
}

Feet operator"" _ft(long double value){
    return Feet{static_cast<double>(value)};
}

Feet operator"" _ft(unsigned long long value){
    return Feet{static_cast<double>(value)};
}

Feet operator"" _in(long double value){
    return Feet{static_cast<double>(value / 12.)};
}

Feet operator"" _in(unsigned long long value){
    return Feet{static_cast<double>(value / 12.)};
}