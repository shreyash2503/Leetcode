// https://leetcode.com/problems/reorder-list

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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            s.push(temp);
            size++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0;i<size / 2;i++){
            ListNode* _temp = s.top();
            s.pop();
            _temp->next = NULL;
            ListNode* next = temp->next;
            temp->next = _temp;
            _temp->next = next;
            temp = next;
        }
        temp->next = NULL;

        
    }
};