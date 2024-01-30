// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<long long int> s;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == "+" || v[i] == "*" || v[i] == "/" || v[i] == "-")
            {
                int data1 = s.top();
                s.pop();
                int data2 = s.top();
                s.pop();
                if(v[i] == "+")
                {
                    s.push(data1 + data2);
                }
                else if(v[i] == "-")
                {
                  s.push(data2 - data1);   
                }
                else if(v[i] == "*")
                {
                    s.push(data2 * data1);
                }
                else
                {
                    s.push(data2/data1);
                }
                   
            }
            else
            {
                s.push(stoll(v[i]));
            }
            
        }
        return s.top();
    }
};