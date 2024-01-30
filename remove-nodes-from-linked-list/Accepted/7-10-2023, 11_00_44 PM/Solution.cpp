// https://leetcode.com/problems/remove-nodes-from-linked-list

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
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        int max = prev->val;
        ListNode* newHead = prev;
        curr = prev->next;
        ListNode* temp = prev;
        while(curr != NULL){
            if(max > curr->val && prev->next){
                ListNode* a = prev->next->next;
                curr->next = NULL;
                prev->next = a;
                curr = prev->next;
            }
            else if(max < curr->val){
                max = curr->val;
                prev = curr;
                curr = curr->next;
               
            } else {
                prev = curr;
                curr = curr->next;

            }
        }
        ListNode* newprev = NULL;
        ListNode* newcurr = newHead;
        while(newcurr != NULL){
            ListNode* temp = newcurr->next;
            newcurr->next = newprev;
            newprev = newcurr;
            newcurr = temp;
        }

        return newprev;

        

        
    }
};