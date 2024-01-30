// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
    static bool compare(pair<int, int> p1, pair<int, int> p2){
       if(p1.first < p2.first){
           return true;
       } 
       if(p1.first == p2.first){
           return p1.second < p2.second;
       }
       return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        int index = 0;
        for(auto x : mat){
            int sum = accumulate(x.begin(), x.end(), 0);
            v.push_back(make_pair(sum, index));
            index++;
        }
        sort(v.begin(), v.end(), compare);

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;

        
        
    }
};