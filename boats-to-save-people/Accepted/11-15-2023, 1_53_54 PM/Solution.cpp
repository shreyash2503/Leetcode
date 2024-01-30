// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i = 0;
        int j = people.size() - 1;
        int count = 0;
        sort(people.begin(), people.end());
        while(i <= j){
           cout << i << endl;
           cout << j;
            
            if(people[i] + people[j] <= limit){
                i ++; j--;
            
            } else {
                j --;
            }
            count ++;
        }
        cout << count;
        return count;
        
    }

};