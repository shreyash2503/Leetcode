class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        size_t size = heights.size();
        int i {};
        priority_queue<int> pq;

        for(i=0;i<size - 1;i++){
            int diff = heights[i + 1] - heights[i];

            if(diff <= 0){
                continue;
            }
            bricks -= diff;
            pq.push(diff);
            if(bricks < 0){
                ladders --;
                bricks += pq.top();
                pq.pop();
            }
            if(ladders < 0){
                break;
            }

        }

        return i;

        
    }
};
