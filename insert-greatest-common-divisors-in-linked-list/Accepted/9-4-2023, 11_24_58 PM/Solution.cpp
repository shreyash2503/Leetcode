// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr != NULL){
            int gcd = __gcd(prev->val, curr->val);
            ListNode* temp = new ListNode(gcd);
            prev->next = temp;
            temp ->next = curr;
            prev = curr;
            curr = curr->next;
        }

        return head;
        
    }
};