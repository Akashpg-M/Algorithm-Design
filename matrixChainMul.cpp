#include<iostream>
#include<vector>
using namespace std;

int MinMatrixOper(vector<int>& mDim, int s, int e){
  if(s == e) return 0;

  int res = INT_MAX;
  for(int i=s; i<e; i++){
    res = min(res, MinMatrixOper(mDim, s,i) + MinMatrixOper(mDim, i+1, e) + mDim[s-1]*mDim[i]*mDim[e]);
  }

  return res;
}

int main(){
  int n;
  cout<<"Enter no of Matrix: ";
  cin>>n;
  vector<int> mDim(n+1);
  for(int i=1; i<n+1; i++){
    cout<<"Enter val: ";
    cin>>mDim[i];
  }

  cout<<"Minimum operations needed to multiply matrix : "<<MinMatrixOper(mDim, 1, n-1);
}