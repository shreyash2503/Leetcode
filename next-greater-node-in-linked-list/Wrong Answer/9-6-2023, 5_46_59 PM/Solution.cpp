// https://leetcode.com/problems/next-greater-node-in-linked-list

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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        stack<int> s;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> ans(v.size(), 0);
        for(int i=0;i<v.size();i++){
            if(s.empty()){
                s.push(i);
            } else {
                if(v[s.top()] < v[i]){
                    // int index = s.top();
                    // s.pop();
                    // s.push(i);
                    //v[index] = v[i];
                    while(!s.empty() && v[s.top()] <= v[i]){
                        int index = s.top();
                        ans[index] = v[i];
                        s.pop();
                    }
                    s.push(i);
                } else {
                    s.push(i);
                }
            }

        }

        return ans;


        
        
    }
};