// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a == NULL) return b;
        if(b == NULL) return a;
        ListNode* finalHead = NULL;
        if(a->val > b->val)
        {
            finalHead = b;
            b = b->next;
        }
        else
        {
            finalHead = a;
            a = a->next;
        }
        ListNode* finalTail = finalHead;
        while(a && b)
        {
            if(a->val > b->val)
            {
                finalTail->next = b;
                b = b->next;
            }
            else
            {
                finalTail->next = a;
                a = a->next;
            }
            finalTail = finalTail->next;
        }
        if(a == NULL)
        {
            finalTail->next = b;
        }
        else
        {
            finalTail->next = a;
        }
        return finalHead;
    }
};