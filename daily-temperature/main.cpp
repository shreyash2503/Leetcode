class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t size = temperatures.size();
        vector<int> ans(size, 0);
        stack<int> s;


        for(int i{};i<size;i++){
           while(!s.empty() && temperatures[s.top()] < temperatures[i]){
               ans[s.top()] = i - s.top(); s.pop();
           }
           s.push(i);
        }
        return ans;
        
    }
};
