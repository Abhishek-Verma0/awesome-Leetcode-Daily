/*2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
Medium
Topics
Companies
Hint

A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

Example 1:

Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].

Example 2:

Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

Example 3:

Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.

 

Constraints:

    The number of nodes in the list is in the range [2, 105].
    1 <= Node.val <= 105


*/








/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int minor(int a, int b){
    return (a < b) ? a : b;
}

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int* retlist = malloc(sizeof(int)*2);
    *returnSize = 2;

    int crits[100001];
    int critsind = 0;

    int index = 2;
    struct ListNode* previter = head;
    struct ListNode* iter;

    int lmmin = -1;
    int lmmax = -1;
    int rmmin = -1;
    int rmmax = -1;


    iter = head->next;

    while(iter->next != NULL){
        if((iter->val < previter->val && iter->val < iter->next->val) || (iter->val > previter->val && iter->val > iter->next->val)){
            crits[critsind++] = index;
        }

        index++;
        previter = iter;
        iter = iter->next;

        
    }

    if((critsind <= 1) || (head->next == NULL || head->next->next == NULL)){
        retlist[0] = -1;
        retlist[1] = -1;

        return retlist;
    }


    int min = 100001;
    for(int i = 0; i < critsind - 1; i++){
        min = minor(min, crits[i + 1] - crits[i]);
    }

    retlist[0] = min;
    retlist[1] = crits[critsind - 1] - crits[0];


    
    
    return retlist;

}