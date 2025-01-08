/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

 

Constraints:

    bloomDay.length == n
    1 <= n <= 105
    1 <= bloomDay[i] <= 109
    1 <= m <= 106
    1 <= k <= n


*/






#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper function to check if it is possible to form m bouquets in given days
bool possible(int* bloomDay, int bloomDaySize, int day, int m, int k) {
    int count = 0;
    int numB = 0;

    for (int i = 0; i < bloomDaySize; i++) {
        if (bloomDay[i] <= day) {
            count++;
        } else {
            numB += (count / k);
            count = 0;
        }
    }
    numB += (count / k);
    return numB >= m; // Returning true if the number of bouquets is greater than or equal to m
}

// Function to find the minimum number of days required to make m bouquets of k flowers each
int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    // Check for integer overflow and insufficient number of flowers
    if (bloomDaySize < (long long)m * k) return -1;

    // Find the minimum and maximum days in the bloomDay array
    int low = bloomDay[0];
    int high = bloomDay[0];
    for (int i = 1; i < bloomDaySize; i++) {
        if (bloomDay[i] < low) {
            low = bloomDay[i];
        }
        if (bloomDay[i] > high) {
            high = bloomDay[i];
        }
    }

    // Binary search to find the minimum days required
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (possible(bloomDay, bloomDaySize, mid, m, k)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    int bloomDay[] = {1, 10, 3, 10, 2};
    int bloomDaySize = sizeof(bloomDay) / sizeof(bloomDay[0]);
    int m = 3;
    int k = 1;

    int result = minDays(bloomDay, bloomDaySize, m, k);
    if (result != -1) {
        printf("Minimum number of days required: %d\n", result);
    } else {
        printf("Not enough flowers to make %d bouquets of %d flowers each.\n", m, k);
    }

    return 0;
}
