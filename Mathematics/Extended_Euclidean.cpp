/*
Extended Euclidean is used to calculate the valus of the x and y which comes by the formula :
 ===> ax + by = gcd(a, b)
 ===> x = y1;
 ===> y = x1 - (a / b) * y1;

 */
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

// pair<int, int> solve(int a, int b)
// {
//     if (b == 0)
//     {
//         return {1, 1};
//     }
//     auto [x1, y1] = solve(b, a % b);
//     int x = y1;
//     int y = x1 - (a / b) * y1;
//     return {x, y};
// }

int main()
{
    int a, b;
    cin >> a >> b;
    // auto [x, y] = solve(a, b);
    // cout << x << "," << y;
    return 0;
}
