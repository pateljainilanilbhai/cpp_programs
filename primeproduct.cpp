// C++ program to find numbers that are product
// of exactly two distinct prime numbers

#include <bits/stdc++.h>
using namespace std;

// Function to check whether a number
// is a PerfectSquare or not
bool isPerfectSquare(long double x)
{

    long double sr = sqrt(x);

    return ((sr - floor(sr)) == 0);
}

// Function to check if a number is a
// product of exactly two distinct primes
bool isProduct(int num)
{
    int cnt = 0;

    for (int i = 2; cnt < 2 && i * i <= num; ++i) {
        while (num % i == 0) {
            num /= i;
            ++cnt;
        }
    }

    if (num > 1)
        ++cnt;

    return cnt == 2;
}

// Function to find numbers that are product
// of exactly two distinct prime numbers.
void findNumbers(int N)
{
    // Vector to store such numbers
    vector<int> vec;

    for (int i = 1; i <= N; i++) {
        if (isProduct(i) && !isPerfectSquare(i)) {

            // insert in the vector
            vec.push_back(i);
        }
    }

    // Print all numers till n from the vector
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}

// Driver function
int main()
{
    int N = 400;

    findNumbers(N);

    return 0;
}
