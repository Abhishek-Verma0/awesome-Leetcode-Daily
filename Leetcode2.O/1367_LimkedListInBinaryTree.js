/**1367. Linked List in Binary Tree
Medium
Topics
Companies
Hint

Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

 

Example 1:

Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  

Example 2:

Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true

Example 3:

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.

 

Constraints:

    The number of nodes in the tree will be in the range [1, 2500].
    The number of nodes in the list will be in the range [1, 100].
    1 <= Node.val <= 100 for each node in the linked list and binary tree.

 */





/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {ListNode} head
 * @param {TreeNode} root
 * @return {boolean}
 */


var isSubPath = function(head, root) {
    return dfs(head, head, root);
};

var dfs = function(head, cur, root) {
    if (cur === null) return true;  // Successfully matched the list
    if (root === null) return false; // Reached the end of the tree without matching
    
    if (cur.val === root.val) {
        cur = cur.next;  // Move to the next list node if value matches
    } else if (head.val === root.val) {
        head = head.next; // Start new matching attempt if the value matches head of list
    } else {
        cur = head;  // Reset the matching pointer
    }
    
    // Recursively check left and right subtrees
    return dfs(head, cur, root.left) || dfs(head, cur, root.right);
};