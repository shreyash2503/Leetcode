// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int iterator = 1;
        s.push(asteroids[0]);
        while(iterator <= asteroids.size() - 1){
            cout<<1;
            if(s.empty() || abs(asteroids[iterator]) > abs(s.top()) && ((asteroids[iterator] > 0 && s.top() < 0) || (asteroids[iterator] < 0 && s.top() > 0))){
                s.pop();

            }  else if(s.empty() || abs(asteroids[iterator]) < abs(s.top()) && ((asteroids[iterator] > 0 && s.top() < 0) || (asteroids[iterator] < 0 && s.top() > 0))){
                iterator++;

            }  else if(s.empty() || abs(asteroids[iterator]) > abs(s.top()) && ((asteroids[iterator] > 0 && s.top() > 0) || (asteroids[iterator] < 0 && s.top() < 0))){
               s.push(asteroids[iterator]);
               iterator++;

            } else if(s.empty() || abs(asteroids[iterator]) < abs(s.top()) && ((asteroids[iterator] > 0 && s.top() > 0) || (asteroids[iterator] < 0 && s.top() < 0))){
                s.push(asteroids[iterator]);
                iterator++;

            } else if(abs(asteroids[iterator] == abs(s.top()) && ((asteroids[iterator] > 0 && s.top() > 0) || (asteroids[iterator] < 0 && s.top() < 0)))){
                s.push(asteroids[iterator]);
                iterator ++ ;
            } else if(abs(asteroids[iterator] == abs(s.top()) && ((asteroids[iterator] > 0 && s.top() < 0) || (asteroids[iterator] < 0 && s.top() > 0)))){
                cout<<"hello";
                s.pop();
                iterator ++ ;
            }
            else {
                iterator ++;
            };

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