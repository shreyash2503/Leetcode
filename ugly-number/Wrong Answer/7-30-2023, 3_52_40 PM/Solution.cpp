// https://leetcode.com/problems/ugly-number

class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i<n;i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    bool isUgly(int n) {
        vector<int> v;
        for(int i=2;i<n;i++){
            if(n % i == 0 && isPrime(i)){
                v.push_back(i);
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        return v.size() <= 3 ? true : false;
    }
};