/*in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 

Example 1:

Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.

 

Constraints:

    n == position.length
    2 <= n <= 105
    1 <= position[i] <= 109
    All integers in position are distinct.
    2 <= m <= position.length
*/




#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the maximum distance
int maxDistance(int* position, int positionSize, int m) {
    // Sort the positions array
    qsort(position, positionSize, sizeof(int), compare);

    int l = 1;
    int r = position[positionSize - 1] - position[0];
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int lastPosition = position[0];
        int balls = 1;

        for (int i = 1; i < positionSize; i++) {
            if (position[i] - lastPosition >= mid) {
                lastPosition = position[i];
                balls++;
            }
        }

        if (balls >= m) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    int position[] = {1, 2, 8, 4, 9}; // Example positions
    int m = 3; // Number of balls
    int positionSize = sizeof(position) / sizeof(position[0]);

    int result = maxDistance(position, positionSize, m);
    printf("Maximum distance is: %d\n", result);

    return 0;
}
