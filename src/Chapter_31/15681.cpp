#include<iostream>
#include<vector>
using namespace std;

int N, root, M;

vector<int>child;
vector<vector<int>>graph;

void input();
void DFS(int nodeNow, int parent);

int main(){

  input();

  return 0;
}

void input(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>root>>M;

  for(int i{0}; i < N + 1; i++){
    vector<int>tmp;
    graph.push_back(tmp);

    child.push_back(1);
  }

  for(int i{0}; i < N - 1; i++){

    int num1, num2;
    cin>>num1>>num2;
  
    graph[num1].push_back(num2);
    graph[num2].push_back(num1);
  }

  DFS(root, 0);

  for(int i{0}; i < M; i++){
    int num;
    cin>>num;

    cout<<child[num]<<"\n";
  }
}

void DFS(int node, int parent){

  for(auto j : graph[node]){

    if(j == parent)
      continue;

    else{
      DFS(j, node);
      child[node] += child[j];
    }
  }
}