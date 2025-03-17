

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left=left, right=right {}
 * };
 */



/**
 * T.C -> O(n)
 * S.C -> O(n)
 */


class Solution {
public:
     vector<int>sum; // Vector to store the inorder traversal of the tree.
    void inorder(TreeNode* root){
        if(root==nullptr){ // Base case: if the node is null, return.
            return;
        }
            inorder(root->left); // Recursively traverse the left subtree.
            sum.push_back(root->val); // Add the current node's value to the vector.
            inorder(root->right); // Recursively traverse the right subtree.
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root); // Perform inorder traversal to get a sorted array of node values.
        int target=0; // Variable to store the complement needed to reach the target sum.
        map<int,int>mp; // Map to store the elements encountered and their indices.
        for(int i=0;i<sum.size();i++){ // Iterate through the sorted array.
            target=k-sum[i]; // Calculate the complement needed.
            if(mp.find(target)!=mp.end()){ // Check if the complement exists in the map.
                return true; // If the complement exists, return true (found a pair).
            }
            mp[sum[i]]=i; // Add the current element and its index to the map.
        }
        return false; // If no pair is found, return false.
    }
};