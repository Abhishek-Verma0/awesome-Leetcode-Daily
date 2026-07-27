/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void paths(TreeNode* root, vector<string>& path, string st) {
        if (root == nullptr)
            return;
        st+=to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            path.push_back(st);
         
            return;
        }
        st+="->";
        paths(root->left,path,st);
        paths(root->right,path,st);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        string st = "";
        paths(root,path,st);
        return path;
    }
};