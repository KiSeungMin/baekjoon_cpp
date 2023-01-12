#include<iostream>
#include<vector>
using namespace std;

vector<int>parent;
vector<vector<int>>adj;
vector<bool>check;

void DFS(int parentNode);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin>>N;

  for(int i{0}; i < N + 1; i++){
    parent.push_back(i);

    vector<int>tmp;
    adj.push_back(tmp);

    check.push_back(false);
  }

  for(int i{0}; i < N - 1; i++){
    
    int num1, num2;
    cin>>num1>>num2;

    adj[num1].push_back(num2);
    adj[num2].push_back(num1);
  }

  check[1] = true;
  DFS(1);

  for(int i{2}; i <= N; i++)
    cout<<parent[i]<<"\n";

  return 0;
}

void DFS(int parentNode){

  for(auto j : adj[parentNode]){

    if(check[j])
      continue;

    else{
      parent[j] = parentNode;
      check[j] = true;
      DFS(j);
    }
  }
}