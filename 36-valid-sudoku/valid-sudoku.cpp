class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     vector<long int> row(9,0);
     vector<long int> col(9,0);
     vector<long int> grid(9,0);

     for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            if(board[i][j]!='.'){
            int gi = (i/3)*3+(j/3);
            long int no = (long int)1<<(board[i][j]-'0');
            if(row[i]&no) {
                cout<<i<<" "<<board[i][j]<<" "<<row[i]<<" "<<no<<"\n";
                return false;
            }
            if(col[j]&no) {
                 cout<<j<<" "<<col[j]<<" "<<no<<"\n";
                return false;
            }
            if(grid[gi]&no) {
                 cout<<gi<<" "<<grid[gi]<<" "<<no<<"\n";
                return false;
            }

            row[i]=row[i]+no;
            col[j] = col[j]+no;
            grid[gi] = grid[gi]+no;
            }
        }
     }
     return true;
    }
};