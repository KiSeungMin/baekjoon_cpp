#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int V, E;

vector<int>parent;
vector<int>dist;
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

void init();
void getAnswer();

int main(){

  init();

  return 0;
}

void init(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(!pq.empty())
    pq.pop();

  cin>>V>>E;

  for(int i{0}; i<=V; i++){
    parent.push_back(-1);
    dist.push_back(0);
  }

  for(int i{0}; i < E; i++){

    vector<int>tmp;

    int num1, num2, dis;
    cin>>num1>>num2>>dis;

    tmp.push_back(dis);
    tmp.push_back(num1);
    tmp.push_back(num2);

    pq.push(tmp);
  }

  while(!pq.empty())
    getAnswer();

  int pointer = 1;

  while(parent[pointer] != pointer)
    pointer = parent[pointer];

  cout<<dist[pointer]<<"\n";
}

void getAnswer(){

  vector<int> vec  = pq.top();
  pq.pop();

  int dis = vec[0];
  int num1 = vec[1];
  int num2 = vec[2];

  int pointer1 = num1;
  int pointer2 = num2;

  if(parent[num1] == -1)
    pointer1 = -1;

  else{
    while(parent[pointer1] != pointer1)
      pointer1 = parent[pointer1];
  }

  if(parent[num2] == -1)
    pointer2 = -1;

  else{
    while(parent[pointer2] != pointer2)
      pointer2 = parent[pointer2];
  }

  if(pointer1 == -1 && pointer2 == -1){
    parent[num1] = num1;
    parent[num2] = num1;

    dist[num1] = dis;
    return;
  }

  else if(pointer1 != -1 && pointer2 == -1){
    parent[num2] = pointer1;

    dist[pointer1] += dis;
    return;
  }

  else if(pointer1 == -1 && pointer2 != -1){
    parent[num1] = pointer2;

    dist[pointer2] += dis;
    return;
  }
  
  else if(pointer1 == pointer2)
    return;

  else{
    parent[pointer2] = pointer1;

    dist[pointer1] += dist[pointer2];
    dist[pointer1] += dis;
    return;
  }
}