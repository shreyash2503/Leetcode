// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
        {
            return head;
        }
        int count = 1;
        ListNode* lef;
        ListNode* righ;
        ListNode* temp = head;

        if(left == right-1)
        {
            ListNode* prev = NULL;
            while(temp != NULL)
            {
                if(count == left)
                {
                    lef = temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
                count++;
            }
            if(lef->next->next == NULL)
            {
              ListNode* tail = lef->next;
              tail->next = temp;
              temp->next = NULL;
              return tail;
            }
            else
            {
            if(lef && lef->next)
            {
                ListNode *next = lef->next;       //Right Node;
                ListNode* next2 = lef->next->next;
                prev->next = next;
                next->next = lef;
                lef->next = next2;
            }
            return head;
            }

            
        }


        

        else if(left == 1 && right != left+1)
        {
            lef = temp;
            while(temp != NULL)
            {
                if(count == right-1)
                {
                    righ = temp;
                    break;
                }
                temp = temp->next;
                count++;
                
            }
                ListNode* n2 = righ->next;
                ListNode* next1 = lef->next;
                ListNode* next2 = righ->next->next;
                n2->next = next1;
                righ->next = lef;
                lef->next = next2;
                return head;
        }
        else
        {
        while(temp != NULL)
        {
            if(count == left-1)
            {
                lef = temp;
            }
            if(count == right-1)
            {
                righ = temp;
                break;
            }
            temp = temp->next;
            count++;
        }
        ListNode* n1 = lef->next;
        ListNode* n2 = righ->next;
        ListNode* next1 = lef->next->next;
        ListNode* next2 = righ->next->next;
        lef->next = n2;
        righ->next = n1;
        n2->next = next1;
        n1->next = next2;
        return head;

        }
        return head;
       
        
    }
};