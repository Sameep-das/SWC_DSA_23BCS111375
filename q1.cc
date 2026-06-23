#include <bits/stdc++.h>
using namespace std;

// Function to calculate sum of divisors
int divisorsSum(int n)
{
    int sum = 0; // Initialize sum of prime factors

    // Note that this loop runs till square root of n
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, take only one
            // of them
            if (n / i == i)
            {
                sum = sum + i;
            }
            else // Otherwise take both
            {
                sum = sum + i;
                sum = sum + (n / i);
            }
        }
    }
    return sum;
}

// Function to check Deficient Number
bool isDeficient(int n)
{
    // Check if sum(n) < 2 * n
    return (divisorsSum(n) < (2 * n));
}

/* Driver program to test above function */
int main()
{
    isDeficient(12) ? cout << "YES\n" : cout << "NO\n";
    isDeficient(15) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}