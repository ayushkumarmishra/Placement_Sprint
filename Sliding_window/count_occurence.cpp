/*
 Count the number of occurences of the pattern in the string given.
 */
#include <bits/stdc++.h>
using namespace std;

int solve(string str, string ptr)
{
    int count = 0;
    int n = ptr.length();
    unordered_map<char, int> umap;
    for (int i = 0; i < n; i++)
    {
        umap[ptr[i]]++;
    }
    int count_of_char = umap.size();
    int i = 0, j = 0;
    int k = n;
    while (j < str.length())
    {
        if (umap.find(str[j]) != umap.end())
        {
            umap[str[j]]--;
            if (umap[str[j]] == 0)
            {
                count_of_char--;
            }
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count_of_char == 0)
                count++;
            if (umap.find(str[i]) != umap.end())
            {
                umap[str[i]]++;
                if (umap[str[i]] == 1)
                {
                    count_of_char++;
                }
            }
            i++;
            j++;
        }
    }
    return count;
}

int main()
{
    string str = "forxxorfxdofr";
    string ptr = "for";
    cout << solve(str, ptr);
    return 0;
}
