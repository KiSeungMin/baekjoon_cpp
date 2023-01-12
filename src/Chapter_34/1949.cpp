#include<iostream>
#include<vector>
using namespace std;

/*
두 개의 값을 이용 : {현재 값을 포함할 경우에 최댓값 = 1번값, 현재 값을 포함하지 않을 경우에 최댓값 = 2번값}

현재 값을 포함할 경우 : max(sum(자식 노드의 두번째값), sum(max(손자 노드의 첫 번째 값, 손자 노드의 두 번째 값)))

현재 값을 포함하지 않을 경우 : sum(max(자식 노드의 첫 번째값, 자식 노드의 두 번째값)) 단, 모두 두 번째값을 선택하는 경우는 제외

*/

int N;
int answer = 0;

vector<int>cost;
vector<pair<int, int>>costNow;
vector<vector<int>>graph;

void input();
void getAnswer(int node, int parent);
int getMax(int a, int b);

int main(){

  input();

  return 0;
}

void input(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;

  for(int i{0}; i<=N; i++){
    vector<int>tmp;
    graph.push_back(tmp);

    pair<int, int> tmp2 = {0, 0};
    costNow.push_back(tmp2);
  }

  cost.push_back(0);
  for(int i{0}; i < N; i++){

    int num;
    cin>>num;

    cost.push_back(num);
  }

  for(int i{0}; i < N - 1; i++){

    int num1, num2;
    cin>>num1>>num2;

    graph[num1].push_back(num2);
    graph[num2].push_back(num1);
  }

  getAnswer(1, 0);

  /*
  for(int i{1}; i <= N; i++){
    cout<<i<<" "<<costNow[i].first<<" "<<costNow[i].second<<"\n";
  }
  */

  cout<<answer<<"\n";
}

void getAnswer(int node, int parent){

  int res1 = cost[node];
  int res2 = 0;

  for(auto j : graph[node]){

    if(j == parent)
      continue;
    
    else  
      getAnswer(j, node);
  }

  for(auto j : graph[node]){

    if(j == parent)
      continue;

    else
      res1 += costNow[j].second;
  }

  int tmp = cost[node]; 

  for(auto j : graph[node]){

    if(j == parent)
      continue;

    for(auto k : graph[j]){

      if(k == node)
        continue;

      tmp += getMax(costNow[k].first, costNow[k].second);
    }
  }

  if(tmp > res1)
    res1 = tmp;

  for(int i{0}; i < graph[node].size(); i++){

    if(graph[node][i] == parent)
      continue;

    int tmp =  costNow[graph[node][i]].first;

    for(int j{0}; j < graph[node].size(); j++){

      if(j == i || graph[node][j] == parent)
        continue;

      else
        tmp += getMax(costNow[graph[node][j]].first, costNow[graph[node][j]].second);
    } 

    if(tmp > res2)
      res2 = tmp;  
  }

  costNow[node].first = res1;
  costNow[node].second = res2;

  if(res1 > answer)
    answer = res1;

  if(res2 > answer)
    answer = res2;
}

int getMax(int a, int b){
  
  if(a > b)
    return a;

  return b;
}