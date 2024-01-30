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
    pair<ListNode*, ListNode*> reverse(ListNode* head, int count, int end){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(count <= end){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count ++;
        }
        return make_pair(prev, curr);




    }
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            size ++;
            temp = temp->next;
        }

        int end = size + 1 - k;
        int count = 1;

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            if(count == k){

                auto p = reverse(curr, count, end);
                ListNode* _temp = p.first;
                if(prev != NULL){
                    prev->next = _temp;

                }
                while(_temp->next != NULL){
                    _temp = _temp->next;
                }
                _temp->next = p.second;
                if(k == 1){
                    p.first;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
            count ++;

        }

        return head;

        
    }
};