// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> _s;
        for(auto c : s){
            if(s.empty()){
                _s.push(c);
            } else if(c == '(' || c == '[' || c == '{'){
                _s.push(c);
            } else if(c == ')' && _s.top() == '('){
                _s.pop();
            } else if(c == ']' &&_s.top() == '['){
                _s.pop();
            } else if(c == '}' && _s.top() == '{'){
                _s.pop();
            } else {
                return false;
            }

        }

        return _s.size() > 0 ? false : true;        
    }
};