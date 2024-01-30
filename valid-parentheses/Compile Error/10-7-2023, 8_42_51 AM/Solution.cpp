// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> _s;
        if(s[0] == ']' || s[0] == ')' || s[0] == '}'){
            return false;
        }
        for(auto c : s){
            if(c == '(' || c == '{' || c == '['){
                _s.push(c);
            } else if(!_s.empty() && c == ')' && _s.top() == '('){
                _s.pop();
            } else if(!_s.emtpy() && c == '}' && _s.top() == '{'){
                _s.pop();
            } else if(!_s.empty() && c == ']' && _s.top() == '['){
                _s.pop();
            } else {
                return false;
            }
        }

        return _s.size() > 0 ? false : true;        
    }
};