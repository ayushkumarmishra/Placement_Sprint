/*
 Count the first negative in every window of size 'k'.
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int arr[], int n, int k)
{
    int i = 0, j = 0;
    vector<int> ans;
    list<int> l;

    while (j < n)
    {
        if (arr[j] < 0)
        {
            l.push_back(arr[j]);
        }

        if (j - i + 1 < k)
        {
            j++;
            continue;
        }
        else if (j - i + 1 == k)
        {
            if (l.size() == 0)
            {
                ans.push_back(0);
                i++;
                j++;
            }
            else
            {
                ans.push_back(l.front());
                if (arr[i] == l.front())
                    l.pop_front();
                i++;
                j++;
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {12, -1, -7, -8, -15, 30, 10, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    ans = solve(arr, n, 3);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
