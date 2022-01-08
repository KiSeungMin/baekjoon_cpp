#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

  int N, limit;
  cin>>N>>limit;

  vector<int>arr;
  for(int i{0}; i < N; i++){
    int num;
    cin>>num;
    arr.push_back(num);
  }

  sort(arr.begin(), arr.end());

  

  int answer = 1;
  vector<int>board;
  board.push_back(0);

  for(int i{0}; i < N; i++){


  }



  return 0;
}