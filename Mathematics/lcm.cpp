/*
 LCM OF TWO NUMBER
 */
#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b)
{
    int ans;
    ans = max(a, b);
    while (true)
    {
        if (ans % a == 0 && ans % b == 0)
        {
            return ans;
        }
        ans++;
    }
    return ans;
}

int main()
{
    cout << solve(1, 3);
    return 0;
}