/**590. N-ary Tree Postorder Traversal
Solved
Easy
Topics
Companies

Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]

 

Constraints:

    The number of nodes in the tree is in the range [0, 104].
    0 <= Node.val <= 104
    The height of the n-ary tree is less than or equal to 1000.

 

Follow up: Recursive solution is trivial, could you do it iteratively?
 */



/**
 * // Definition for a _Node.
 * function _Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {_Node|null} root
 * @return {number[]}
 */
var postorder = function(root) {
//create a array tp stpre the values in order
     const arr = []

     //sb functon for traversing
    const traverse = (root) => {
        //WHEN THERE IS VALUES IN ROOTAND IT HAVE CHILDRENS
        if(root){
            if(root.children){
            //ILLETRATE THROOUGH THE CHILDRESN  AND AAIN CALL THE CHILDREN USING RECURSION,WE USE TO CALL AGAIN THE FUNCTION WITH THE  CHILDREN IS BECAUSE TO FIND HOW MANY DEPTH OR HOW MANU SUB CHILDREN IS THERE OR TO FIND THE LEAF NODE
        for(let node of root.children){
           traverse(node)
            }
        }

        //AFTER THE FOR LOOP AND ALL ADD THE CURRENT VALUE  VECAUSE THIS IA A POST ORDER 
// iN POST ORDER FIRST IS ALL CHILDREN NODES THEN IS THE PARENT NODE
            arr.push(root.val)
        }
    }

    //FIRST CALLING OF THE FUNCTION
    traverse(root)
//AFTER GETTING TEH VLAUSSS RETURN THE ARR TO GET RESULT
    return arr

    
};