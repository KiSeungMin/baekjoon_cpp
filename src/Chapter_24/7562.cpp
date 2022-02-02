#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool move(int rowNow, int colNow, int rowMove, int colMove, vector<vector<bool>>& visited);
void DFS(queue<pair<int, int >>& node, vector<vector<bool>>& visited);

int N;
int row, col;
int goalRow, goalCol;

int result = 0;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin>>T;

  for(int t{0}; t < T; t++){

    cin>>N;
    cin>>row>>col;
    cin>>goalRow>>goalCol;

    if(row == goalRow && col == goalCol){
      cout<<0<<"\n";
      continue;
    }

    vector<bool>tmp(N, false);
    vector<vector<bool>>visited(N, tmp);
    visited[row][col]=true;

    queue<pair<int, int>> node;
    node.push({row, col});

    DFS(node, visited);

    cout<<result<<"\n";

    result = 0;
  }

  return 0;
}

void DFS(queue<pair<int, int>>& node, vector<vector<bool>>& visited){

  int size = node.size();

  for(int i{0}; i < size; i++){

    int row = node.front().first;
    int col = node.front().second;

    if(row == goalRow && col == goalCol)
      return;

    node.pop();

    if(move(row, col, -1, -2, visited))
      node.push({row -1, col -2});

    if(move(row, col, -2, -1, visited))
      node.push({row-2, col-1});

    if(move(row, col, -2, 1, visited))
      node.push({row-2, col+1});

    if(move(row, col, -1, 2, visited))
      node.push({row-1, col+2});

    if(move(row, col, 1, 2, visited))
      node.push({row+1, col+2});

    if(move(row, col, 2, 1, visited))
      node.push({row+2, col+1});

    if(move(row, col, 2, -1, visited))
      node.push({row+2, col-1});

    if(move(row, col, 1, -2, visited))
      node.push({row+1, col-2});
  }

  result++;

  DFS(node, visited);
}

bool move(int rowNow, int colNow, int rowMove, int colMove, vector<vector<bool>>& visited){

  if(rowNow + rowMove >= 0 && rowNow + rowMove < N){

    if(colNow + colMove >= 0 && colNow + colMove < N){

      if(visited[rowNow + rowMove][colNow + colMove] == false){

        visited[rowNow + rowMove][colNow + colMove] = true;
        return true;
      }
    }
  }

  return false;
}