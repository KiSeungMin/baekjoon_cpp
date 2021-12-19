#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, K;
int answer = 0;

void BFS(queue<int>& node, vector<bool>& visited);

int main(){

  cin>>N>>K;

  if(N == K){
    cout<<0<<"\n";
    return 0;
  }

  vector<bool>visited(100001, false);
  visited[N]=true;

  queue<int>node;
  node.push(N);

  BFS(node, visited);

  cout<<answer<<"\n";

  return 0;
}

void BFS(queue<int>& node, vector<bool>& visited){

  answer++;

  int size= node.size();

    for(int i{0}; i < size; i++){

      int start = node.front();
      node.pop();

      if(start - 1 >= 0  && visited[start - 1] == false){

        if(start - 1 == K)
          return;

        visited[start - 1] = true;
        node.push(start - 1);
      }

      if(start + 1 <= 100000 && visited[start + 1] == false){

        if(start + 1 == K)
          return;

        visited[start + 1] = true;
        node.push(start + 1);
      }

      if(start * 2 <= 100000 && visited[start * 2] == false){

        if(start * 2 == K)
          return;

        visited[start * 2] = true;
        node.push(start * 2);
      }
    }

  BFS(node, visited);
}