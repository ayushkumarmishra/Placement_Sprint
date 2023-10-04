/*
This is one of the important Problems of sliding window.
Question : Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".
 */
#include <bits/stdc++.h>
using namespace std;

int solve(string str, string ptr)
{
    int start = 0;
    // int end = INT_MAX;
    int ans = INT_MAX;
    int n = ptr.length();
    int i = 0, j = 0;

    unordered_map<char, int> umap;
    for (int i = 0; i < n; i++)
    {
        umap[ptr[i]]++;
    }
    int count = umap.size();

    while (j < str.length())
    {
        if (umap.find(str[j]) != umap.end())
        {
            umap[str[j]]--;
            if (umap[str[j]] == 0)
            {
                count--;
            }
        }

        if (count == 0)
        {
            while (count == 0)
            {
                // if (end - start > j - i)
                // {
                //     start = i;
                //     end = j;
                // }
                ans = min(ans, j - i + 1);
                if (umap.find(str[i]) != umap.end())
                {
                    umap[str[i]]++;
                    if (umap[str[i]] > 0)
                    {
                        count++;
                    }
                }
                i++;
            }
        }
        j++;
    }
    // return end == INT_MAX ? "No substring present" : str.substr(start, end - start + 1);
    return ans;
}

int main()
{
    string str = "ADOBECODEBANC";
    string ptr = "ABC";
    string ans = "";
    // ans = solve(str, ptr);
    cout << solve(str, ptr) << endl;
    // cout << ans << endl;
    return 0;
}