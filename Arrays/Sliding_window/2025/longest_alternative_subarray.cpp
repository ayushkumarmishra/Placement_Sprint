/*
Problem statement: *** Longest Alternating Subarray ***

You are given a 0-indexed integer array nums. A subarray s of length m is called alternating if:

▶️ m is greater than 1.
▶️ s1 = s0 + 1.
▶️ The 0-indexed subarray s looks like [s0, s1, s0, s1,...,s(m-1) % 2]. In other words, s1 - s0 = 1, s2 - s1 = -1, s3 - s2 = 1, s4 - s3 = -1, and so on up to s[m - 1] - s[m - 2] = (-1)m.
Return the maximum length of all alternating subarrays present in nums or -1 if no such subarray exists.

Test case:
Input: nums = [2,3,4,3,4]
Output: 4

Explanation:
The alternating subarrays are [2, 3], [3,4], [3,4,3], and [3,4,3,4]. The longest of these is [3,4,3,4], which is of length 4.

*** Intuitions and Approaches: ***
Naive Approach : 
- Time complexity: O(n^2)
- Space complexity: O(1)


class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(); // Size of the input vector
        int maxi = -1; // Initialize the maximum length of an alternating subarray as -1
        
        for(int i = 0; i < n-1; i++) { // Outer loop for starting index of subarray
            bool ch = false; // Flag to track increasing or decreasing order
            
            for(int j = i + 1; j < n; j++) { // Inner loop for ending index of subarray
                if(!ch) { // Subarray is in increasing order
                    if(nums[j] - nums[j-1] == 1) { // Check for alternating pattern
                        ch = true; // Set flag to true
                        maxi = max(maxi, j - i + 1); // Update maximum length if necessary
                    } else {
                        break; // Break the inner loop if alternating pattern is not valid
                    }
                } else { // Subarray is in decreasing order
                    if(nums[j] - nums[j-1] == -1) { // Check for alternating pattern
                        ch = false; // Set flag to false
                        maxi = max(maxi, j - i + 1); // Update maximum length if necessary
                    } else {
                        break; // Break the inner loop if alternating pattern is not valid
                    }
                }
            }
        }
        
        return maxi; // Return the maximum length of an alternating subarray
    }
};

    """ Optimized approach """ ===> O(N) time complexity and O(1) space complexity

    there are three things that we need to think of :
    1. there is n incresing trend and then decresing trend on alternating indexes, so the falsg i used to handle that trend.
    2. the first if loop is uesed to check the increasing trend and the else part indside it mentions that the the difference is not what we looking for that is why we are moving left pointer to right pointer.
    3. the second if loop is used to check the decreasing trend and inside that we have three checks : 
        1. if the difference is -1 then we are moving the left pointer to right pointer and updating the maxmLength.
        2. if the difference is 1 then we are moving the left pointer to right pointer - 1 i.e moving the left pointer 1 element before where the trend was broken.
        3. if the difference is not what we are looking for then we are moving the left pointer to right pointer and updating the flag to false.

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 1;
        int maxmLength = -1;
        bool flag = false;

        if (n == 1) {
            return maxmLength;
        }

        while (right < n) {
            if (!flag) {
                if (nums[right] - nums[right - 1] == 1) {
                    maxmLength = max(maxmLength, right - left + 1);
                    flag = true;
                } else {
                    left = right;
                }
            } else {
                if (nums[right] - nums[right - 1] == -1) {
                    maxmLength = max(maxmLength, right - left + 1);
                    flag = false;
                } else if (nums[right] - nums[right - 1] == 1) {
                    left = right - 1;
                    maxmLength = max(maxmLength, right - left + 1);
                } else {
                    flag = false;
                    left = right;
                }
            }
            right++;
        }
        return maxmLength;
    }
};






*/