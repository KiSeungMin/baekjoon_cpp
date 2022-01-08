#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){

  int N, K;
  cin>>N>>K;

  priority_queue<int, vector<int>, greater<int>> pq;

  for(int i{1}; i <= N; i++){

    for(int j{1}; j <= N; j++){

      pq.push(i * j);
    }
  }

  for(int i{K-1}; i > 0; i--){
    pq.pop();
  }

  cout<<pq.top()<<"\n";

  return 0;
}