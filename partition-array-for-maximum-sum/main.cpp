class Solution {
public:
    unordered_map<int, int> map;

    int dfs(vector<int> &arr, int index, int k){
        if(map.find(index) != map.end()){
            return map[index];
        }
        int res {};
        int curr_max {};
        size_t size = arr.size();
        for(int i{index}; i<min<size_t>(size, index + k);i++){
            curr_max = max(curr_max, arr[i]);
            int curr_window = i - index + 1;
            res = max(res, dfs(arr, i + 1, k) + curr_window * curr_max);
        }
        map[index] = res;

        return res;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return dfs(arr, 0, k);
        
    }
};
