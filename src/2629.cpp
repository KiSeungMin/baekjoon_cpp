#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<bool>DP(40001, false);

  int N;
  cin>>N;

  vector<int>weight;
  for(int i{0}; i < N; i++){
    int num;
    cin>>num;
    weight.push_back(num);
  }

  vector<int> board;
  board.push_back(0);

  for(int i{0}; i < weight.size(); i++){

    vector<int>tmp;

    for(int j{0}; j < board.size(); j++){

      int num1 = weight[i] + board[j];
      int num2 = abs(weight[i] - board[j]);

      if(num1 <= 40000 && DP[num1] == false){
        tmp.push_back(num1);
        DP[num1] = true;
      }

      if(num2 <= 40000 && DP[num2] == false){
        tmp.push_back(num2);
        DP[num2]=true;
      } 
    }

    for(auto j : tmp)
      board.push_back(j);
  }

  int M;
  cin>>M;

  for(int i{0}; i < M; i++){
    int num;
    cin>>num;

    if(DP[num])
      cout<<"Y ";

    else
      cout<<"N ";
  }

  return 0;
}