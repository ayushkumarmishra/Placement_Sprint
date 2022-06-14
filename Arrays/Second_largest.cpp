#include <bits/stdc++.h>
using namespace std;

/*
arr : 1, 2, 4, 6, 5, 6, 8;
arr : 4, 4, ,4 , 4
*/

int secondLargest(int arr[], int n)
{
    int largest = 0, res = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (res == -1 && arr[i] > arr[largest])
            {
                res = i;
            }
        }
    }
    return res;
}

int main()
{
    int arr[] = {6, 6, 7, 6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = secondLargest(arr, n);
    (ans == -1) ? printf("No Second Largest Possible") : printf("%d", arr[ans]);

    return 0;
}