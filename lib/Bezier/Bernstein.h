#include <Arduino.h>

#ifndef BERNSTEIN_H
#define BERNSTEIN_H

const int factorial(const int &n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

const int getBinomialCoefficient(const int &n, const int &k)
{
    if (k < 0 || k > n)
    {
        return 0; // "outside" Pascal's triangle
    }
    return factorial(n) / (factorial(k) * factorial(n - k));
}

struct Bernstein
{
    const float binomialCoefficient;
    const int n, k;

    Bernstein(
        const int &n,
        const int &k) : binomialCoefficient(getBinomialCoefficient(n, k)),
                        n(n),
                        k(k){};

    const float operator()(const float &t) const
    {
        return binomialCoefficient * pow(t, k) * pow(1 - t, n - k);
    }
};

#endif