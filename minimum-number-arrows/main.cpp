class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        auto prev = points[0];
        size_t size = points.size();
        int arrows {};

        for(int i{};i<size;i++){
            auto& current = points[i];
            if(current[0] > prev[1]){
                arrows ++;
                prev = current;
            } else {
                prev[1] = min(prev[1], current[1]);
            }
        }
        arrows ++;
        return arrows;
    }
};
