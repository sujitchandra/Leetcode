class Solution {
public:
    bool helper (vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i=0; i<9; i++){
            if(board[i][col] == c)
            {
                return false;
            }
            if(board[row][i] == c){
                return false;
            }
            
        }
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(board[3*(row/3) + i][3*(col/3) + j] == c){
                return false;
                }
            }
            
        }   
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] != '.' ){
                    char c = board[i][j];
                    board[i][j] = '.';
                    if(helper(board,i,j,c) == false) return false;
                    board[i][j] = c;
                } 
            }
        }
        return true;
    }
};