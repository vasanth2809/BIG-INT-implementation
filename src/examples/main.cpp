#include "../include/BigInt.hpp"
#include <iostream>
using namespace std;

int main() {
    BigInt first("12345");
    cout << "The number of digits in first big integer = "
         << Length(first) << '\n';

    BigInt second(12345);
    if (first == second) {
        cout << "first and second are equal!\n";
    } else {
        cout << "Not equal!\n";
    }
    return 0;
}
