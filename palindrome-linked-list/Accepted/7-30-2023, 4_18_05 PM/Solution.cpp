// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        ListNode* flag = head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        vector<int> v;
        while(curr != NULL){
            v.push_back(curr->val);
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        int i = 0;

        while(prev != NULL){
            cout<<v[i];
            if(prev->val != v[i]){
                return false;
            }
            prev = prev->next;
            i++;
        }

        return true;

        
    }
};