#include<iostream>
#include<vector>
using namespace std;

void solve(int rowNo, vector<vector<char>>& board, vector<vector<vector<char>>>& ans, vector<int>& chkRow, vector<int>& chkPD, vector<int>& chkND);

int main(){
  int n;

  cout<<"Enter Board Size: ";
  cin>>n;

  vector<vector<char>> board(n, vector<char>(n, '.'));
  vector<vector<vector<char>>> ans;

  vector<int> chkRow(n, 0);
  vector<int> chkPD(2* n-1, 0);
  vector<int> chkND(2* n-1, 0);

  solve(0, board, ans, chkRow, chkPD, chkND);

  for(vector<vector<char>> b : ans){
    for(vector<char> row: b){
      for(char block : row){
        cout<<block<<" ";
      }
      cout<<'\n';
    }
    cout<<"-----------------------------------"<<endl;
  }
}

void solve(int rowNo, vector<vector<char>>& board, vector<vector<vector<char>>>& ans, vector<int>& chkRow, vector<int>& chkPD, vector<int>& chkND){
  if(rowNo == board.size()){
    ans.push_back(board);
    return;
  }

  for(int col = 0; col < board.size(); col++){
    if(chkRow[col] == 0 && chkPD[rowNo+col] == 0 && chkND[rowNo-col+board.size()-1] == 0){
      chkRow[col] = chkPD[rowNo+col] = chkND[rowNo-col+board.size()-1] = 1;
      board[rowNo][col] = 'Q';

      solve(rowNo+1, board, ans, chkRow, chkPD, chkND);

      chkRow[col] = chkPD[rowNo+col] = chkND[rowNo-col+board.size()-1] = 0;
      board[rowNo][col] = '.';
    }
  }
}
