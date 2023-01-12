#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
int answer = 0;

vector<bool>check;
vector<vector<int>>graph;

/* 자식 노드의 개수가 0개가 아닐 경우 인플러언서임(자식이 인플루언서인 경우 자식에서 제외*/

void input();
void getAnswer(int node, int parent);

int main(){

  input();

  return 0;
}

void input(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;

  for(int i{0}; i <= N; i++){
    
    check.push_back(false);

    vector<int>tmp;
    graph.push_back(tmp);
  }

  for(int i{0}; i < N - 1; i++){

    int num1;
    int num2;
    cin>>num1>>num2;

    graph[num1].push_back(num2);
    graph[num2].push_back(num1);
  }

  getAnswer(1, 0);

  cout<<answer<<"\n";
}

void getAnswer(int node, int parent){

  int child = 0;

  for(auto j : graph[node]){
   
    if(j == parent)
      continue;

    getAnswer(j, node);

    if(check[j] == true)
      continue;

    child++;
  }

  if(child == 0)
    return;

  for(auto j : graph[node]){

    if(j == parent)
      continue;

    check[j] = true;
  }

  check[node] = true;

  answer++;
}