#include<iostream>
#include<vector>
using namespace std;


int lcs(string s1, string s2);

int main(){
  string str1, str2;
  cout<<"Enter a substr1: ";
  getline(cin, str1);

  cout<<"Enter a substr2: ";
  getline(cin, str2);

  cout<<"The Longest common Substring is : "<<lcs(str1, str2);
  return 0;
}

int lcs(string s1, string s2){
  int n = s1.size();
  int m = s2.size();

  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  for(int i= 1; i<=n; i++){
    for(int j= 1; j<=m; j++){
      int take = 0, notTake = 0;
      if(s1[i-1] == s2[j-1]) take = 1 + dp[i-1][j-1];
      else notTake = max(dp[i][j-1], dp[i-1][j]);

      dp[i][j] = max(take, notTake);
    }
  }

  return dp[n][m];
}