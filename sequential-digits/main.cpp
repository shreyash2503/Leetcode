class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        size_t _low = to_string(low).size();
        size_t _high = to_string(high).size();

        vector<int> ans;

        for(int i = _low;i<_high+1;i++){
            for(int j{1};j<9;j++){
                if(i + j > 10){
                    break;
                }
                int num = j;
                int prev = j;
                for(int k{};k<i-1;k++){
                    num = num * 10;
                    prev += 1;
                    num += prev;

                }
                if(low <= num && num <= high){
                    ans.push_back(num);
                }
            }
        }

        return ans;
        
    }

};
