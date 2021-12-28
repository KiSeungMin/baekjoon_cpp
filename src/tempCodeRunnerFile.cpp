#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin>>T;

  for(int t{0}; t < T; t++){

    int N;
    cin>>N;

    vector<unsigned long long>arr;

    for(int i{0}; i < N; i++){

      int num;
      cin>>num;
      arr.push_back(num);
    }

    vector<int>tmp(N, 0);
    vector<vector<int>>sum(N, tmp);

    for(int i{0}; i < N; i++){

      for(int j{i}; j < N; j++){

        sum[i][j] = sum[i][j-1] + arr[i][j];
      }
    }

    for(int i{0}; i < N; i++){
      sum[i][i] = 0;
    }

    for(int i{0}; i < N; i++){
      
      for(int j{0}; j < N; j++){

        cout<<sum[i][j]<<" ";
      }
      cout<<"\n";
    }
  }

  return 0;
}