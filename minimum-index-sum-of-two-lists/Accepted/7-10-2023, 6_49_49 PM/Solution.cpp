// https://leetcode.com/problems/minimum-index-sum-of-two-lists

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int maxSize = max(list1.size(), list2.size());
        vector<int> temp(maxSize, INT_MAX);
        vector<string> ans;

        if(list1.size() > list2.size()){
            for(int i=0;i<list1.size();i++){
               for(int j=0;j<list2.size();j++){
                   if(list1[i] == list2[j]){
                       temp[i] = i + j;
                       
                   }
               } 
            }
            int minElement = *min_element(temp.begin(), temp.end());
            for(int i=0;i<list1.size();i++){
                if(temp[i] == minElement){
                    ans.push_back(list1[i]);
                }
            }


        } else {
            for(int i=0;i<list2.size();i++){
                for(int j=0;j<list1.size();j++){
                    if(list2[i] == list1[j]){
                        temp[i] = i + j;
                    }

                }
            }
            int minElement = *min_element(temp.begin(), temp.end());
            for(int i=0;i<list2.size();i++){
                if(temp[i] == minElement){
                    ans.push_back(list2[i]);
                }
            }

           
        }
        return ans;

        

        
    }
};