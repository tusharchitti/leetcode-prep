class Solution {
public:

    bool doesWordExist(vector<vector<char>>& board, string word, 
    vector<vector<int>> &visit , 
    int x, int y , int check)
    {
        //cout<<x<<" "<<y<<endl;
        if( x<0 || y<0 || x >= board.size() || y >= board[0].size() || visit[x][y] ==1)
        {
           return false;
        }

        if(board[x][y] == word[check] && check == word.length()-1)
        {
            return true;
        }
        if(board[x][y] != word[check]) return false;
        visit[x][y]  = 1;
        bool ans = false;
        ans = ans || doesWordExist(board, word, visit, x-1, y , check+1) ||
        doesWordExist(board, word, visit, x, y-1 , check+1) ||
        doesWordExist(board, word, visit, x+1, y , check+1)||
        doesWordExist(board, word, visit, x, y+1 , check+1);
        visit[x][y] = 0;
        return ans;

    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<int>> visit(board.size() , vector<int>(board[0].size() , 0));
                    if(doesWordExist(board, word, visit,i,j,0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};