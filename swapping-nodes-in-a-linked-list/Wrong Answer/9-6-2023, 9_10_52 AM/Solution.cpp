// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            size ++;
            temp = temp->next;
        }
        int count = 1;
        int end = size + 1 - k;
        temp = head;
        ListNode* first = NULL;
        ListNode* second = NULL;
        while(temp != NULL){
            if(count == k){
                first = temp;
            }
            if(count == end){
                second = temp;
                break;
            }
            temp = temp->next;
            count ++;

        }
        if(first != NULL && second != NULL){
            swap(first->val, second->val);
        }
        return head;

        
    }
};