// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> map;
        Node* newHead = new Node(head->val);
        map[head] = newHead;
        Node* temp = head;
        Node* newTemp = newHead;

        while (temp) {
            if (temp->next) {
                if (!map.count(temp->next))
                    map[temp->next] = new Node(temp->next->val);
                newTemp->next = map[temp->next];
            }

            if (temp->random) {
                if (!map.count(temp->random))
                    map[temp->random] = new Node(temp->random->val);
                newTemp->random = map[temp->random];
            }

            temp = temp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
