#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int N, M;
int island = 0;
const int INF = 2000000000;


vector<vector<bool>>check;    // 이미 특정 섬에 포함되어 있는지 체크
vector<vector<int>>arr;   // 입력값 저장하는 배열
vector<vector<pair<int, int>>>graph;    // 각 섬들을 구성하는 좌표들 저장
vector<vector<int>>dist;    // 섬과 섬 사이의 최소 거리를 2차원 배열로 저장
vector<int>parent;   // 크루스칼 알고리즘 사용을 위해 parent배열 선언 

int counter = 0;    // counter 가 N - 1일 경우 완성 가능, 아닐 경우 완성 불가능
int answer = 0;   // 최소 거리

priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

void init();
void getAnswer();
void BFS(int row, int col);
void getDistance();

int main(){

  init();

  return 0;
}

void init(){

  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin>>N>>M;

  for(int i{0}; i < N; i++){

    vector<int>tmp;
    vector<bool>tmp2;
    for(int j{0}; j < M; j++){
      
      int num;
      cin>>num;
      tmp.push_back(num);
      tmp2.push_back(false);
    }

    arr.push_back(tmp);
    check.push_back(tmp2);
  }

  for(int i{0}; i < N; i++){

    for(int j{0}; j < M; j++){

      if(check[i][j] || arr[i][j] == 0)
        continue;
       
      else{

        vector<pair<int, int>>tmp;
        tmp.push_back({i, j});
        check[i][j] = true;
        graph.push_back(tmp);

        BFS(i, j);
        island++;
      }
    }
  }

  getAnswer();
}

void getAnswer(){

  for(int i{0}; i < island; i++){
    vector<int>tmp(island, INF);
    dist.push_back(tmp);
  }

  // 섬의 각 요소들과 다른 섬의 각 요소들 사이의 거리를 모두 비교
  // 거리가 2 이상이고, 사이에 바다만 있으며, 최단 거리를 갱신할 수 있는 경우에만 값 갱신

  for(int i{0}; i < island; i++){

    for(int j{i + 1}; j < island; j++){

      for(auto x : graph[i]){

        for(auto y : graph[j]){

          if(x.first == y.first){
            
            int dis = abs(y.second - x.second) - 1;

            if(dis < dist[i][j] && dis > 1){
              
              bool flag = true;

              if(x.second > y.second){

                for(int a{y.second + 1}; a < x.second; a++){
                  
                  if(arr[x.first][a] == 1){
                    flag = false;
                    break;
                  }
                }
              }

              else if(x.second < y.second){

                for(int a{x.second + 1}; a < y.second; a++){

                  if(arr[x.first][a] == 1){
                    flag = false;
                    break;
                  }
                }
              }

              if(flag)
                dist[i][j] = dis;
            }
          }

          else if(x.second == y.second){

            int dis = abs(y.first - x.first) - 1;
            
            if(dis< dist[i][j] && dis > 1){
              
              bool flag = true;

              if(x.first > y.first){

                for(int a{y.first + 1}; a < x.first; a++){

                  if(arr[a][x.second] == 1){

                    flag = false;
                    break;
                  }
                }
              }

              else if(x.first < y.first){

                for(int a{x.first + 1}; a < y.first; a++){

                  if(arr[a][x.second] == 1){

                    flag = false;
                    break;
                  }
                }
              }

              if(flag)
                dist[i][j] = dis;
            }
          }
        }
      }
    }
  }

  for(int i{0}; i < island; i++){

    for(int j{0}; j < island; j++){

      if(dist[i][j] != INF && dist[i][j] != 1){
        vector<int>tmp = {dist[i][j], i, j};
        pq.push(tmp);
      }
    }
  }

  for(int i{0}; i < island; i++){
    parent.push_back(-1);
  }

  while(counter < island - 1 && !pq.empty())
    getDistance();

  if(counter == island - 1){
    cout<<answer<<"\n";
  }

  else{
    cout<<-1<<"\n";
  }
}

void getDistance(){

  vector<int>top = pq.top();
  pq.pop();

  int dis = top[0];
  int num1 = top[1];
  int num2 = top[2];

  int pointer1 = num1;
  int pointer2 = num2;

  if(parent[num1]== -1)
    pointer1 = -1;

  else{
    while(parent[pointer1] != pointer1)
      pointer1 = parent[pointer1];

    parent[num1] = pointer1;
  }

  if(parent[num2] == -1)
    pointer2 = -1;

  else{
    while(parent[pointer2] != pointer2)
      pointer2 = parent[pointer2];

    parent[num2] = pointer2;
  }

  if(pointer1 == -1 && pointer2 == -1){
    parent[num1] = num1;
    parent[num2] = num1;

    answer += dis;
    counter++;
    return;
  }

  else if(pointer1 != -1 && pointer2 == -1){
    parent[num2] = pointer1;

    answer += dis;
    counter++;
    return;
  }

  else if(pointer1 == -1 && pointer2 != -1){
    parent[num1] = pointer2;

    answer += dis;
    counter++;
    return;
  }

  else if(pointer1 == pointer2)
    return;

  else{

    parent[pointer2] = pointer1;

    answer += dis;
    counter++;

    return;
  }
}

void BFS(int row, int col){

  if(col < M - 1 && arr[row][col + 1] == 1 && check[row][col + 1] == false){
    
    graph[island].push_back({row, col + 1});
    check[row][col + 1] = true;

    BFS(row, col + 1);
  }

  if(col > 0 && arr[row][col - 1] == 1 && check[row][col - 1] == false){

    graph[island].push_back({row, col - 1});
    check[row][col - 1]=true;

    BFS(row, col - 1);
  }

  if(row < N - 1 && arr[row + 1][col] == 1 && check[row + 1][col] == false){

    graph[island].push_back({row + 1, col});
    check[row + 1][col] = true;
    BFS(row + 1, col);
  }

  if(row > 0 && arr[row - 1][col] == 1 && check[row - 1][col] == false){

    graph[island].push_back({row - 1, col});
    check[row - 1][col] = true;
    BFS(row - 1, col);
  }

  return;
} 