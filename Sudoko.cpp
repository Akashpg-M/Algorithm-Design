#include<iostream>
#include<vector>
#include<climits>

using namespace std;

bool solveSudoko(int row, int col, vector<vector<vector<int>>>& ans, vector<vector<int>>& board);
bool isValid(vector<vector<int>>& board, int row, int col, int num);

int main(){
  vector<vector<int>> board;

  vector<vector<vector<int>>> ans;

  solveSudoko(0, 0, ans, board);

  for(vector<vector<int>> board: ans){
    for(vector<int> row : board){
      for(int block : row){
        if(block == INT_MAX) cout<<".";
        else cout<<block;
      }
      cout<<endl;
    }
    cout<<"--------------------------------------------";
  }
  return 0;
}

bool solveSudoko(int row, int col, vector<vector<vector<int>>>& ans, vector<vector<int>>& board){
    if(row == 9) ans.push_back(board);
    if(col == 9) solveSudoko(row + 1, 0, ans, board);

    if(board[row][col] == INT_MAX){
      for(int n=1; n<=9; n++){
        if(isValid(board, row, col, n)){
          board[row][col] = n;
          if(solveSudoko(row, col+1, ans, board));
          board[row][col] = INT_MAX;
        }
      }
    }else{
      solveSudoko(row, col+1, ans, board);
    }
}

bool isValid(vector<vector<int>>& board, int row, int col, int num){
  for(int i=0; i<9; i++){
    if(board[row][i] == num) return false;
    if(board[i][col] == num)  return false;
    if(board[row - row%3 + i%3][col - col%3 + i/3] == num) return false;

    return true;
  }
}
