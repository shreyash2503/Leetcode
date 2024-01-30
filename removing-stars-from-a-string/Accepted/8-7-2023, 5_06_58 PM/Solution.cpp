// https://leetcode.com/problems/removing-stars-from-a-string

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(const auto& i : s){
            if(i == '*'){
                st.pop();
                continue;
            }
            st.push(i);
        }
        string str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
        
    }
};