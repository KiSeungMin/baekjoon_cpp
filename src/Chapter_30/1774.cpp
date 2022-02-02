#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int N, M;

vector<int>parent;
vector<long double>dist;
vector<pair<long long , long long>>graph;

priority_queue<pair<long double, pair<long long, long long>>, vector<pair<long double, pair<long long, long long>>>, greater<pair<long double, pair<long long, long long>>>>pq;

void getAnswer();

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;
  cin>>M;

  pair<long long, long long> tmptmp = {-1, -1};
  graph.push_back(tmptmp);

  for(int i{0}; i < N; i++){
    long long num1, num2;
    cin>>num1>>num2;

    pair<long long, long long> tmp = {num1, num2};
    graph.push_back(tmp);

    parent.push_back(-1);
    dist.push_back(0.00);
  }

  parent.push_back(-1);
  dist.push_back(0.00);


  for(int j{0}; j < M; j++){
    long long num1, num2;
    cin>>num1>>num2;

    pair<long double, pair<long long, long long>>tmp = {0, {num1, num2}};
    pq.push(tmp);
  }

  for(int i{1}; i <= N; i++){

    for(int j{i + 1}; j <= N; j++){

      long long x1 = graph[i].first;
      long long y1 = graph[i].second;

      long long x2 = graph[j].first;
      long long y2 = graph[j].second;
    
      long double dis = static_cast<long double>(sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2)));

      pair<long double, pair<long long, long long>>tmp = {dis, {i, j}};

      pq.push(tmp);
    }
  }

  while(!pq.empty())
    getAnswer();

  int pointer = 1;
  while(parent[pointer] != pointer)
    pointer = parent[pointer];

  long double answer = dist[pointer];

  answer =answer * 100;
  answer = round(answer);
  answer = answer / 100;
  
  cout<<fixed;
  cout.precision(2);
  cout<<answer<<"\n";

  return 0;
}

void getAnswer(){

  pair<long double, pair<long long , long long>>vec = pq.top();
  pq.pop();

  long double dis = vec.first;
  long long num1 = vec.second.first;
  long long num2 = vec.second.second;

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
    parent[num2] =  num1;

    dist[num1] += dis;
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