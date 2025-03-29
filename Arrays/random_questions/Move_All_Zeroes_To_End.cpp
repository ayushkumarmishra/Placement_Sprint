#include <bits/stdc++.h>
using namespace std;

/*
eg: arr[] = {8, 5, 0, 10, 0, 30}
o/p : arr[] = {8, 5, 10, 30, 0, 0}
*/

void moveToEnd(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[count], arr[i]);
            count++;
        }
    }
}

int main()
{
    int arr[] = {8, 5, 0, 10, 0, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    moveToEnd(arr, n);

    for (int i : arr)
        cout << i << " ";

    return 0;
}