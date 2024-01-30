// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        ListNode* temp1 = headA;
        int count1 = 0;
        while(temp1 != NULL){
            temp1 = temp1->next;
            count1++;

        }

        ListNode* temp2 = headB;
        int count2 = 0;
        while(temp2 != NULL){
            temp2 = temp2->next;
            count2 ++;
        }
        if(count1 > count2){
            int skip = count1 - count2;
            int tempCount = 0;
            while(skip != tempCount){
                headA = headA->next;
                tempCount++;
                
            }
            while(headA != headB){
                    headA = headA->next;
                    headB = headB->next;
                }
            return headA;
        } else {
            int skip = count2 - count1;
            int tempCount = 0;
            while(skip != tempCount){
                headB = headB->next;
                tempCount++;
            }
            while(headA != headB){
                headA = headA->next;
                headB = headB->next;
            }
            return headA;

        }

        return NULL;
       
       
    }
};