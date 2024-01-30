// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pre = NULL;
        ListNode* curr = NULL;
        ListNode* forw = NULL;
        ListNode* temp = head;
        for(int i=0;i<left-2;i++){
            temp = temp->next;

        }
        pre = temp;
        curr = pre->next;
        for(int i=0;i<right-left;i++){
            forw = curr->next;
            curr->next = forw->next;
            forw->next = pre->next;
            pre->next = forw;
        }
        return head;
        
       
        
    }
};