


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> vec;
    int n = grid.size(), m = grid[0].size();

    // converting 2d grid to 1d array 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vec.push_back(grid[i][j]);

    // Check if all elements can be transformed using x
    int remainder = vec[0] % x;
    for (int num : vec) {
        if (num % x != remainder)
            return -1; // Not possible
    }

    // Sort the array to find the median
    sort(vec.begin(), vec.end());
    int median = vec[vec.size() / 2];

    // Calculate the number of operations required
    int operations = 0;
    for (int num : vec) {
        operations += abs(num - median) / x;
    }

    return operations;
        
    }
};