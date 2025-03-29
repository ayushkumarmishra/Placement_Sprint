/*
 Remove the duplicates from the sorted arrays.
 */
#include <bits/stdc++.h>
using namespace std;

// O(N) , O(N)
void solve(int arr[], int n)
{
    int temp[n + 1];
    int res = 1;
    temp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (temp[res - 1] != arr[i])
        {
            temp[res] = arr[i];
            res++;
        }
    }

    for (int i = 0; i < res; i++)
    {
        arr[i] = temp[i];
        // cout << arr[i] << endl;
    }
}

// O(N) , O(1)

void solve(int arr[], int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res - 1] != arr[i])
        {
            arr[res] = arr[i];
            res++;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    for (int i = 0; i < n - 1; i++)
        cout << arr[i] << endl;
    return 0;
}