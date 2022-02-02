#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>timeArr;
vector<int>parent;

int N, K;
const int INF = 2000000000;

void DFS(int timeNow, queue<int>que);
void move(int num, int parentNow , int timeNow, queue<int>& que);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>K;

  if(N == K){
    cout<<0<<"\n"<<N<<"\n";
    return 0;
  }

  for(int i{0}; i < 100001; i++){
    timeArr.push_back(INF);
    parent.push_back(i);
  }

  timeArr[N] = 0;

  queue<int> que;
  que.push(N);

  DFS(1, que);

  cout<<timeArr[K]<<"\n";

  vector<int>result;
  result.push_back(K);

  int pointer = parent[K];
  result.push_back(pointer);

  while(pointer != N){

    pointer = parent[pointer];
    result.push_back(pointer);
  }

  for(int i{static_cast<int>(result.size()-1)}; i >=0; i--){
    cout<<result[i]<<" ";
  }

  return 0;
}

void DFS(int timeNow, queue<int>que){

  int size = que.size();

  for(int i{0}; i < size; i++){

    int top = que.front();
    que.pop();

    move(top + 1, top, timeNow, que);
    move(top - 1, top, timeNow, que);
    move(top * 2, top, timeNow, que);

    if(top + 1 == K || top - 1 == K || top * 2 == K)
      return;
  }

  if(que.size() == 0)
    return;

   DFS(timeNow + 1, que);
}

void move(int num, int parentNow , int timeNow, queue<int>& que){

   if(num>= 0 && num <= 100000){

     if(timeNow < timeArr[num]){
       timeArr[num] = timeNow;
       parent[num] = parentNow;
       que.push(num);
     }
   }
}