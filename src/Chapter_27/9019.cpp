#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int start;
int goal;

vector<char>command(10000, 'X');
vector<int>parent(10000, 0);

void init();
void DFS(queue<int>que);
void check(int num, char commandNow, int parentNow, queue<int>& que);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin>>T;

  for(int t{0}; t < T; t++){

    init();

    cin>>start>>goal;

    command[start] = 'O';

    queue<int>que;
    que.push(start);

    DFS(que);

    vector<char>result;
    int pointer = goal;

    while(command[pointer] != 'O'){
      result.push_back(command[pointer]);
      pointer = parent[pointer];
    }

    for(int i{static_cast<int>(result.size()-1)}; i>=0; i--){
      cout<<result[i];
    }
    cout<<"\n";
  }
}

void init(){
  for(int i{0}; i < 10000; i++){
    parent[i] = i;
    command[i] = 'X';
  }
}

void DFS(queue<int>que){

   int size = que.size();
   for(int i{0}; i < size; i++){

     int num = que.front();
     que.pop();

     int result;

     result = (num * 2) % 10000;
     check(result, 'D', num, que);
     if(result == goal)
        return;

     result = num - 1;
     if(result < 0)
      result = 9999;
     check(result, 'S', num, que);
     if(result == goal)
      return;
     
     string tmptmp = to_string(num);
     int sizeNum = tmptmp.length();
     string tmp;
     for(int i{0}; i < 4 - sizeNum; i++){
       tmp.push_back('0');
     }
     for(int i{0}; i <sizeNum; i++){
       tmp.push_back(tmptmp[i]);
     }

     string res;
     for(int i{1}; i< tmp.length(); i++){
       res.push_back(tmp[i]);
     }
     res.push_back(tmp[0]);
     result = stoi(res);
     check(result, 'L', num, que);

     if(result == goal)
      return;

     string res2;
     res2.push_back(tmp[tmp.length()-1]);
     for(int i{0}; i < tmp.length()-1; i++){
       res2.push_back(tmp[i]);
     }
     result = stoi(res2);
     check(result, 'R', num, que);

     if(result == goal)
      return;
  }

  if(que.size() == 0)
    return;

   DFS(que);
}

void check(int num, char commandNow, int parentNow, queue<int>& que){

  if(num >= 0 && num < 10000){

    if(command[num] == 'X'){

      command[num] = commandNow;
      parent[num] = parentNow;
      que.push(num);
    }
  }
}