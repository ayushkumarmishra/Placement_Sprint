/*
 GCD of Two NUmber
 ..
 if (a > b)
 GCD(a, b ) === gcd(a-b, b)
 */

#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    else if (a > b)
        return solve(a - b, b);
    return solve(a, b - a);
}

int solve(int a, int b)
{
    if (b == 0)
        return a;
    return solve(b, a % b);
}

int main()
{
    cout << solve(12, 16);
    return 0;
}