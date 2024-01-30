// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string a) {
        stack<char> s;
            for(int i=0;i<a.length();i++)
            {
                if(a[i] == '(' || a[i] == '[' || a[i] == '{')
                {
                    s.push(a[i]);
                }
                else
                {
                    if(s.empty()) return false;
                    if((a[i] == ')' && s.top() == '(') || (a[i] == '}' && s.top() == '{') || (a[i] == ']' && s.top() == '['))
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        if(s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};