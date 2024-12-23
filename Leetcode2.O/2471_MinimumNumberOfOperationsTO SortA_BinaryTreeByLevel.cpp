/***2471. Minimum Number of Operations to Sort a Binary Tree by Level
Solved
Medium
Topics
Companies
Hint

You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:

Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 2:

Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 3:

Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.

 

Constraints:

    The number of nodes in the tree is in the range [1, 105].
    1 <= Node.val <= 105
    All the values of the tree are unique.

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
class Solution {
public:
 int swapCount(vector<int>& vec){
    int swap=0;  // to store the minimum count

     vector<int> sorted(begin(vec),end(vec) ); // it copies all element of vec to this new vector

    sort(begin(sorted),end(sorted)); // this inbuilt funtion sorts the vector in ascending order 

        /// now A map to store the values and their indices of unsroted vector to make efficient operations 
        unordered_map<int,int>mp;
        for(int i=0;i<vec.size();i++){
            mp[vec[i]]=i;  // this stores the value vec[i] mapped to its index 'i' in the map 
        }
// this loop will check for the whether a swap is needed or not to make unsorted to sorted 
        for(int i=0;i<vec.size();i++){
            if(vec[i]==sorted[i]){
                continue;
            }
            int currIndx= mp[sorted[i]]; // stores the index of the value which is not at right place
            mp[vec[i]]= currIndx; // update the index of  before the swapping the elements in map
            mp[vec[currIndx]]=i;  
           std::swap(vec[currIndx],vec[i]); // swap the elemnts in unsorted array
            swap++;
        }
        return swap;  // this value goes to next function
 }



    int minimumOperations(TreeNode* root) {
        int res=0;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int n=que.size();
            vector<int> vec; // to store the Node values of each level 
            while(n--){
                TreeNode* temp=que.front(); // stores the first node in que
                que.pop(); // pops out the first node from que
                vec.push_back(temp->val); // pushes value of the temp to the vector that stores values of single level at a time
                if(temp->left){ // if node has anty left child
                    que.push(temp->left);  // push it into the queue
                }
                if(temp->right){ // if node has any right child
                    que.push(temp->right); // push it into the queue
                }
            }
            res+=swapCount(vec);  // this will store the min count that will be needed to sort each lvl of tree
        }
        return res;
    }
};