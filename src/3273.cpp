#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

  int N;
  cin>>N;

  int answer = 0;

  vector<int> arr;

  for(int i{0}; i < N; i++){
    int num;
    cin>>num;
    arr.push_back(num);
  }

  int goal;
  cin>>goal;

  sort(arr.begin(), arr.end());

  int start = 0;
  int end = N - 1;

  while(start < end){

    if(arr[start] + arr[end] < goal){
      start++;
      continue;
    }

    else if(arr[start] + arr[end] == goal){
      answer++;
      start++;
      end--;
      continue;
    }

    else{
      end--;
      continue;
    }
  }

  cout<<answer<<"\n";

  return 0;
}