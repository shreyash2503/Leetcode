// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> dq;
        for(const auto &i : nums){
            dq.push_back(i);
        }

        for(const int i : dq){
            cout << i;
        }

        for(int i=0;i<k;i++){
            int ele = dq.back();
            dq.pop_back();
            dq.push_front(ele);
        }
        int size = dq.size();
        for(int i=0;i<size;i++){
            int frontElement = dq.front();
            nums[i] = frontElement;
            dq.pop_front();
        }
 
        
    }
};