#include<iostream>
#include<vector>
using namespace std;

const int INF = 2000000000;

int main(){

  int N;
  cin>>N;

  vector<int>arr;
  for(int i{0}; i < N; i++){
    int num;
    cin>>num;
    arr.push_back(num);
  }

  vector<int>count(N, 1);
  vector<int>parent(N, 0);
  for(int i{0}; i < N; i++)
    parent[i] = i;

  int answer = 0;
  int answerIndex = 0;
  
  for(int i{0}; i < N; i++){

    int max = 0;

    for(int j{i-1}; j>=0; j--){

      if(arr[j] < arr[i] && count[j] + 1 > max){

        count[i] = count[j] + 1;
        max = count[j] + 1;
        parent[i] = j;
      }
    }

    if(count[i] > answer){
      answer=count[i];
      answerIndex=i;
    }
  }

  vector<int>answerArray;

  int index = answerIndex;
  while(answerArray.size() < answer){

    answerArray.push_back(arr[index]);
    index = parent[index];
  }

  cout<<answer<<"\n";

  for(int i{answer-1}; i >= 0; i--){
    cout<<answerArray[i]<<" ";
  }
  cout<<"\n";

  return 0;
}