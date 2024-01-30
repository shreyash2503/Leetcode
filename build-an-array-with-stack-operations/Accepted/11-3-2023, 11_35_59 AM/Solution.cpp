// https://leetcode.com/problems/build-an-array-with-stack-operations


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int count = 0;
        int stream = 1;
        
        while (count < target.size() && stream <= n) {
            int element = target[count];
            int currentStream = stream;

            
            if (element == currentStream) {
                ans.push_back("Push");
                count ++;
                
            } else {
                
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            stream++;

        }

        return ans;
    }
};
