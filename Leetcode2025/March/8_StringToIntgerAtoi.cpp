/**
 * T.C --> O(n)
 * S.C --> O(1) -- as no extra space used only constant space used 
 */



class Solution {
public:
    int myAtoi(string s) {
        int n = 1;         // sign decider based  '-' or  '+'
        long long num = 0; // using long long to detect overflow of int
        int i = 0;
        int len = s.size();  // size of the string 

        // 1. Skip leading spaces as spaces are only allowed in beg not at in btw
        while (i < len && s[i] == ' ') {
            i++;
        }

        // 2. Check sign whether it is positve or negative
        if (i < len && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-')
                n = -1;
            i++;
        }

        // 3. Parse only digits not the char or space which come in btw if do so then break 
        while (i < len && isdigit(s[i])) {
            int val = s[i] - '0';
            num = num * 10 + val;

            // 4. Handle overflow — must clamp to INT_MAX/INT_MIN
            if (num * n > INT_MAX){
                return INT_MAX;
            }
            if (num * n < INT_MIN)
            {
                return INT_MIN;
            }

            i++;
        }
        // 5. Final result
        return (int)(num * n);
    }
};
