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
      ListNode* target = head->next;
      ListNode* even = head->next;
      ListNode* odd = head;
       while(even && odd){
          odd->next = odd->next->next;
          even->next = even->next->next;
          odd = odd->next;
          even = even->next;
       }
       odd->next = target;
       return head;

        
    }
};