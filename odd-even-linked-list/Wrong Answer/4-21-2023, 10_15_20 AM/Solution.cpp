// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
       ListNode* curr = head;
       ListNode* target = head->next;
       cout<<target->val;
       ListNode* forw = head;;
       while(forw->next != nullptr){
           forw = curr->next;
           curr->next = curr->next->next;
           curr = forw;
       }
       curr->next = target;
       return head;

        
    }
};