/*
You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

Return the score of s.

 

Example 1:

Input: s = "hello"

Output: 13

Explanation:

The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

Example 2:

Input: s = "zaz"

Output: 50

Explanation:

The ASCII values of the characters in s are: 'z' = 122, 'a' = 97. So, the score of s would be |122 - 97| + |97 - 122| = 25 + 25 = 50.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scoreOfString(const char *s) {
    int score = 0;
    size_t length = strlen(s);
    for (size_t i = 0; i < length - 1; i++) {
        score += abs(s[i] - s[i + 1]);
    }
    return score;
}

int main() {
    const char *s = "example"; // Replace with your input string
    int score = scoreOfString(s);
    printf("Score of the string: %d\n", score);
    return 0;
}
