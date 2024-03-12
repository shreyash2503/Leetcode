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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);   
        ListNode* current = front;
        unordered_map<int, ListNode*> map;
        int sum {};
        while(current != nullptr){
            sum += current->val;
            if(map.find(sum) != map.end()){
                ListNode* prev = map[sum];
                current = prev->next;
                int p = sum + current->val;
                while(p != sum){
                    map.erase(p);
                    current = current->next;
                    p += current->val;
                }
                prev->next = current->next;
            } else {
                map[sum] = current;
            }
            current = current->next;
        }

        return front->next;


        
    }
};
