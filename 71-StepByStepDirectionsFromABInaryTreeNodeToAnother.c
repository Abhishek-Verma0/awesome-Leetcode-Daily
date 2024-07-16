/*2096. Step-By-Step Directions From a Binary Tree Node to Another
Medium
Topics
Companies
Hint

You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

    'L' means to go from a node to its left child node.
    'R' means to go from a node to its right child node.
    'U' means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node s to node t.



Example 1:

Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

Example 2:

Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.



Constraints:

    The number of nodes in the tree is n.
    2 <= n <= 105
    1 <= Node.val <= n
    All the values in the tree are unique.
    1 <= startValue, destValue <= n
    startValue != destValue

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool getPath(struct TreeNode *node, const int *target, char **path, int *len)
{
    if (node == NULL)
        return false;

    if (node->val == *target)
        return true;

    // Check left side, if not found, pop the step
    (*path)[(*len)++] = 'L';
    bool left = getPath(node->left, target, path, len);
    if (!left)
    {
        (*len)--;
    }

    // Check right side, if not found, pop the step
    (*path)[(*len)++] = 'R';
    bool right = getPath(node->right, target, path, len);
    if (!right)
    {
        (*len)--;
    }

    return left || right;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char *getDirections(struct TreeNode *root, int startValue, int destValue)
{
    char *tostart = (char *)malloc((1e5 + 1) * sizeof(char));
    if (tostart == NULL)
    {
        return NULL;
    }

    char *toend = (char *)malloc((1e5 + 1) * sizeof(char));
    if (toend == NULL)
    {
        free(tostart);
        return NULL;
    }

    int len_start = 0;
    int len_end = 0;

    getPath(root, &startValue, &tostart, &len_start);
    getPath(root, &destValue, &toend, &len_end);

    int depth = 0;
    while (depth < len_start && depth < len_end && tostart[depth] == toend[depth])
    {
        depth++;
    }

    int resultSize = len_start - depth + len_end - depth + 1;
    char *result = (char *)malloc(resultSize * sizeof(char));
    if (result == NULL)
    {
        free(tostart);
        free(toend);
        return NULL;
    }

    int idx = 0;
    for (int i = depth; i < len_start; ++i)
    {
        result[idx++] = 'U';
    }

    for (int i = depth; i < len_end; ++i)
    {
        result[idx++] = toend[i];
    }

    result[idx] = '\0';

    free(tostart);
    free(toend);

    return result;
}