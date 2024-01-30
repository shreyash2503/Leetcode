// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* one = head;
        ListNode* two = head;
        ListNode* prev = NULL;
        int count = 0;
        while(1)
        {
            if(count!=n)
            {
                 two = two->next;
                count++;
            }
            else
            {
                break;
            }
           
        }
        if(two == NULL)
        {
            head = head->next;
        }
        else
        {
         while(two!=NULL)
        {
            prev = one;
            two = two->next;
            one = one->next;
        }
            
        }
       if(one and one->next)
       {
            prev->next = one->next;
            one->next = NULL;
            return head;
       }
        else
        {
            return one->next ;
        }
        
    }
};