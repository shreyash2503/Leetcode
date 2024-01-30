class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;

        for(auto num : tokens){
            if(num == "+" || num == "-" || num == "*" || num == "/"){
                auto top1 = s.top(); s.pop();
                auto top2 = s.top(); s.pop();
                if(num == "+"){
                    s.push(top2 + top1);
                }
                if(num == "-"){
                    s.push(top2 - top1);
                }
                if(num == "*"){
                    s.push(top2 * top1);
                }
                if(num == "/"){
                    s.push(top2 / top1);
                }

            } else {
                s.push(stoi(num));
            }
        }
        
        return s.top();
    }
};
