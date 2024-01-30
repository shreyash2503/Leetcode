// https://leetcode.com/problems/minimum-speed-to-arrive-on-time

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(dist.size() > ceil(hour)){
            return -1;
        }
        int start = 1;
        int end = 1e7;
        int min = 0;
        while(start <= end){
            int mid = start + (end - start) / 2;
            double count = 0;
            for(int i=0;i<dist.size();i++){
                double temp = dist[i] * 1.0 / mid;
                if(i != dist.size() - 1){
                    count = count + ceil(temp);
                } else {
                    count = count + temp;
                }
            }
            if(count > hour){
                start = mid + 1;
            } else {
                min = mid;
                end = mid - 1;
            }
        }

        return min;
        
    }
};