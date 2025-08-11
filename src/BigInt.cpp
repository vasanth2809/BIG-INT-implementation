#include "BigInt.hpp"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <algorithm>

// ---------------- Constructors ----------------
BigInt::BigInt(unsigned long long n) {
    do {
        digits.push_back(n % 10 + '0');
        n /= 10;
    } while (n != 0);
}

BigInt::BigInt(std::string &s) {
    digits = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        if (!isdigit(s[i])) throw("ERROR");
        digits.push_back(s[i]);
    }
}

BigInt::BigInt(const char *s) {
    digits = "";
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (!isdigit(s[i])) throw("ERROR");
        digits.push_back(s[i]);
    }
}

BigInt::BigInt(const BigInt &a) {
    digits = a.digits;
}

// ---------------- Operators ----------------
int BigInt::operator[](const int index) const {
    if (index < 0 || index >= digits.size()) throw("ERROR");
    return digits[index] - '0';
}

BigInt &BigInt::operator=(const BigInt &a) {
    digits = a.digits;
    return *this;
}

// Increment / Decrement
BigInt &BigInt::operator++() {
    *this += 1;
    return *this;
}

BigInt BigInt::operator++(int) {
    BigInt temp = *this;
    *this += 1;
    return temp;
}

BigInt &BigInt::operator--() {
    *this -= 1;
    return *this;
}

BigInt BigInt::operator--(int) {
    BigInt temp = *this;
    *this -= 1;
    return temp;
}

// Arithmetic friend functions
BigInt &operator+=(BigInt &a, const BigInt &b) {
    int carry = 0;
    int i = 0;
    for (; i < a.digits.size() || i < b.digits.size() || carry; i++) {
        if (i == a.digits.size()) a.digits.push_back('0');
        int sum = (a.digits[i] - '0') + carry + (i < b.digits.size() ? (b.digits[i] - '0') : 0);
        carry = sum / 10;
        a.digits[i] = (sum % 10) + '0';
    }
    return a;
}

BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt temp = a;
    temp += b;
    return temp;
}

BigInt &operator-=(BigInt &a, const BigInt &b) {
    if (a < b) throw("Negative result not supported");
    int borrow = 0;
    for (size_t i = 0; i < a.digits.size(); i++) {
        int diff = (a.digits[i] - '0') - borrow - (i < b.digits.size() ? (b.digits[i] - '0') : 0);
        borrow = 0;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        a.digits[i] = diff + '0';
    }
    while (a.digits.size() > 1 && a.digits.back() == '0')
        a.digits.pop_back();
    return a;
}

BigInt operator-(const BigInt &a, const BigInt &b) {
    BigInt temp = a;
    temp -= b;
    return temp;
}

// Comparison operators
bool operator==(const BigInt &a, const BigInt &b) {
    return a.digits == b.digits;
}

bool operator!=(const BigInt &a, const BigInt &b) {
    return !(a == b);
}

bool operator<(const BigInt &a, const BigInt &b) {
    if (a.digits.size() != b.digits.size())
        return a.digits.size() < b.digits.size();
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        if (a.digits[i] != b.digits[i])
            return a.digits[i] < b.digits[i];
    }
    return false;
}

bool operator<=(const BigInt &a, const BigInt &b) {
    return (a < b) || (a == b);
}

bool operator>(const BigInt &a, const BigInt &b) {
    return !(a <= b);
}

bool operator>=(const BigInt &a, const BigInt &b) {
    return !(a < b);
}

// Multiplication
BigInt &operator*=(BigInt &a, const BigInt &b) {
    if (Null(a) || Null(b)) {
        a = BigInt();
        return a;
    }
    std::vector<int> res(a.digits.size() + b.digits.size(), 0);
    for (size_t i = 0; i < a.digits.size(); i++) {
        for (size_t j = 0; j < b.digits.size(); j++) {
            res[i + j] += (a.digits[i] - '0') * (b.digits[j] - '0');
            if (res[i + j] >= 10) {
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
    }
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
    a.digits.clear();
    for (int digit : res)
        a.digits.push_back(digit + '0');
    return a;
}

BigInt operator*(const BigInt &a, const BigInt &b) {
    BigInt temp = a;
    temp *= b;
    return temp;
}

// Division
BigInt &operator/=(BigInt &a, const BigInt &b) {
    if (Null(b)) throw("Division by zero");
    BigInt temp;
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        temp.digits.insert(temp.digits.begin(), a.digits[i]);
        while (temp.digits.size() > 1 && temp.digits.back() == '0')
            temp.digits.pop_back();
        int x = 0, l = 0, r = 10;
        while (l <= r) {
            int m = (l + r) >> 1;
            BigInt t = b * BigInt(m);
            if (t <= temp) {
                x = m;
                l = m + 1;
            } else r = m - 1;
        }
        a.digits[i] = x + '0';
        temp -= b * BigInt(x);
    }
    while (a.digits.size() > 1 && a.digits.back() == '0')
        a.digits.pop_back();
    return a;
}

BigInt operator/(const BigInt &a, const BigInt &b) {
    BigInt temp = a;
    temp /= b;
    return temp;
}

// Modulus
BigInt operator%(const BigInt &a, const BigInt &b) {
    BigInt temp = a;
    temp -= (a / b) * b;
    return temp;
}

BigInt &operator%=(BigInt &a, const BigInt &b) {
    a = a % b;
    return a;
}

// Exponentiation
BigInt &operator^=(BigInt &a, const BigInt &b) {
    BigInt exp = b, base = a, result = 1;
    while (!Null(exp)) {
        if (exp[0] % 2 != 0) result *= base;
        base *= base;
        divide_by_2(exp);
    }
    a = result;
    return a;
}

BigInt operator^(BigInt &a, const BigInt &b) {
    BigInt temp = a;
    temp ^= b;
    return temp;
}

// Square root
BigInt sqrt(BigInt &a) {
    BigInt l = 1, r = a, mid, ans;
    while (l <= r) {
        mid = (l + r) / 2;
        if (mid * mid <= a) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

// Input / Output
std::ostream &operator<<(std::ostream &out, const BigInt &a) {
    for (int i = a.digits.size() - 1; i >= 0; i--)
        out << a.digits[i];
    return out;
}

std::istream &operator>>(std::istream &in, BigInt &a) {
    std::string s;
    in >> s;
    a = BigInt(s);
    return in;
}

// Helpers
void divide_by_2(BigInt &a) {
    int carry = 0;
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        int cur = (a.digits[i] - '0') + carry * 10;
        a.digits[i] = cur / 2 + '0';
        carry = cur % 2;
    }
    while (a.digits.size() > 1 && a.digits.back() == '0')
        a.digits.pop_back();
}

bool Null(const BigInt &a) {
    return a.digits.size() == 1 && a.digits[0] == '0';
}

int Length(const BigInt &a) {
    return a.digits.size();
}
