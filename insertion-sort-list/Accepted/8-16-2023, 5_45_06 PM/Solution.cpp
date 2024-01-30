// https://leetcode.com/problems/insertion-sort-list

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        ListNode* next = NULL;
        int count = 0;
        while(temp != NULL){
            ListNode* i = temp;
            next = temp->next;
            int j = count;
            int swap = count;
            while(next != NULL){
                if(next->val < i->val){
                    i = next;
                    swap = j;
                }
                next = next->next;
                j++;

            }
            int flag = temp->val;
            temp->val = i->val;
            i->val = flag;
            count++;
            temp = temp->next;

        }

        return head;
        
    }
};