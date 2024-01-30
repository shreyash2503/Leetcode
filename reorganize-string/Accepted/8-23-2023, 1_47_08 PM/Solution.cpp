// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> map;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = 1;
            } else {
                map[s[i]]++;
            }
        }
        priority_queue<pair<int, char>> max_heap;
        for(auto &[ch, freq] : map){
            max_heap.push({freq, ch});
        }

        string res;
        while(max_heap.size() >= 2) {
            auto [freq1, ch1] = max_heap.top();
            max_heap.pop();
            auto [freq2, ch2] = max_heap.top();
            max_heap.pop();

            res += ch1;
            res += ch2;
            if(--freq1 > 0) max_heap.push({freq1, ch1});
            if(--freq2 > 0) max_heap.push({freq2, ch2});
        }

        if(!max_heap.empty()){
            auto [freq, ch] = max_heap.top();
            if(freq > 1) return "";
            res += ch;
        }
        return res;
        
        
    }
};