#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){

  int N;
  cin>>N;

  vector<int>arr;
  for(int i{0}; i < N; i++){
    int num;
    cin>>num;
    arr.push_back(num);
  }

  sort(arr.begin(), arr.end());

  int answer =abs(arr[0] + arr[N-1]) + 1;
  int left = arr[0];
  int right = arr[N-1];

  int start = 0;
  int end =  N - 1;

  while(start < end){

    int result = abs(arr[start] + arr[end]) + 1;

    while(abs(arr[start] + arr[end]) < result && start < end){

      result = abs(arr[start] + arr[end]);
      end--;
    }

    end++;

    if(abs(arr[start] + arr[end]) < answer){
      answer = abs(arr[start] + arr[end]);
      left = arr[start];
      right = arr[end];
    }

    start ++;
    
  }

  cout<<left<<" "<<right<<"\n";

  return 0;
}