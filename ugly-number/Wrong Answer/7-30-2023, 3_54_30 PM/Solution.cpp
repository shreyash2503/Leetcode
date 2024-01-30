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
        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        for(int i=5;i<n;i++){
            if(n % i == 0 && isPrime(i)){
                v.push_back(i);
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        return v.size() == 3 ? true : false;
    }
};