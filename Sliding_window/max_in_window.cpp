/*
 Find the maximum value in a window of size k in the array of size n.
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int arr[], int k, int n)
{
    int i = 0, j = 0;
    list<int> ls;
    ls.push_back(arr[j]);
    vector<int> v;
    if (k > n)
    {
        int maxi = max(v.begin(), v.end());
        v.push_back(maxi);
        return v;
    }
    while (j < n)
    {
        while (ls.size() > 0 && ls.back() < arr[j])
        {
            ls.pop_back();
        }
        ls.push_back(arr[j]);
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            v.push_back(ls.front());
            if (ls.front() == arr[i])
            {
                ls.pop_front();
            }
            i++;
            j++;
        }
    }
    return v;
}

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 9;
    vector<int> v;
    v = solve(arr, k, n);
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}