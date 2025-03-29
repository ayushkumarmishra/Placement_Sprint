/*
 This is a variable sliding window problem
Longest K unique characters substring
 */
#include <bits/stdc++.h>
using namespace std;

int solve(string str, int k)
{
    int n = str.length();
    int i = 0, j = 0;
    int maxi = -1;
    unordered_map<char, int> umap;
    umap.clear();
    while (j < n)
    {
        umap[str[j]]++;

        if (umap.size() < k)
            j++;
        if (umap.size() > k)
        {
            while (umap.size() > k)
            {
                umap[str[i]]--;
                if (umap[str[i]] == 0)
                {
                    umap.erase(str[i]);
                }
                i++;
            }
            j++;
        }
        else if (umap.size() == k)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
    }
    return maxi;
}

int main()
{
    string str = "aaaa";
    int k = 2;
    cout << solve(str, k) << endl;

    return 0;
}
