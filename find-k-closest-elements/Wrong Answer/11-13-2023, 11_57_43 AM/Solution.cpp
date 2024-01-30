// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto number : arr){
            pq.push({abs(number - x), number});
        }

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second); pq.pop();
        }

        return ans;
        
    }
};