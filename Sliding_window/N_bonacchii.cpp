/*
 Given the value of the n and m;
 find the m no of n-bonachhi number.
 eg:     N = 3, M = 8
 o/p --> 0 0 1 1 2 4 7 13
 */
#include <bits/stdc++.h>
using namespace std;
int v[1001];

void solve(int n, int m)
{
    for (int i = 0; i < n - 1; i++)
    {
        v[i] = 0;
    }
    v[n - 1] = 1;
    int sum_used = 1;
    for (int i = n; i < m; i++)
    {
        v[i] = sum_used;
        sum_used = sum_used - v[i - n];
        sum_used += v[i];
    }
    for (int i = 0; i < m; i++)
    {
        cout << v[i] << " ";
    }
}

// Function to print bonacci series
void bonacciseries(long n, int m)
{

    // Assuming m > n.
    int a[m] = {0};
    a[n - 1] = 1;
    a[n] = 1;

    // Uses sliding window
    for (int i = n + 1; i < m; i++)
        a[i] = 2 * a[i - 1] - a[i - n - 1];

    // Printing result
    for (int i = 0; i < m; i++)
        cout << a[i] << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    solve(n, m);
    cout << endl;
    bonacciseries(n, m);
    return 0;
}