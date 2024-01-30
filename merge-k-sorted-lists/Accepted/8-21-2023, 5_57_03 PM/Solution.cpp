// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* merge(ListNode* a, ListNode* b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        ListNode* newHead = NULL;
        if(a->val > b->val){
            newHead = b;
            b->next = merge(a, b->next);

        } else {
            newHead = a;
            newHead->next = merge(a->next, b);
        }
        return newHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 1 && lists[0] == NULL){
            return NULL;
        }
        ListNode* prev = lists[0];

        for(int i=1;i<lists.size();i++){
            prev = merge(prev, lists[i]);
        }

        return prev;
      
        
        
    }
};