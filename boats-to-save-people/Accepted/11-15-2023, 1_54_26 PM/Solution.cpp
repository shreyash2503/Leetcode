// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       sort(begin(people),end(people));
        int n=people.size();

        int j=n-1;
        int i=0;
        int ans=0;
        
        while(i<j){
            if(people[i]+people[j]<=limit){
                ans++;
                j--;
                i++;
            }else{
                ans++;
                j--;
            }
        }
        if(i==j)ans++;
        return ans;
        
    }

};