/*1382. Balance a Binary Search Tree
Solved
Medium
Topics
Companies
Hint

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:

Input: root = [2,1,3]
Output: [2,1,3]

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    1 <= Node.val <= 105

*/







struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct TreeNode* root, int* a, int* index) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, a, index);
    a[(*index)++] = root->val;
    inorder(root->right, a, index);
}

struct TreeNode* buildBalancedBST(int* a, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct TreeNode* root = newNode(a[mid]);
    root->left = buildBalancedBST(a, start, mid - 1);
    root->right = buildBalancedBST(a, mid + 1, end);
    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    int a[10001];
    int index = 0;
    inorder(root, a, &index);
    return buildBalancedBST(a, 0, index - 1);
}