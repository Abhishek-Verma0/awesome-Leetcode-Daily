/***83. Remove Duplicates from Sorted List
Solved
Easy
Topics
Companies

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:

Input: head = [1,1,2]
Output: [1,2]

Example 2:

Input: head = [1,1,2,3,3]
Output: [1,2,3]

 

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* create(ListNode* head1, int data){
            ListNode* newNode= new ListNode();
            newNode->val=data;
            newNode->next=nullptr;
            if(head1==nullptr){
                return newNode;
            }
            ListNode* temp=head1;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
            return head1;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* head1=nullptr;

    if(head==nullptr){
        return nullptr;
    }
        ListNode* temp= head;
        int dup=temp->val;
        head1=create(head1,dup);
        while(temp!=nullptr){
            if(temp->val==dup){
                temp=temp->next;
                continue;
            }
            
            dup=temp->val;
            head1=create(head1,dup);
            temp=temp->next;
            
            


        }
        return head1;
    }
};
// link to my leetcode solution do visit and upvote
`https://leetcode.com/problems/remove-duplicates-from-sorted-list/solutions/6217499/easy-beats-100-by-abhishek-verma01-o6er `