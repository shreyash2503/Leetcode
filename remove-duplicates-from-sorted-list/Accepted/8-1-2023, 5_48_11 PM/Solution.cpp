// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            if(s.find(curr->val) == s.end()){
                s.insert(curr->val);
            } else {
                ListNode* temp = prev->next->next;
                curr->next = NULL;
                prev->next = temp;
                curr = temp;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
        
    }
};