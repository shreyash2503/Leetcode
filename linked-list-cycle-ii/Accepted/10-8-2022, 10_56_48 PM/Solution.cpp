// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode* fast = head, *slow = head, *ptr = head;
       if(head == NULL || head->next == NULL)
       {
           return NULL;
       }
       while(fast && fast->next)
       {
           slow = slow->next;
           fast = fast->next->next;
           if(slow == fast)
           {
               break;
           }
       }
       if(slow != fast)
       {
           return NULL;
       }
        while(slow != ptr)
        {
            slow = slow->next;
            ptr = ptr->next;
        }
        return slow;
        
        
    }
};