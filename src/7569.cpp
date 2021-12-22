#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int result = 0;
int answer = 0;
int col, row, hei;

vector<vector<vector<bool>>>visited;
vector<vector<vector<int>>>arr;

bool move(int hei11, int row1, int col1);
void DFS(queue<vector<int>>& node);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>col>>row>>hei;

  queue<vector<int>> node;

  for(int i{0}; i < hei; i++){

    vector<vector<int>>tmp2;
    vector<vector<bool>>tmpBool2;
    for(int j{0}; j < row; j++){

      vector<int>tmp;
      vector<bool>tmpBool;
      for(int k{0}; k < col; k++){

        int num;
        cin>>num;

        if(num == 1){
          vector<int>tmpVec={i, j, k};
          node.push(tmpVec);
          tmpBool.push_back(true);
        }

        else if(num == 0){
          result ++;
          tmpBool.push_back(false);
        }

        else
          tmpBool.push_back(false);

        tmp.push_back(num);
      }
      tmp2.push_back(tmp);
      tmpBool2.push_back(tmpBool);
    }
    arr.push_back(tmp2);
    visited.push_back(tmpBool2);
  }

  if(result == 0){
    cout<<0<<"\n";
    return 0;
  }

  DFS(node);

  if(result == 0){
    cout<<answer<<"\n";
    return 0;
  }

  else{
    cout<<-1<<"\n";
    return 0;
  }

  return 0;
}

void DFS(queue<vector<int>>& node){
  
  int size = node.size();

  for(int i{0}; i < size; i++){

    vector<int> first = node.front();
    node.pop();

    int heiNow = first[0];
    int rowNow = first[1];
    int colNow = first[2];
    vector<int>tmp;

    for(int z{colNow-1}; z <= colNow +1; z = z + 2){

      if(move(heiNow, rowNow, z)){

        result--;
        visited[heiNow][rowNow][z] = true;
        arr[heiNow][rowNow][z] = 1;

        tmp = vector<int>{heiNow, rowNow, z};
        node.push(tmp);
      }
    }

    for(int y{rowNow-1}; y <= rowNow +1; y = y + 2){
      if(move(heiNow, y, colNow)){

        result--;
        visited[heiNow][y][colNow] = true;
        arr[heiNow][y][colNow] = 1;
        tmp = vector<int>{heiNow, y, colNow};
        node.push(tmp);
      }
    }

    for(int x{heiNow-1}; x <= heiNow +1; x = x + 2){

      if(move(x, rowNow, colNow)){

        result--;
        visited[x][rowNow][colNow] = true;
        arr[x][rowNow][colNow] = 1;
        tmp = vector<int>{x, rowNow, colNow};
        node.push(tmp);
      }
    }
  }

  answer++;

  if(result == 0)
    return;

  if(node.size() == 0)
    return;

  DFS(node);
}

bool move(int hei1, int row1, int col1){

  if(col1 >= 0 && col1 < col){

    if(row1 >= 0  && row1 < row){

      if(hei1 >= 0 && hei1 < hei){

        if(visited[hei1][row1][col1] == false){

          if(arr[hei1][row1][col1] == 0)
            return true;
        }
      }
    }
  }

  return false;
}