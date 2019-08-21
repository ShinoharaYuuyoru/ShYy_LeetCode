class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> visitedCol(9, vector<bool>(9, false));
        vector<vector<bool>> visitedRow(9, vector<bool>(9, false));
        vector<vector<bool>> visitedBox(9, vector<bool>(9, false));
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    continue;
                }
                
                int num=board[i][j]-'1';
                int boxIdx=i/3*3+j/3;
                
                if(visitedCol[i][num]==true||visitedRow[j][num]==true||visitedBox[boxIdx][num]==true)
                {
                    return false;
                }
                else
                {
                    visitedCol[i][num]=true;
                    visitedRow[j][num]=true;
                    visitedBox[boxIdx][num]=true;
                }
            }
        }
        
        return true;
    }
};