// https://leetcode.com/problems/path-crossing

class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> origin = make_pair(0, 0);
        set<pair<int, int>> s;
        s.insert(origin);
        for(char c : path){
            if(c == 'N'){
                origin.second += 1;
            } else if(c == 'E'){
                origin.first += 1;
            } else if(c == 'S'){
                origin.second -= 1;
            } else {
                origin.first -= 1;
            }
            if(s.find(origin) != s.end()){
                return true;
            } else {
                s.insert(origin);
            }
        }
        return false;
        
    }
};