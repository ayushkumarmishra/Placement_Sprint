/*
Problem Link : https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1#
 */
#include <bits/stdc++.h>
using namespace std;

/// To Traverse inside the graph
void dfs(int start, vector<pair<int, int>> g[], int &min_wt, int &end, int visited[])
{
    visited[start] = 1;
    for (auto i : g[start])
    {
        if (visited[i.first] == 0)
        {
            min_wt = min(min_wt, i.second);
            end = i.first;
            dfs(i.first, g, min_wt, end, visited);
        }
    }
}

// This is the main Function return the answer.

vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
{
    vector<vector<int>> res;
    vector<int> inp(n + 1, 0);
    vector<int> out(n + 1, 0);
    int visited[n + 1];
    memset(visited, 0, sizeof(visited));
    vector<pair<int, int>> grph[n + 1];

    for (int i = 0; i < p; i++)
    {
        out[a[i]] = 1;
        inp[b[i]] = 1;
        grph[a[i]].push_back({b[i], d[i]});
    }

    for (int i = 1; i <= n; i++)
    {
        if (inp[i] == 0 && out[i] == 1 && visited[i] == 0)
        {
            int s = i;
            int e;
            int min_wt = INT_MAX;
            dfs(i, grph, min_wt, e, visited);
            res.push_back({s, e, min_wt});
        }
    }
    return res;
}
