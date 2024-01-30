// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int iterator = 1;
        s.push(asteroids[0]);
        while(iterator <= asteroids.size() - 1){
            if(s.empty() || abs(asteroids[iterator]) > abs(s.top()) && ((asteroids[iterator] > 0 && s.top() < 0) || (asteroids[iterator] < 0 && s.top() > 0))){
                cout<<1;
                s.pop();

            }  else if(s.empty() || abs(asteroids[iterator]) < abs(s.top()) && ((asteroids[iterator] > 0 && s.top() < 0) || (asteroids[iterator] < 0 && s.top() > 0))){
                iterator++;
                cout<<2;

            }  else if(s.empty() || abs(asteroids[iterator]) > abs(s.top()) && ((asteroids[iterator] > 0 && s.top() > 0) || (asteroids[iterator] < 0 && s.top() < 0))){
               s.push(asteroids[iterator]);
               iterator++;
               cout<<3;

            } else if(s.empty() || abs(asteroids[iterator]) < abs(s.top()) && ((asteroids[iterator] > 0 && s.top() > 0) || (asteroids[iterator] < 0 && s.top() < 0))){
                s.push(asteroids[iterator]);
                iterator++;
                cout<<3;

            } else if(abs(asteroids[iterator] == abs(s.top()) && ((asteroids[iterator] > 0 && s.top() > 0) || (asteroids[iterator] < 0 && s.top() < 0)))){
                s.push(asteroids[iterator]);
                iterator ++ ;
                cout<<4;
            } else if(abs(asteroids[iterator] == abs(s.top())) && asteroids[iterator] != s.top()){
                s.pop();
                iterator ++ ;
                cout<<5;
            }
            else {
                s.pop();
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