// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;

        ListNode* prev = dummyNode;
        ListNode* curr = head;
        while(curr && curr->next){
            prev->next = curr->next;
            curr->next = curr->next->next;

            prev->next->next = curr;

            prev = curr;
            curr = curr->next;

        }

        return dummyNode->next;


        
    }
};