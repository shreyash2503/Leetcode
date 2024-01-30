// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
 
    pair<ListNode*, ListNode*> findMiddle(ListNode* head){
        ListNode* temp = head;
        pair<ListNode*, ListNode*> p;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        p.first = slow;
        p.second = slow->next;
        return p;
    }
    int pairSum(ListNode* head) {
        pair<ListNode*, ListNode*> p;
        p = findMiddle(head);
        p.first->next = NULL;
        ListNode* curr = p.second;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        int max  = INT_MIN;
        while(head != NULL && prev != NULL){
            if(head->val + prev->val > max){
                max = head->val + prev->val;
            }
            head = head->next;
            prev = prev->next;
        
        }
        return max;
        
        
        
    }
};