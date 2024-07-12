/*1717. Maximum Score From Removing Substrings
Solved
Medium
Topics
Companies
Hint

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

    Remove substring "ab" and gain x points.
        For example, when removing "ab" from "cabxbae" it becomes "cxbae".
    Remove substring "ba" and gain y points.
        For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.



Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.

Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20



Constraints:

    1 <= s.length <= 105
    1 <= x, y <= 104
    s consists of lowercase English letters.

*/

int maximumGain(char *s, int x, int y)
{
    int len = strlen(s);
    int score = 0;
    char *stack = (char *)malloc(len + 1); // Stack to simulate string processing
    int top = -1;                          // Stack pointer

    // Choose the order based on points
    char first[3], second[3];
    int firstPoints, secondPoints;
    if (x > y)
    {
        strcpy(first, "ab");
        strcpy(second, "ba");
        firstPoints = x;
        secondPoints = y;
    }
    else
    {
        strcpy(first, "ba");
        strcpy(second, "ab");
        firstPoints = y;
        secondPoints = x;
    }

    // Process the string for the first substring
    for (int i = 0; i < len; ++i)
    {
        stack[++top] = s[i];
        if (top >= 1 && stack[top] == first[1] && stack[top - 1] == first[0])
        {
            top -= 2; // Remove the substring
            score += firstPoints;
        }
    }

    // Process the remaining stack for the second substring
    int newLen = top + 1;
    top = -1;
    for (int i = 0; i < newLen; ++i)
    {
        stack[++top] = stack[i];
        if (top >= 1 && stack[top] == second[1] && stack[top - 1] == second[0])
        {
            top -= 2; // Remove the substring
            score += secondPoints;
        }
    }

    free(stack);
    return score;
}