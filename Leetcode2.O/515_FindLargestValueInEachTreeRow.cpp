/***515. Find Largest Value in Each Tree Row
Solved
Medium
Topics
Companies

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:

Input: root = [1,2,3]
Output: [1,3]

 

Constraints:

    The number of nodes in the tree will be in the range [0, 104].
    -231 <= Node.val <= 231 - 1

 */




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



/**
* Write simple Level Order travrsal code and store Max value from each level in new vector array then return that vector array
 */

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int>mxVal;  // to store max value from each level
        if(root==0){ // if tree is empty return empty vector
            return mxVal;
        }
        queue<TreeNode*>que; // to store nodes at each level
        que.push(root);
        while(!que.empty()){ // traverse till all nodes are visited
            int n=que.size();
            vector<int>lvl; // to store values at each level
            while(n--){ // traverse all nodes at current level
                TreeNode* temp=que.front(); // get first node from queue
                que.pop(); // remove node from queue
                lvl.push_back(temp->val); // store value in vector
                if(temp->left){ // if left child is present add it to queue
                    que.push(temp->left); // add left child to queue
                }
                if(temp->right){ // if right child is present add it to queue
                    que.push(temp->right);
                }
            }
            sort(lvl.rbegin(),lvl.rend()); // sort vector in descending order
            mxVal.push_back(lvl[0]); // store max value in vector
        }
    return mxVal; // return vector of max values from each level
    }
};