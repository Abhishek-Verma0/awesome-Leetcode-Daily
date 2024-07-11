/*1190. Reverse Substrings Between Each Pair of Parentheses
Solved
Medium
Topics
Companies
Hint

You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.



Example 1:

Input: s = "(abcd)"
Output: "dcba"

Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.



Constraints:

    1 <= s.length <= 2000
    s only contains lower case English characters and parentheses.
    It is guaranteed that all parentheses are balanced.

*/

char *reverseParentheses(char *s)
{
    int len = strlen(s);
    int *ind_stack = (int *)malloc(len * sizeof(int));
    int ind_top = -1;
    char *res = (char *)malloc((len + 1) * sizeof(char));
    int res_len = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            ind_stack[++ind_top] = res_len;
        }
        else if (s[i] == ')')
        {
            int start_ind = ind_stack[ind_top--];
            for (int j = start_ind, k = res_len - 1; j < k; j++, k--)
            {
                char temp = res[j];
                res[j] = res[k];
                res[k] = temp;
            }
        }
        else
        {
            res[res_len++] = s[i];
        }
    }

    res[res_len] = '\0';
    free(ind_stack);
    return res;
}