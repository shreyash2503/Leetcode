// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* greater = new ListNode(0);
        ListNode* temp_less = less;
        ListNode* temp_greater = greater;
        while(head != NULL){
            if(head->val < x){
                temp_less->next = head;
                temp_less = temp_less->next;
            } else {
                temp_greater->next = head;
                temp_greater = temp_greater->next;
            }
            head = head->next;
           
        }
        temp_greater->next = NULL;
        temp_less->next = greater->next;

        return less->next;
        
    }
};