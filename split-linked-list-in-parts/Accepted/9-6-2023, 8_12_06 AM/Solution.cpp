// https://leetcode.com/problems/split-linked-list-in-parts

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }

        int rem = size % k;
        int width = size / k;
        vector<ListNode*> v;
        ListNode* curr = head;
        for(int i=0;i<k;i++){
            ListNode* temp = curr;
            int length = (i < rem ? 1 : 0) + width - 1;
            for(int j=0;j<length;j++){
                if(curr != NULL){
                    curr = curr->next;
                }
            }
            if(temp != NULL){
                ListNode* prev = curr;
                curr = curr->next;
                prev->next = NULL;

            }
            v.push_back(temp);


        }
       

        return v;
        
        
        
    }
};