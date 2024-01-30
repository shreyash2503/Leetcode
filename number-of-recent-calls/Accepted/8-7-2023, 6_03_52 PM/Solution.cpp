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
        this->counter ++;
        while(q.front() < t - 3000){
            q.pop();
        }
        
        return q.size();
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */