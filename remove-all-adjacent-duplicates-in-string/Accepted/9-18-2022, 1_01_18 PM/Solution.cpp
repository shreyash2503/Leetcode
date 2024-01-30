// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string a) {
        stack <char>s;
        for(int i=0;i<a.size();i++)
        {
            if(s.empty() || s.top()!=a[i])
            {
                s.push(a[i]);
            }
            else
            {
                s.pop();
            }
        }
        string t="";
            while(!s.empty())
            {
                t.push_back(s.top());
                s.pop();
            }
        reverse(t.begin(),t.end());
        return t;
    }
};