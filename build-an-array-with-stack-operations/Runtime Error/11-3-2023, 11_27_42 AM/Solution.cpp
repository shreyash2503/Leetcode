// https://leetcode.com/problems/build-an-array-with-stack-operations


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> s;
        int count = 0;
        int stream = 1;
        
        while (count < target.size() && stream <= n) {
            int element = target[count];
            int currentStream = stream;

            if (!s.empty() && s.top() != target[count - 1]) {
                s.pop();
                ans.push_back("Pop");
            }

            if (element == currentStream) {
                s.push(currentStream);
                ans.push_back("Push");
                count++;
            } else {
                s.push(currentStream);
                ans.push_back("Push");
            }

            stream++;
        }

        return ans;
    }
};
