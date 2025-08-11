#include "../include/BigInt.hpp"
#include <iostream>
using namespace std;

int main() {
    // Test 1: Constructor with string
    BigInt first("12345");
    cout << "First BigInt: " << first << '\n';
    cout << "The number of digits in first big integer = " << Length(first) << '\n';

    // Test 2: Constructor with integer
    BigInt second(12345);
    cout << "Second BigInt: " << second << '\n';

    // Test 3: Equality operator
    if (first == second) {
        cout << "first and second are equal!\n";
    } else {
        cout << "first and second are not equal!\n";
    }

    // Test 4: Addition
    BigInt third = first + second;
    cout << "Sum of first and second: " << third << '\n';

    // Test 5: Multiplication
    BigInt fourth = first * second;
    cout << "Product of first and second: " << fourth << '\n';

    // Test 6: Increment operator
    ++first;
    cout << "First after increment: " << first << '\n';

    // Test 7: Decrement operator
    --second;
    cout << "Second after decrement: " << second << '\n';

    // Test 8: Factorial
    BigInt factorial;
    factorial = factorial.Factorial(5); // Call as a member function
    cout << "Factorial of 5: " << factorial << '\n';

    // Test 9: Fibonacci
    BigInt fibonacci;
    fibonacci = fibonacci.NthFibonacci(10); // Call as a member function
    cout << "10th Fibonacci number: " << fibonacci << '\n';

    // Test 10: Catalan number
    BigInt catalan;
    catalan = catalan.NthCatalan(5); // Call as a member function
    cout << "5th Catalan number: " << catalan << '\n';

    return 0;
}
