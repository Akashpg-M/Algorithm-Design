#include<iostream>
#include<vector>
#include<climits>

using namespace std;


vector<int> bellmanFord(vector<vector<int>> graph, bool& flag);

int main(){
  vector<vector<int>> graph ={
                              {  0,   4,   INT_MAX, 6 },  
                              { INT_MAX, 0,   3,   INT_MAX }, 
                              { INT_MAX, INT_MAX, 0,   1 }, 
                              { INT_MAX, -2,  INT_MAX, 0 }
                            };


  bool flag = false;

  vector<int> result = bellmanFord(graph, flag);

  if(flag) cout<<"Negetive cycle is present";
  else{
    cout<<"Shortest DIST from Src : 0"<<endl;
    for(int i=0; i<result.size(); i++){
      if(result[i] == INT_MAX) cout<<"Node "<<i<<" : "<<"No path"<<endl;
      else cout<<"Node "<<i<<" : "<<result[i]<<endl;
    }

    return 0;
  }
  
}


vector<int> bellmanFord(vector<vector<int>> graph, bool& flag){
  vector<int> d(graph[0].size(), INT_MAX);
  d[0] = 0;

  for(int rep=0; rep<graph.size()-1; rep++){
    for(int i=0; i<graph.size(); i++){
      for(int j=0; j<graph.size(); j++){
        if(d[i] != INT_MAX && graph[i][j] != INT_MAX && d[i] + graph[i][j] < d[j]) d[j] = d[i] + graph[i][j];
      }
    }
  }

  for(int i=0; i<graph.size(); i++){
    for(int j=0; j<graph.size(); j++){
      if(d[i] != INT_MAX && graph[i][j] != INT_MAX && d[i] + graph[i][j] < d[j]) flag = true;
    }
  }

  return d;
}
