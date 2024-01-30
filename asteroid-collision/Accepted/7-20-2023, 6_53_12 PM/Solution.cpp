// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int iterator = 1;
        stack<int> s;
        int big = -1;
        int flag = 0;
        s.push(asteroids[0]);
        while(iterator < asteroids.size()){
            cout<<iterator<<endl;
            if(flag == 0){
                big = asteroids[iterator];
            }
            if(!s.empty() && abs(s.top()) == abs(big) && s.top() > 0 && big < 0){
                s.pop();
                iterator ++;
                flag = 0;
                continue;
            }
            if(!s.empty() && s.top() > 0 && big < 0 && abs(s.top()) != abs(big)){
                big = abs(s.top()) > abs(asteroids[iterator]) ? s.top() : asteroids[iterator];
                s.pop();
                flag = 1;
                continue;
            }
            if(flag == 0) {
                s.push(asteroids[iterator]);
                iterator ++;
            }
            if(flag == 1){
                s.push(big);
                flag = 0;
                iterator ++; 
            }
        }
        vector<int> ans;

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;

        
    }
};