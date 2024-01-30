// https://leetcode.com/problems/number-of-recent-calls

class RecentCounter {
public:
    int counter;
    queue<int> q;
    RecentCounter() {
        this->counter = 0;
        
    }
    
    int ping(int t) {
        q.push(t);
        int _low = t - 3000;
        int _high = t;
        int size = q.size();
        int count = 0;
        this->counter ++;
        for(int i=0;i<size;i++){
            int front = q.front();
            q.pop();
            q.push(front);
            if(front >= _low && front <= _high){
                count ++;
            }
        }
        cout<<count;
        return count;
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */