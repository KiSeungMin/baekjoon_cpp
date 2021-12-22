#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

int N, M;
const int maxInt= 2000000000;
int result = 0;
int answer = maxInt;

void BFS(queue<pair<int, int>>&node, vector<vector<bool>>& visited, vector<vector<bool>>& arr);

int main(){

  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin>>N>>M;

  vector<vector<bool>>arr;

  for(int i{0}; i < N; i++){

    string s;
    cin>>s;

    vector<bool>tmp;

    for(int j{0}; j < M; j++){

      if(s[j] == '0')
        tmp.push_back(false);
      
      else
        tmp.push_back(true);
    }

    arr.push_back(tmp);
  }

  vector<bool>tmp(M, false);
  vector<vector<bool>>visited(N, tmp);

  visited[0][0]=true;
  vector<vector<bool>>visitedCopy = visited;

  queue<pair<int, int>>node;
  node.push({0, 0});

  BFS(node, visited, arr);

  if(result < answer)
    answer = result;

  result = 0;
  
  visited = visitedCopy;

  for(int i{0}; i < N; i++){

    for(int j{0}; j < M; j++){

      if(arr[i][j] == true){
        
        arr[i][j] = false;
        visited = visitedCopy;

        queue<pair<int, int>>node;
        node.push({0, 0});

        BFS(node, visited, arr);

        if(result < answer)
          answer = result;

        result = 0;
        arr[i][j] = true;
      }
    }
  }

  if(answer == maxInt)
    answer = -1;

  cout<<answer<<"\n";

  return 0;
}

void BFS(queue<pair<int, int>>& node, vector<vector<bool>>& visited, vector<vector<bool>>& arr){

  result++;

  if(result >= answer)
    return;

  int size = node.size();
  
  for(int i{0}; i < size; i++){

    pair<int, int>tmp = node.front();
    node.pop();

    int row = tmp.first;
    int col = tmp.second;

    if(row == N -1 && col == M -1)
      return;

    if(row != 0){

      if(arr[row - 1][col] == false && visited[row - 1][col] == false){

        node.push({row - 1, col});
        visited[row - 1][col] = true;
      }
    }

    if(row != N - 1){

      if(arr[row + 1][col] == false && visited[row + 1][col] == false){

        node.push({row + 1, col});
        visited[row + 1][col] = true;
      }
    }

    if(col != 0){

      if(arr[row][col - 1] == false && visited[row][col - 1] == false){

        node.push({row, col-1});

        visited[row][col - 1] = true;
      }
    }

    if(col != M - 1){

      if(arr[row][col + 1] == false && visited[row][col + 1] == false){

        node.push({row, col + 1});

        visited[row][col + 1] = true;
      }
    }
  }

  if(node.size() == 0){
    result = maxInt;
    return;
  }

  BFS(node, visited, arr);
}
