#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const long long INF =999999999999;

int N, M;
int start , goal;
vector<long long>dist;
vector<long long>parent;
vector<vector<vector<long long>>>graph;
priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long  long>>> que;

void getAnswer();

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;

  for(int i{0}; i < N + 1; i++){
    vector<vector<long long>>tmp;
    graph.push_back(tmp);

    dist.push_back(INF);
    parent.push_back(i);
  }

  for(int i{0}; i < M; i++){
    long long start, goal, dis;
    cin>>start>>goal>>dis;
    vector<long long> tmp= {dis, start, goal};

    graph[start].push_back(tmp);
  }

  cin>>start>>goal;

  dist[start] = 0;

  for(auto j : graph[start])
    que.push(j);

  getAnswer();

  cout<<dist[goal]<<"\n";

  vector<int>result;

  result.push_back(goal);
  int pointer = goal;

  while(true){

    if(pointer == start)
      break;

    pointer = parent[pointer];
    result.push_back(pointer);
  }

  cout<<result.size()<<"\n";

  for(int i{static_cast<int>(result.size()-1)}; i >=0; i--){
    cout<<result[i]<<" ";
  }

  cout<<"\n";

  return 0;
}

void getAnswer(){

  int size = que.size();

  for(int i{0}; i < size; i++){

    vector<long long>arr = que.top();
    que.pop();

    long long dis = arr[0];
    long long startNow = arr[1];
    long long goalNow = arr[2];

    if(dis + dist[startNow] < dist[goalNow]){

      dist[goalNow] = dis + dist[startNow];
      parent[goalNow] = startNow;

      for(auto j : graph[goalNow])
         que.push(j);
    }
  }

  if(que.size() == 0)
    return;

  getAnswer();

  return;
}