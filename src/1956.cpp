#include<iostream>
#include<vector>
using namespace std;

const unsigned int INF = 2000000000;
unsigned int answer = INF;

unsigned int getMin(unsigned int a, unsigned int b);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int node, edge;
  cin>>node>>edge;

  vector<unsigned int>tmp(node + 1, INF);
  vector<vector<unsigned int>>graph(node + 1, tmp);

  for(int i{0}; i < edge; i++){

    int start, end, cost;
    cin>>start>>end>>cost;

    graph[start][end] = cost;
  }

  for(int i{1}; i < node + 1 ; i++)
    graph[i][i]  = 0;

  for(int i{1}; i < node + 1; i++){

    for(int j{1}; j < node + 1; j ++){

      for(int k{1}; k < node + 1; k++){

      if(j == k)
        continue;

      graph[j][k] = getMin(graph[j][k], graph[j][i] + graph[i][k]);
      

      if(graph[j][k] > INF)
        graph[j][k] = INF;

      if(graph[j][k]  + graph[k][j]< answer)
          answer = graph[j][k] + graph[k][j];
      }
    }
  }
  
  if(answer >= INF){
    cout<<-1<<"\n";
    return 0;
  }

  cout<<answer<<"\n";

  return 0;
}

unsigned int getMin(unsigned int a, unsigned int b){

  if(a > b)
    return b;

  return a;
}