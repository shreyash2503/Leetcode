// https://leetcode.com/problems/build-an-array-with-stack-operations

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> s;
        int count = 0;
        int stream = 1;
        while(count != target.size() && stream <= n){
            int element = target[count];
            int _stream = stream;
            if(!s.empty() && s.top() != target[count - 1]){
                s.pop();
                ans.push_back("Pop");
            }
            if(element == _stream){
                s.push(_stream);
                ans.push_back("Push");
                count++;
                stream++;
            }
            if(element != _stream){
                s.push(_stream);
                ans.push_back("Push");
                stream++;
            }


        }

        return ans;
        
    }
};