#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;

vector<int>dist;    // 각각의 요소에서 최대 가중치를 저장하는 배열
vector<vector<int>>element;   // 해당 요소에서 최대 가중치를 가질 때, 관련 요소들을 저장하는 배열
vector<vector<int>>graph;   // 인접한 요소들을 저장하는 배열

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

  dist.push_back(0);
  for(int i{0}; i < N; i++){
    int num;
    cin>>num;

    dist.push_back(num);
  }

  for(int i{0}; i <= N; i++){
    vector<int>tmp;
    graph.push_back(tmp);
    element.push_back(tmp);
  }

  for(int i{0}; i < N - 1; i++){
    int num1, num2;
    cin>>num1>>num2;

    graph[num1].push_back(num2);
    graph[num2].push_back(num1);
  }

  getAnswer(1, 0);

  int answer = 0;
  vector<int>answerArr = {};

  for(int i{1}; i <=N; i++){

    if(dist[i] > answer){
      answer = dist[i];
      answerArr = element[i];
    }
  }

  /*
  for(int i{1}; i <=N; i++){
    for (auto j : element[i])
      cout<<j<<" ";
    cout<<"\n";
  }
  */

  cout<<answer<<"\n";

  sort(answerArr.begin(), answerArr.end());

  for(auto j : answerArr)
    cout<<j<<" ";

  cout<<"\n";
}

void getAnswer(int node, int parent){

  int res1 = 0;   // 자식들만 더한 값
  int res2 = dist[node];    // 손자들과 현재 노드를 더한 값

  vector<int>arr1;    // 자식들만 담겨져 있는 노드
  vector<int>arr2 = {node};    // 손자들과 현재 노드가 담겨져 있는 노드

  for(auto i : graph[node]){

    if(i == parent)
      continue;

    else
      getAnswer(i, node);  // 모든 자식 요소들에 재귀적으로 수행(가장 자식 노드부터)
  }

  for(auto i : graph[node]){

    if(i == parent)
      continue;

    else{

      res1 += dist[i];
      for(auto j : element[i])    // 자식 요소들의 element요소를 현재 element 요소에 추가
        arr1.push_back(j);

      for(auto j : graph[i]){

        if(j == node)
          continue;

        else{
          res2 += dist[j];
          for(auto k : element[j])    // 손자 요소들의 element요소를 현재 element 요소에 추가
            arr2.push_back(k);
        }
      }
    }
  }

  if(res1 >= res2){
    dist[node] = res1;
    element[node] = arr1;
  }

  else{
    dist[node] = res2;
    element[node] = arr2;
  }
}