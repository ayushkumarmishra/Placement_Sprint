/*
Problem statement: *** Minimum Window Substring ***

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

Test case: 
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
    Note that the same letter must occur in the window in the same frequency as it does in t.

*** Intuitions and Approaches: ***

""" Naive approach """

1. Find all the subarrays first of string s.
2. Then store all the elements of t in a hash map. 
   eg: t = "ABC" => {A:1, B:1, C:1}
3. Start checking each of the generated subarrays to see if the element being checked is already in the hashmap or not.
4. If it contains all the elements of t, then check if the length of the subarray is less than the previous minimum length. If yes, update the minimum length and move to the other substrings.

Generating Substrings: 
- The algorithm generates all possible substrings from the input string. This involves nested loops, where the outer loop selects the starting index and the inner loop selects the ending index of the substring.

Frequency Map for Target String: 
- Before generating and checking substrings, a frequency map (hash map) is created for the target string t. This map stores each character in t as a key and its frequency as the value.

Validating Substrings: 
- For each generated substring, the algorithm iterates through the characters. It checks if each character exists in the frequency map created from string t. If a character is found in the map, its count is decremented. A separate counter keeps track of how many characters from t are found in the current substring.

Checking Validity: 
- A substring is considered valid if, after scanning, all characters of t are present in the substring with at least the required frequency. This is determined by checking if the count of found characters equals the length of t.

Minimum Length Tracking: 
- Throughout the process, the algorithm tracks the minimum length of valid substrings found so far. If a smaller valid substring is encountered, it updates the minimum length and the starting index of that substring.

Return Result: 
- After checking all substrings, the algorithm returns the minimum length substring found.

Test case: 
    Input: s = "ADOBECODEBANC", t = "ABC"

** Pseudo code: **

minLength = INT_MAX // Initialize the minimum length to a very large value
startIndex = -1;    // Initialize the starting index of the minimum substring
count = 0;          // Counter to track the number of valid characters found

for (i = 0 ==> n) {  // Outer loop to iterate through the starting index of substrings
    Hash[256] = {0}; // Initialize a hash map to store character frequencies

    for (j = i ==> m) { // Inner loop to iterate through the ending index of substrings
        Hash[t[j]]++;   // Increment the frequency of the current character in the hash map

        for (j = 0 ==> n) { // Iterate through the string s
            if (hash[s[j]] > 0) { // Check if the character exists in the hash map
                count++;          // Increment the count of valid characters
            }
            hash[s[j]]--;         // Decrement the frequency of the character in the hash map

            if (count == m) { // If all characters of t are found in the substring
                if ((j - i + 1) < minLength) { // Check if the current substring is smaller
                    minLength = j - i + 1;     // Update the minimum length
                    startIndex = i;           // Update the starting index
                }
                break; // Break out of the loop as we found a valid substring
            }
        }
    }
}
s.substr(startIndex, minLength); // Return the minimum substring

1. Method - 1: Sliding Window Approach
*/
