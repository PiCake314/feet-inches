#pragma once

#include <iostream>
#include <compare>


class Feet{
    double value;

public:

    Feet(double value);

    Feet(const Feet& feet);

    double getValue() const;

    Feet operator+(const Feet& feet) const;

    Feet operator-(const Feet& feet) const;

    Feet operator*(const Feet& feet) const;

    Feet operator/(const Feet& feet) const;

    Feet operator+=(const Feet& feet);

    Feet operator-=(const Feet& feet);

    Feet operator*=(const Feet& feet);

    Feet operator/=(const Feet& feet);

    Feet operator++();

    Feet operator++(int);

    Feet operator--();

    Feet operator--(int);

    Feet operator-() const;

    bool operator==(const Feet& feet) const;

    std::partial_ordering operator<=>(const Feet& feet) const;

    friend std::ostream& operator<<(std::ostream& os, const Feet& feet);

};


Feet operator"" _ft(long double value);
Feet operator"" _ft(unsigned long long value);

Feet operator"" _in(long double value);
Feet operator"" _in(unsigned long long value);

