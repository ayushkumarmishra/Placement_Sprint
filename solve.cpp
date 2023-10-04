#include <bits/stdc++.h>
using namespace std;

int solve(int min, int max)
{
    int count = 0;
    int ans = 0;
    for (int i = min; i <= max; i++)
    {
        while (i != 0)
        {
            i = i / 10;
            ++count;
        }
        ans += count;
        count = 0;
    }
    return ans;
}

int main()
{
    cout << solve(12, 15) << endl;
    // solve(8, 12);
    return 0;
}
