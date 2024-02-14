class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        size_t size = nums.size();
        int pos = 0;
        int neg = 1;
        vector<int> v(size, 0);
        for(auto &i : nums){
            if(i > 0){
                v[pos] = i;
                pos += 2;
            } else {
                v[neg] = i;
                neg += 2;
            }
        }

        return v;
    }
};;:
