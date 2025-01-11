
/**
 * 1400. Construct K Palindrome Strings
Solved
Medium
Topics
Companies
Hint

Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.

 

Constraints:

    1 <= s.length <= 105
    s consists of lowercase English letters.
    1 <= k <= 105


 */

class Solution {
public:
    bool canConstruct(string s, int k) {
        // If the string length equals the number of palindromes required,
        // it means each character can act as its own palindrome.
        if(s.size() == k) { 
            return true;
        }
        
        // If the string length is less than the number of palindromes required,
        // it's impossible to form `k` palindromes.
        if(s.size() < k) {  
            return false;
        }
        
        // Create a frequency array for all 26 lowercase letters.
        vector<int> freq(26, 0);
        int oddCount = 0; // Counts characters with odd frequencies.
        
        // Calculate the frequency of each character in the string.
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        // Count how many characters have odd frequencies.
        for(int count : freq) {
            if(count % 2 != 0) {
                oddCount++;
            }
        }

        // If the number of odd-frequency characters exceeds `k`,
        // it's impossible to form `k` palindromes.
        if(oddCount > k) {
            return false;
        }

        // Otherwise, it's possible to form `k` palindromes.
        return true;
    }
};
