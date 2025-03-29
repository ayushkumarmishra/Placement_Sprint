/*
Stock buy and sell problem :
 */

#include <bits/stdc++.h>
using namespace std;

// O(N^2) , O(1) ==> Naive Algorithm

int solve(int arr[], int start, int end)
{
    if (end <= start)
        return 0;
    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (arr[j] > arr[i])
            {
                int curr_profit = arr[j] - arr[i] + solve(arr, start, i - 1) + solve(arr, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

// Effcient Solution

int maxProfit(int arr[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += arr[i] - arr[i - 1];
        }
    }
    return profit;
}

int main()
{
    int arr[] = {1, 5, 3, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << solve(arr, 0, n) << endl;
    cout << maxProfit(arr, n) << endl;
    return 0;
}