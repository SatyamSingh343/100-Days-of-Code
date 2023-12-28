class Solution {
public:
    vector<vector<string>> ans;
    int col_mask, diag_mask, anti_diag_mask;

    void print(){
        int i=0;
        for(vector<string>& board: ans){
            cout<<"sol "<<++i<<":\n";
            for(string& row: board)
                cout<<row<<endl;
            cout<<"=======\n";
        }
    }

    void find_sol(int i, int n, vector<string>& board) {
        if (i == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if ((col_mask & (1 << j)) == 0 && 
                (diag_mask & (1 << (i - j + n - 1))) == 0 && 
                (anti_diag_mask & (1 << (i + j))) == 0)
            {
                board[i][j] = 'Q';
                col_mask |= (1 << j);
                diag_mask |= (1 << (i - j + n - 1));
                anti_diag_mask |= (1 << (i + j));

                find_sol(i + 1, n, board);

                board[i][j] = '.';//backtracking

                col_mask &= ~(1 << j);
                diag_mask &= ~(1 << (i - j + n - 1));
                anti_diag_mask &= ~(1 << (i + j));
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        col_mask = diag_mask = anti_diag_mask = 0;
        find_sol(0, n, board);
        //print();
        return ans;
    }
};
