//  finding the index at which the number occured for the first time 

#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    if (*needle == '\0') {
        return 0; // If needle is empty, return 0
    }
    
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    for (int i = 0; i <= haystackLen - needleLen; i++) {
        int j;
        for (j = 0; j < needleLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needleLen) {
            return i; // Found needle at index i
        }
    }

    return -1; // Needle not found
}

int main() {
    char haystack[] = "hello";
    char needle[] = "ll";
    int result = strStr(haystack, needle);
    printf("Index of first occurrence: %d\n", result); // Output should be 2
    return 0;
}




// 


// second solution with 0ms time


int strStr(char* haystack, char* needle) {
    int needleLen = strlen(needle); // Get the length of the needle
    int haystackLen = strlen(haystack); // Get the length of the haystack

    // Iterate through the characters of the haystack
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        // Check if the substring of haystack starting at index i and of length needleLen is equal to the needle
        if (strncmp(&haystack[i], needle, needleLen) == 0) {
            return i; // If true, return the current index i
        }
    }

    return -1; // If no match is found, return -1
}