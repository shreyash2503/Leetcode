// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

class Solution {
public:

    int count = 0;
    int minDeletions(string s) {
        map<char, int> map;
        for(auto x : s){
            map[x] ++;
        }
        
        priority_queue<int> pq;
        for(const auto x : map){
            pq.push(x.second);
        }

        while(pq.size() != 1){
            auto top = pq.top();
            pq.pop();

            if(top == pq.top() && top != 0){
                count ++;
                pq.push(top - 1);
            }
        }
        return count;
        
        
        


    }
};