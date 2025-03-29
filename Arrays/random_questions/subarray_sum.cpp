/*
    Maximum Sum Subarray
 */
#include <bits/stdc++.h>
using namespace std;

void solve_naive(int arr[], int n)
{
    int maxmm = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            maxmm = max(curr, maxmm);
        }
    }
    cout << maxmm;
}

void solve_optmize(int arr[], int n)
{
    int maxmm = arr[0];
    int max_ending = arr[0];
    for (int i = 0; i < n; i++)
    {
        max_ending = max(arr[i], arr[i] + max_ending);
        maxmm = max(maxmm, max_ending);
    }
    cout << maxmm;
}

int main()
{
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "**** This is the output of Naive_code ****" << endl;
    solve_naive(arr, n);
    cout << endl
         << "**** This is the output of optimize_code ****" << endl;
    solve_optmize(arr, n);
    return 0;
}