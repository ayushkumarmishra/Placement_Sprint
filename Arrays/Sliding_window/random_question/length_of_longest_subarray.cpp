
// This is a variable sliding window problem

/*
 Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.
 */
#include <bits/stdc++.h>
using namespace std;

// This solution is only valid for positive integer so we cannot use it for 0 or negative numbers.

int solve(vector<int> arr, int n, int k)
{
    int i = 0, j = 0;
    int maxi = 1;
    int sum = 0;

    while (j < n)
    {
        sum += arr[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
        else if (sum == k)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
    }
    return maxi;
}

// For negative number we use the map approach

// int solve(vector<int> arr, int n, int k)
// {
//     int sum = 0, res = 0;
//     unordered_map<int, int> umap;
//     umap[0]++;

//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//         res += umap[sum - k];
//         umap[sum]++;
//     }
//     return res;
// }

int main()
{
    vector<int> arr = {4, 1, 1, 1, 2, 3, 5};
    int n = arr.size();
    cout << solve(arr, n, 5) << endl;

    return 0;
}