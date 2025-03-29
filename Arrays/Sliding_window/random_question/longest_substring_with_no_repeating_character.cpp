/*
Questions --> Given a string s, find the length of the longest substring without repeating characters.

Example:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include <bits/stdc++.h>
using namespace std;

int solve(string str)
{
    int n = str.length();
    int i = 0, j = 0;
    int maxi = -1;
    unordered_map<char, int> umap;
    umap.clear();
    while (j < n)
    {
        umap[str[j]]++;

        // if (umap.size() < k)
        //     j++;
        // if (umap.size() > j - i + 1) // This condition will never occur because character in the map cannot go beyond the size of the window at that particular time of window.
        // {
        //     j++;
        // }
        if (umap.size() < j - i + 1)
        {
            while (umap.size() < j - i + 1)
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
        else if (umap.size() == j - i + 1)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
    }
    return maxi;
}

int main()
{
    string str = "pwwkew";
    int k = 2;
    cout << solve(str) << endl;
}