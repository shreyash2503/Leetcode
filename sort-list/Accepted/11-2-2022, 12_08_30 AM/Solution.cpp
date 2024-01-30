// https://leetcode.com/problems/sort-list

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
    ListNode* mergeLists(ListNode* a, ListNode* b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        ListNode* newHead = NULL;
        if(a->val > b->val)
        {
            newHead = b;
            newHead->next = mergeLists(a, b->next);
        }
        else
        {
            newHead = a;
            newHead->next = mergeLists(a->next, b);
        }
        return newHead;

        }
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL ) return head;;
        ListNode* slow = head; 
        ListNode* fast = head->next;
         while(fast && fast->next)
         {
             slow = slow->next;
             fast = fast->next->next;
         }  
         ListNode* n = slow->next;
         slow->next = NULL;
        ListNode* a = sortList(head);
        ListNode* b = sortList(n);
        ListNode* newHead = mergeLists(a, b);
        return newHead;
        
    }
};