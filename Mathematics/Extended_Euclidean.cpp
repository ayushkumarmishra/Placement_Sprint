#include <iostream>
#include <utility>
using namespace std;

pair<int, int> solve(int a, int b)
{
    if (b == 0)
    {
        return {1, 0}; // Base case, gcd(a, 0) = a and x = 1, y = 0
    }
    pair<int, int> xy = solve(b, a % b);
    int x = xy.second;
    int y = xy.first - (a / b) * xy.second;
    return {x, y};
}

int main()
{
    int a, b;
    cin >> a >> b;
    pair<int, int> result = solve(a, b);
    cout << result.first << "," << result.second;
    return 0;
}
