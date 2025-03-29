/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 */

#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution : TC : O(N^2) , SC : O(1)  This will give the time limit exceeded error.

int solve(int height[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int lMax = height[i];
        for (int j = 0; j < i; j++)
        {
            lMax = max(lMax, height[j]);
        }

        int rMax = height[i];
        for (int j = i + 1; j < n; j++)
            rMax = max(height[j], rMax);

        res += (min(rMax, lMax) - height[i]);
    }
    return res;
}

/* ********************************************************************************************** */

// Optimize Solution : TC : O(N) , SC : O(N) {The Pre-Processing Approach}

int solve(int height[], int n)
{
    int leftMax[n], rightMax[n];
    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
        leftMax[i] = max(height[i], leftMax[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(height[i], rightMax[i + 1]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        res += min(leftMax[i], rightMax[i]) - height[i];
    }
    return res;
}

/* ********************************************************************************************** */

// Most Optimize Solution : TC : O(N) , SC : O(1) { The Two Pointer Approach}

int solve(int height[], int n)
{

    int leftPtr = 0, rightPtr = n - 1;
    int leftMax = 0, rightMax = 0;
    int res = 0;

    while (leftPtr <= rightPtr)
    {
        if (height[leftPtr] <= height[rightPtr])
        {
            if (height[leftPtr] >= leftMax)
                leftMax = height[leftPtr];
            else
                res += leftMax - height[leftPtr];
            leftPtr++;
        }
        else
        {
            if (height[rightPtr] >= rightMax)
                rightMax = height[rightPtr];
            else
                res += rightMax - height[rightPtr];
            rightPtr--;
        }
    }

    return res;
}

int main()
{
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(height[0]);
    cout << solve(height, n) << endl;
    return 0;
}