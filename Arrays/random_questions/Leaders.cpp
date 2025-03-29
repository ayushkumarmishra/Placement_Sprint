/*
    Q: Leaders In an Array : A leader is someone whose right side element are all smaller than it.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
    int curr_ldr = arr[n - 1];
    cout << curr_ldr << endl;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > curr_ldr)
        {
            cout << arr[i] << endl;
            curr_ldr = arr[i];
        }
    }
}

int main()
{
    int arr[] = {1, 3, 5, 2, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    return 0;
}