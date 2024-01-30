// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points

class Solution {
public:
 Solution(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>ans;
        int m=points[0].size();
        for(int i=0;i<n;i++){
            ans.push_back(points[i][0]);
        }
        sort(ans.begin(),ans.end());
        int min=0;
        for(int i=1;i<ans.size();i++){
            min=max(ans[i]-ans[i-1],min);
        }
        return  min;
    }
};