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
    if(head->next==NULL){
        return head;
    }
    ListNode*temp=head;
    int s=0;
    while(temp!=NULL){
        temp=temp->next;
        s++;
    }
    ListNode*n1=head;
      int t=1;
      while(t!=k){
         n1=n1->next;
         t++;
      }
      ListNode*n2=head;
      t=1;
      while(t!=s+1-k){
          n2=n2->next;
          t++;
      }
      swap(n1->val,n2->val);
      return head;
    }
};
// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         int size = 0;
//         ListNode* temp = head;
//         while(temp != NULL){
//             size ++;
//             temp = temp->next;
//         }
//         int count = 0;
//         int end = size + 1 - k;
//         temp = head;
//         ListNode* first = NULL;
//         ListNode* second = NULL;
//         while(temp != NULL){
//             count ++;
//             if(count == k){
//                 first = temp;
//             }
//             if(count == end){
//                 second = temp;
//                 break;
//             }
//             temp = temp->next;

//         }
//         if(first != NULL && second != NULL){
//             swap(first->val, second->val);
//         }
//         return head;

        
//     }
// };