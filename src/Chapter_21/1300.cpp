#include<iostream>
#include<vector>
using namespace std;

int main(){

  long long N, K;
  cin>>N>>K;

  vector<long long>arr;
  for(long long i{1};i <= N; i++)
    arr.push_back(i);

  long long answer = 0;
  for(long long i{1}; i <= N*N; i++){

    for(int j{0}; j < arr.size(); j++){

      if(arr[j] > i * i)
        break;

      if(i % arr[j] == 0 && (i/arr[j]) <= N)
        answer++;
    }

    if(answer >= K){
      cout<<i<<"\n";
      return 0;
    }
  }  

  return 0;
}