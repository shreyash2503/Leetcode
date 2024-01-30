// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

class Solution {
public:
    static bool sorter(int &a, int &b){
        bitset<sizeof(int) * 8> number1(a);
        bitset<sizeof(int) * 8> number2(b);
        string s1 = number1.to_string();
        string s2 = number2.to_string();
        int c1 = count(s1.begin(), s1.end(), '1');
        int c2 = count(s2.begin(), s2.end(), '1');
        if(c1 < c2){
            return true;
        } else if(c1 == c2){
            if(a > b){
                return false;
            } else {
                return true;
            }
        }

        return false;

    }
    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), sorter);

        return arr;
        
    }
};