// https://leetcode.com/problems/course-schedule

class Solution {
public:
  void createIndegree(vector<vector<int>>& v, unordered_map<int, int>& map, int numCourses) {
    for (int i = 0; i < numCourses; i++) {
        map[i] = 0;
    }
    for (const auto& prerequisites : v) {
        for (const auto& prerequisite : prerequisites) {
            map[prerequisite]++;
        }
    }
}
    void addEdge(vector<vector<int>>& list, int u, int v){
        list[u].push_back(v);
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> map;
        queue<int> q;
        bool dec = false;
        int size = prerequisites.size();
        vector<vector<int>> list(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            addEdge(list, prerequisites[i][1], prerequisites[i][0]);
        }
        createIndegree(list, map, numCourses);
        for(const auto& pair : map){
            if(pair.second == 0){
                q.push(pair.first);
                dec = true;
            }
        }
        if (dec == false) return false;
      
        

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int i=0;i<list[front].size();i++){
                map[list[front][i]] = map[list[front][i]] - 1;
                if(map[list[front][i]] == 0){
                    q.push(list[front][i]);
                }
            }

        }
        for(const auto& pair : map){
            cout<<pair.first<<"->"<<pair.second<<endl;
        }

        return all_of(map.begin(), map.end(), [](const auto& pair) {return pair.second == 0; });

    }
};