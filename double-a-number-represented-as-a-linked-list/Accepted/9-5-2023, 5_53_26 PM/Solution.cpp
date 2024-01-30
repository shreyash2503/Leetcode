// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list

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
    ListNode* doubleIt(ListNode* head) {

        ListNode* temp = head;
        vector<int> v;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int carry = 0;
        for(int i=v.size()-1;i>=0;i--){
            int _temp = 2 * v[i] + carry;
            if(_temp / 10 >= 1){
                carry = _temp / 10;
                v[i] = _temp % 10;
            } else {
                carry = 0;
                v[i] = _temp;
            }
        }
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        if(carry == 0){
            for(auto i : v){
                if(newHead == NULL && newTail == NULL){
                    newHead = new ListNode(i);
                    newTail = newHead;
                } else {
                    newTail->next = new ListNode(i);
                    newTail = newTail->next;
                }
            }
        } else {
            newHead = new ListNode(carry);
            newTail = newHead;
            for(auto i : v){
                newTail->next = new ListNode(i);
                newTail = newTail->next;
            }
        }

        return newHead;
        
    }
};