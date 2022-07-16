/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        // downwards
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i + 1, j, a, n, ans, move + 'D', vis);
            vis[i][j] = 0;
        }

        // left
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j - 1, a, n, ans, move + 'L', vis);
            vis[i][j] = 0;
        }

        // right
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j + 1, a, n, ans, move + 'R', vis);
            vis[i][j] = 0;
        }

        // upwards
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i - 1, j, a, n, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis);
        return ans;
    }
};

//////////////////////// Basic Implementation of Rat in the maze using BAcktracking. ////////////////////

// Safe Function
int n;
int maze[][], sol[][];

bool isSafe(int i, int j)
{
    return (i < n && j < n && maze[i][j] == 1);
}

bool solveMaze()
{
    if (solveMazeRect(0, 0) == false)
        return false;
    else
    {
        printMatrix(sol);
        return true;
    }
}

bool solveMazeRect(int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        sol[i][j] = 1;
        return true;
    }
    if (isSafe(i, j) == true)
    {
        sol[i][j] = 1;
        if (solveMazeRect(i + 1, j) == true)
            return true;
        else if (solveMazeRect(i, j + 1) == true)
            return true;
        sol[i][j] = 0;
    }
    return false;
}