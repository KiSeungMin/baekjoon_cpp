#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int N;

vector<int>parent;
vector<double>dist;
vector<pair<double, double>>node;
priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> pq;

void getAnswer();

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout<<fixed;
  cout.precision(2);

  cin>>N;

  for(int i{0}; i < N; i++){
    
    parent.push_back(-1);
    dist.push_back(0.00);

    double f1, f2;
    cin>>f1>>f2;

    pair<double, double> tmp = {f1, f2};
    node.push_back(tmp);
  }

  for(int i{0}; i < N; i++){

    for(int j{i + 1}; j < N; j ++){

      vector<double>tmp;

      double x1 = node[i].first;
      double y1 = node[i].second;
      double x2 = node[j].first;
      double y2 = node[j].second;

      double dis = sqrt(abs(x1 - x2) * abs(x1- x2) + abs(y1 - y2) * abs(y1 - y2));
   
      tmp.push_back(dis);
      tmp.push_back(i);
      tmp.push_back(j);

      pq.push(tmp);
    }
  }

  while(!pq.empty())
    getAnswer();

  int pointer = 0;
  while(pointer != parent[pointer])
    pointer = parent[pointer];

  cout<<dist[pointer]<<"\n";

  return 0;
}

void getAnswer(){

  vector<double> vec = pq.top();
  pq.pop();

  double dis = vec[0];
  double num1 = vec[1];
  double num2 = vec[2];

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