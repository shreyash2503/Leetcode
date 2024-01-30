// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return NULL;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast && fast->next){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == NULL){
            ListNode* temp = prev->next->next;
            prev->next->next = NULL;
            prev->next = temp;
            return head;
        }
        if(fast->next == NULL){
            ListNode* temp = slow->next->next;
            slow->next->next = NULL;
            slow->next = temp;
            return head;
        }
        return head;
        
    }
};