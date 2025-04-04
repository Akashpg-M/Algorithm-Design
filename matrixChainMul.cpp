#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int MinMatrixOper(vector<int>& mDim);

int main(){
  int n;
  cout<<"Enter no of Matrix: ";
  cin>>n;
  vector<int> mDim(n+1);
  for(int i=0; i<n+1; i++){
    cout<<"Enter val: ";
    cin>>mDim[i];
  }

  cout<<"Minimum operations needed to multiply matrix : "<<MinMatrixOper(mDim);
}

int MinMatrixOper(vector<int>& mDim){
  int n = mDim.size()-1;
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

  for(int len = 2; len<=n; len++){
    for(int i=1; i<=n-len+1; i++){
      int j=i+len-1;
      dp[i][j] = INT_MAX;

      for(int k=i; k<j; k++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + mDim[i-1]*mDim[k]*mDim[j]);
      }
    }
  }

  return dp[1][n];
}