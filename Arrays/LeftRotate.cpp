/*
    Rotate Array :
    Rotate the given array based on the k provide in the

*/

#include <bits/stdc++.h>
using namespace std;

void RotateArray(vector<int> &temp, int low, int high)
{
    while (low < high)
    {
        swap(temp[low], temp[high]);
        low++;
        high--;
    }
}

void solve(int arr[], int n, int k)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
        temp.push_back(arr[i]);

    RotateArray(temp, 0, (k - 1) % n);
    RotateArray(temp, (k - 1) % n, n - 1);
    RotateArray(temp, 0, n - 1);

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    solve(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}