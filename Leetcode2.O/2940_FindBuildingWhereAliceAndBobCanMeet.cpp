/**2940. Find Building Where Alice and Bob Can Meet
Solved
Hard
Topics
Companies
Hint

You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.

If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.

Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

 

Example 1:

Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
Output: [2,5,-1,5,2]
Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2]. 
In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5]. 
In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
In the fifth query, Alice and Bob are already in the same building.  
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

Example 2:

Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
Output: [7,6,-1,4,6]
Explanation: In the first query, Alice can directly move to Bob's building since heights[0] < heights[7].
In the second query, Alice and Bob can move to building 6 since heights[3] < heights[6] and heights[5] < heights[6].
In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
In the fourth query, Alice and Bob can move to building 4 since heights[3] < heights[4] and heights[0] < heights[4].
In the fifth query, Alice can directly move to Bob's building since heights[1] < heights[6].
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

 

Constraints:

    1 <= heights.length <= 5 * 104
    1 <= heights[i] <= 109
    1 <= queries.length <= 5 * 104
    queries[i] = [ai, bi]
    0 <= ai, bi <= heights.length - 1

 */





class Solution {
public:
    int findClosestTallerBuilding(vector<int> &heights, vector<int> &nextTallerBuilding, vector<int> &rightSortedLimit, int height, int startIndex) {
        int numBuildings = heights.size();

        // If we have reached the end of the buildings or we have reached a building that doesn't have a taller building in front of it, return -1
        if (startIndex >= numBuildings || startIndex == -1) return -1;
        
        // If the height of current building is already greater than the required height, return current building's index
        if (heights[startIndex] > height) return startIndex;

        // If the height of current building shorter or equal to required height, and it doesn't have any taller building in front of it, return -1
        if (nextTallerBuilding[startIndex] == -1) return -1;

        // If the entire sorted subarray from the current building has a shorter height than the required height,
        // jump directly to the next taller building after the last building in the subarray.
        if (heights[rightSortedLimit[startIndex]] <= height) return findClosestTallerBuilding(heights, nextTallerBuilding, rightSortedLimit, height, nextTallerBuilding[rightSortedLimit[startIndex]]);

        // Otherwise, the required building is within the sorted subarray.
        int left = startIndex, right = rightSortedLimit[startIndex];
        int closestTallerBuildingIndex = heights[nextTallerBuilding[startIndex]];

        // Apply binary search within the bounds of these sorted buildings
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (heights[mid] <= height) {
                // If we found the shorter building and there is no other building taller and closer than this, then update the index, and let's keep looking farther
                closestTallerBuildingIndex = max(closestTallerBuildingIndex, mid);
                left = mid + 1;
            }
            else {
                // If we found the taller building, then update the index, and let's keep looking closer
                closestTallerBuildingIndex = mid;
                right = mid - 1;
            }
        }
        // We've reached a building that is either slightly shorter or taller than the required height. 
        // Let's verify the height by recursively checking with the updated index.
        return findClosestTallerBuilding(heights, nextTallerBuilding, rightSortedLimit, height, closestTallerBuildingIndex);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int numBuildings = heights.size(), numQueries = queries.size();

        // A vector where each element at index i stores the index of the nearest taller building to the right of building i.
        // If no such building exists, it is set to -1.
        // It is initialized to -1 for each index, indicating that initially, there is no taller building to the right, and this will be updated as we loop through the buildings
        vector<int> nextTallerBuilding(numBuildings, -1);

        // A vector where each element at index i stores the largest index j such that arr[i...j] is sorted.
        //  E.g., for arr = [1, 3, 5, 2, 4, 6], rightSortedLimit = [2, 2, 2, 5, 5, 5].
        // It is initialized to (numBuildings - 1) for each index, assuming the entire sequence is sorted till the last building, and will be updated based on the actual sorted subarrays
        vector<int> rightSortedLimit(numBuildings, numBuildings-1);


        // We already have the required variables for the last building in place, so let's loop in reverse from the second-last building to the 1st building
        for (int i = numBuildings - 2; i > -1; i -= 1) {
            // If the height of the next building is greater than or equal to the current building's height,
            // the current building is part of the same sorted subarray; otherwise, sorted subarray ends at the current building
            rightSortedLimit[i] = heights[i+1] >= heights[i] ? rightSortedLimit[i+1] : i;

            // Find the next taller building to current building
            nextTallerBuilding[i] = findClosestTallerBuilding(heights, nextTallerBuilding, rightSortedLimit, heights[i], i+1);
        }


        // A vector that stores the final result for each query in the queries array
        vector<int> meetingPoint(numQueries, -1);


        for (int i = 0; i < numQueries; i += 1) {
            int aliceIndex = queries[i][0];
            int bobIndex = queries[i][1];

            // Lets swap the indexes if Alice is standing ahead of Bob
            if (aliceIndex > bobIndex) swap(aliceIndex, bobIndex);

            // If both are standing on the same building, their index is their meeting point
            if (aliceIndex == bobIndex) {
                meetingPoint[i] = aliceIndex;
            }
            // As Bob is standing ahead of Alice, and if Alice can reach Bob, then Bob's index is their meeting point
            else if (heights[bobIndex] > heights[aliceIndex]) {
                meetingPoint[i] = bobIndex;
            }
            // If either Alice or Bob doesn't have a taller building ahead of them, they can't meet
            else if (nextTallerBuilding[aliceIndex] == -1 || nextTallerBuilding[bobIndex] == -1) {
                meetingPoint[i] = -1;
            }
            else {
                // Otherwise, let's find the closest building that is taller than both Alice and Bob's buildings and is reachable by both.
                int maxHeight = max(heights[aliceIndex], heights[bobIndex]);
                int startIndex = max(nextTallerBuilding[aliceIndex], nextTallerBuilding[bobIndex]);
                meetingPoint[i] = findClosestTallerBuilding(heights, nextTallerBuilding, rightSortedLimit, maxHeight, startIndex);
            }

        }
        return meetingPoint;
    }
};