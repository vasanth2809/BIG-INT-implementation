#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class BigInt {
    string digits;

public:
    // Constructors
    BigInt(unsigned long long n = 0);
    BigInt(string &);
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

    friend ostream &operator<<(ostream &, const BigInt &);
    friend istream &operator>>(istream &, BigInt &);

    // Helper functions
    friend void divide_by_2(BigInt &a);
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);

    // Factorial, Fibonacci, and Catalan numbers
    BigInt Factorial(int n);
    BigInt NthFibonacci(int n);
    BigInt NthCatalan(int n);
};

#endif
