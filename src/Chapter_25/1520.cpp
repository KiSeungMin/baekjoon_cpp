#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;

vector<vector<int>>DP;
vector<vector<int>>arr;

void move(int row, int col, vector<vector<pair<int, int >>>& graph);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;
  
  for(int i{0}; i < N; i++){

    vector<int>init(M, 0);
    vector<int>tmp;

    for(int j{0}; j < M; j++){

      int num;
      cin>>num;
      tmp.push_back(num);
    }

    arr.push_back(tmp);
    DP.push_back(init);
  }

  vector<pair<int, int>>tmp;
  vector<vector<pair<int, int>>> graph(N*M, tmp);

  for(int i{0}; i < N; i++){

    for(int j{0}; j < M; j++){
      move(i, j , graph);
    }
  }

  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

  for(int i{0}; i < N; i++){

    for(int j{0};j < M; j++){

      vector<int>tmp;
      tmp.push_back(arr[i][j]);
      tmp.push_back(i);
      tmp.push_back(j);

      pq.push(tmp);
    }
  }

  DP[N-1][M-1] = 1;

  while(!pq.empty()){

    vector<int> min = pq.top();
    pq.pop();

    int row = min[1];
    int col = min[2];

    if(DP[row][col] == 0)
      continue;

    for(auto j : graph[row * M  + col]){

      DP[j.first][j.second] += DP[row][col];
    }
  }

  /*
  for(int i{0}; i < N; i++){

    for(int j{0}; j < M; j++){

      cout<<DP[i][j]<<" ";
    }
    cout<<"\n";
  }
  */

  cout<<DP[0][0]<<"\n";

  return 0;
}

void move(int row, int col, vector<vector<pair<int, int >>>& graph){
  
  if(row > 0 && arr[row-1][col] > arr[row][col])
    graph[row * M + col].push_back({row-1, col});
  
  if(row < N -1  && arr[row + 1][col] > arr[row][col])
    graph[row*M + col].push_back({row + 1, col});
  
  if(col > 0 && arr[row][col - 1] > arr[row][col])
    graph[row*M + col].push_back({row, col-1});
  
  if(col < M - 1 && arr[row][col + 1] > arr[row][col])
    graph[row*M + col].push_back({row, col + 1});
  
}