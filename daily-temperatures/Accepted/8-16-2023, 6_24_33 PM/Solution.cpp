// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> answer(temperatures.size(), 0);
        for(int i=temperatures.size() - 1;i>=0;i--){
            if(s.empty()){
                answer[i] = 0;
                s.push(i);
                
            } else {
                while(!s.empty() && temperatures[i] >= temperatures[s.top()]){
                    s.pop();
                }
                if(s.empty()){
                    answer[i] = 0;
                } else {
                    answer[i] = s.top() - i;
                }
                s.push(i);
            } 
        }

        return answer;
    }
};