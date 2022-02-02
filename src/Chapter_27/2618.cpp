#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int N, W;
const int INF = 1000000000;
int answer = INF;

vector<vector<int>>DP;
vector<int>answerVec;

void DFS(int result, int row, int col, int car1, int car2, vector<bool>possible, vector<int>log);

int main(){
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>W;
  srand(static_cast<unsigned int>(time(0)));

  vector<pair<int, int>>arr;

  for(int i{0}; i < W; i++){
    int num1, num2;
    num1 = rand() % 1000;
    num2 = rand() % 1000;
    //cin>>num1>>num2;
    arr.push_back({num1, num2});
  }

  vector<int>tmp(W, INF);
  for(int i{0}; i < W + 2; i++)
    DP.push_back(tmp);

  for(int i{0}; i < W; i++){

    DP[0][i] = abs(1 - arr[i].first) + abs(1 - arr[i].second);
    DP[1][i] = abs(N - arr[i].first) + abs(N - arr[i].second);
  }

  for(int i{0}; i < W; i++){

    for(int j{i + 1}; j < W; j++){

      DP[i + 2][j] = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
    }
  }

  vector<bool>move(W +  2, true);
  vector<int>tmp2;
  DFS(0, 0, 0, 0, 1, move, tmp2);
  DFS(0, 1, 0, 0, 1, move, tmp2);

  cout<<answer<<"\n";

  for(auto j : answerVec)
    cout<<j<<"\n";

  return 0;
}

void DFS(int result, int row, int col, int car1, int car2, vector<bool>possible, vector<int>log){

  result = result + DP[row][col];

  if(result > answer)
    return;

  if(row == car1){
    car1 = col + 2;
    log.push_back(1);
  }

  else if(row == car2){
    car2 = col + 2;
    log.push_back(2);
  }

  if(col == W - 1){

    if(result < answer){
      answer = result;
      answerVec = log;
    }
    return;
  }

  possible[row] = false;

  for(int i{0}; i < col + 3; i++){

    if(DP[i][col + 1] != INF && possible[i] == true){
      DFS(result, i, col + 1, car1, car2, possible, log);
    }
  }
}