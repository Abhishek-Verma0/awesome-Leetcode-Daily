/*
Conversion of given roman number to integer means we get a roman number from user as input and we need to find the integer of that
roman .
*/



#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    int m[256] = {0};
    
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    int ans = 0;
    int len = strlen(s);
    
    for(int i = 0; i < len; i++) {
        if (i + 1 < len && m[(int)s[i]] < m[(int)s[i+1]]) {
            ans -= m[(int)s[i]];
        } else {
            ans += m[(int)s[i]];
        }
    }
    return ans;
}

int main() {
    char s[] = "MCMXCIV";
    int result = romanToInt(s);
    printf("The integer value of %s is: %d\n", s, result);
    return 0;
}

