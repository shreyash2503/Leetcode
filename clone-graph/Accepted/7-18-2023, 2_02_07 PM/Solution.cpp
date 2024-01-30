// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
      unordered_map<int, Node*> map;
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
          Node* temp = q.front();
          q.pop();
          if(temp){
                if( map.find(temp->val) == map.end()){
                    map[temp->val] = new Node(temp->val);
                    for(int i=0;i<temp->neighbors.size();i++){
                        if(map.find(temp->neighbors[i]->val) == map.end()){
                            map[temp->neighbors[i]->val] = new Node(temp->neighbors[i]->val);
                            q.push(temp->neighbors[i]);
                            }
                            map[temp->val]->neighbors.push_back(map[temp->neighbors[i]->val]);

                    }
                } else {
                    Node* flag = map[temp->val];
                    for(int i=0;i<temp->neighbors.size();i++){
                        if(map.find(temp->neighbors[i]->val) == map.end()){
                            map[temp->neighbors[i]->val] = new Node(temp->neighbors[i]->val);
                            q.push(temp->neighbors[i]);
                        }
                        flag->neighbors.push_back(map[temp->neighbors[i]->val]);

                    }


                }
          }
      }
      return map[1];
        
    }
};