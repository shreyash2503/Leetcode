// https://leetcode.com/problems/n-queens

class Solution {
public:

    void backtrack(int r, int n, set<int>& col, set<int>& posDia, set<int>& negDia, vector<string>& board, vector<vector<string>>& ans){
            if(r == n){
                ans.push_back(board);
                return;
            }
            for(int c=0;c<n;c++){
                if(col.find(c) != col.end() || posDia.find(r + c) != posDia.end() || negDia.find(r - c) != negDia.end()){
                    continue;
                }
                col.insert(c);
                posDia.insert(r + c);
                negDia.insert(r - c);
                board[r][c] = 'Q';

                backtrack(r + 1, n, col, posDia, negDia, board, ans);

                col.erase(c);
                posDia.erase(r + c);
                negDia.erase(r - c);
                board[r][c] = '.';
            }
        }

    vector<vector<string>> solveNQueens(int n) {
        set<int> col;
        set<int> posDia;
        set<int> negDia;
        string s(n, '.');

        vector<vector<string>> ans;
        vector<string> board;
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        backtrack(0, n, col, posDia, negDia, board, ans);

        return ans;


        
    }
};
