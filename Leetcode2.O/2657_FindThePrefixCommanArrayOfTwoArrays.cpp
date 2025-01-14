/**
 * T.C -- O(N)
 * S.C -- O(N)
 * 
 * 
 * link to my leetcode solution --  ` https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/solutions/6279121/easy-c-beats-100-find-the-prefix-comman-l295d`
 */



class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // Step 1: Get the size of the input arrays as given  both are of same length 
        int n = A.size();
        
        // Step 2: Initialize the result vector that will store the prefix common counts
        vector<int> pre;

        // Step 3: Create a frequency vector to track how many times elements from A and B appear
        vector<int> freq(n + 1, 0); // size `n + 1` because array values are 1-based means array has entry from  1 to n 
        
        // Step 4: Initialize a counter to count the number of common elements seen so far
        int count = 0;

        // Step 5: Loop through the arrays to process each prefix
        for (int i = 0; i < n; i++) {
            // Increment the frequency of the element from array A
            // here we use the number as index to store their frequency because numbers are unique in both arrays
            freq[A[i]]++;
            
            // If this element appears twice, it means it's common between A and B
            if (freq[A[i]] == 2) {
                count++; // Increment the count of common elements
            }

            // Increment the frequency of the element from array B
            freq[B[i]]++;
            
            // If this element appears twice, it's also common between A and B
            if (freq[B[i]] == 2) {
                count++; // Increment the count of common elements
            }

            // Add the current count of common elements to the result vector
            pre.push_back(count);
        }

        // Return the prefix common array
        return pre;
    }
};



