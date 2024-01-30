// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
       
        if(a.length() != b.length()){
             int diff = a.length() > b.length() ? a.length() - b.length() : b.length() - a.length();
            if(a.length() > b.length()){
                for(int i=0;i<diff;i++){
                b += "0";
                }
                reverse(b.begin(), b.end());
                cout<<b<<endl; 
            } else {
                for(int i=0;i<diff;i++){
                a += "0";
                }
                reverse(a.begin(), a.end());
                cout<<a<<endl;
            }
            
           
        }
        string ans = "";
        for(int i = b.length() - 1;i>=0;i--){
            if(a[i] == '1' && b[i] == '1'){
                if(carry == 1){
                    ans += "1";
                    carry = 1;
                } else {
                    ans += "0";
                    carry = 1;
                    
                }

            } else if((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')){
                if(carry == 1){
                    ans += "0";
                    carry = 1;
                } else {
                    ans += "1";
                    carry = 0;
                }
            } else {
                if(carry == 0){
                    ans += "0";
                    carry = 0;
                } else {
                    ans += "1";
                    carry = 0;
                }
            }

        }
        if(carry == 1){
            ans += "1";
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};