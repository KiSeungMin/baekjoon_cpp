#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int N;
vector<pair<long long, long long>>arr;
vector<vector<long long>>DP;

long long getAnswer(int start, int end);
long long getMin(long long a, long long b);

int main(){
  
  cin>>N;

  for(int i{0}; i < N; i++){

    int num1, num2;
    cin>>num1>>num2;

    arr.push_back({num1, num2});
  }

  for(int i{0}; i < N; i++){
    vector<long long>tmp(N, -1);
    tmp[i] = 0;

    DP.push_back(tmp);
  }

  for(int i{0}; i < N-1; i++)
    DP[i][i+1] = arr[i].first * arr[i].second* arr[i+1].second;

  getAnswer(0, N-1);

  cout<<DP[0][N-1]<<"\n";

  return 0;
}

long long getAnswer(int start, int end){

  if(DP[start][end] != -1)
    return DP[start][end];

  long long min = 90000000000;

  for(int i{start}; i <= end - 1; i++){

    long long res = getAnswer(start, i) + getAnswer(i + 1, end) + (arr[start].first * arr[end].second * arr[i].second);
    min = getMin(min, res);
  }

  DP[start][end] = min;

  return min;
}

long long getMin(long long a, long long b){

  if(a > b)
    return b;

  return a;
}
