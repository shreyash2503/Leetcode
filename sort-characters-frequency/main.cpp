class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char, int> map;

       for(char &c : s){
           map[c] ++;
       }

       priority_queue<pair<int, int>> pq;
       for(auto &[first, second] : map){
           pq.push({second, first});
       }
       string ans = "";

       while(!pq.empty()){
           auto [first, second] = pq.top(); pq.pop();
           for(int i{};i<first;i++){
               ans += second;
           }
       }
       return ans;
        
    }
};
