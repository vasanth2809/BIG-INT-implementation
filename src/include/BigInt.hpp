#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <vector>

class BigInt {
    std::string digits;

public:
    // Constructors
    BigInt(unsigned long long n = 0);
    BigInt(std::string &);
    BigInt(const char *);
    BigInt(const BigInt &);

    // Operators
    int operator[](const int) const;
    BigInt &operator=(const BigInt &);

    BigInt &operator++();
    BigInt operator++(int);
    BigInt &operator--();
    BigInt operator--(int);

    friend BigInt &operator+=(BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt &operator-=(BigInt &, const BigInt &);

    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);
    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);

    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt &operator/=(BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);

    friend BigInt operator%(const BigInt &, const BigInt &);
    friend BigInt &operator%=(BigInt &, const BigInt &);

    friend BigInt &operator^=(BigInt &, const BigInt &);
    friend BigInt operator^(BigInt &, const BigInt &);

    friend BigInt sqrt(BigInt &a);

    friend std::ostream &operator<<(std::ostream &, const BigInt &);
    friend std::istream &operator>>(std::istream &, BigInt &);

    friend BigInt NthCatalan(int n);
    friend BigInt NthFibonacci(int n);
    friend BigInt Factorial(int n);

    // Helper functions
    friend void divide_by_2(BigInt &a);
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);
};

#endif
