/**2116. Check if a Parentheses String Can Be Valid
Solved
Medium
Topics
Companies
Hint

A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

    It is ().
    It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
    It can be written as (A), where A is a valid parentheses string.

You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

    If locked[i] is '1', you cannot change s[i].
    But if locked[i] is '0', you can change s[i] to either '(' or ')'.

Return true if you can make s a valid parentheses string. Otherwise, return false.

 

Example 1:

Input: s = "))()))", locked = "010100"
Output: true
Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.

Example 2:

Input: s = "()()", locked = "0000"
Output: true
Explanation: We do not need to make any changes because s is already valid.

Example 3:

Input: s = ")", locked = "0"
Output: false
Explanation: locked permits us to change s[0]. 
Changing s[0] to either '(' or ')' will not make s valid.

 

Constraints:

    n == s.length == locked.length
    1 <= n <= 105
    s[i] is either '(' or ')'.
    locked[i] is either '0' or '1'.

 */




class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        // Step 1: Basic check - if length is odd, it cannot be a valid parentheses string.
        if (n % 2 != 0) {
            return false;
        }

        // Step 2: Use two stacks to manage open and wildcard positions.
        stack<int> open;       // Tracks indices of locked '('.
        stack<int> openClose;  // Tracks indices of unlocked '0'.

        // Step 3: Traverse the string.
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                // If the character is unlocked, treat it as a wildcard.
                openClose.push(i);
            } else if (s[i] == '(') {
                // If it's a locked '(', add its index to the open stack.
                open.push(i);
            } else if (s[i] == ')') {
                // For locked ')', try to balance it:
                if (!open.empty()) {
                    // Prefer balancing with a locked '(' if available.
                    open.pop();
                } else if (!openClose.empty()) {
                    // Otherwise, use a wildcard to balance.
                    openClose.pop();
                } else {
                    // If no matches are available, it's invalid.
                    return false;
                }
            }
        }

        // Step 4: Post-process to balance remaining locked '(' with wildcards.
        while (!open.empty() && !openClose.empty() && open.top() < openClose.top()) {
            // A wildcard can only balance a '(' if the wildcard appears after it.
            open.pop();
            openClose.pop();
        }

        // Step 5: If there are unmatched '(' left, it's invalid.
        if (!open.empty()) {
            return false;
        }

        // Step 6: If all conditions are satisfied, return true.
        return true;
    }
};
