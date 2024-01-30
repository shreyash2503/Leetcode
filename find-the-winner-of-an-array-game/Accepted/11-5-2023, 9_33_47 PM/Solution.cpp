// https://leetcode.com/problems/find-the-winner-of-an-array-game

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size()){
            int _max = *max_element(arr.begin(), arr.end());
            return _max;
        }
        list<int> l;
        for(auto i : arr){
            l.push_back(i);
        }
        int count = 0;
        int track = l.front();

        while(count != k){
            cout << count;
            int first = l.front();
            l.pop_front();
            int second = l.front();
            l.pop_front();
            if(first > second){
                l.push_front(first);
                l.push_back(second);
            } else {
                l.push_front(second);
                l.push_back(first);
            }
            if(track == l.front()){
                count++;
            } else {
                track = l.front();
                count = 1;
            }
        }

        return l.front();
    }
};