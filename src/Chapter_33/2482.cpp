#include<iostream>
#include<vector>
using namespace std;

int N, K;

void getAnswer();

int main(){

  cin>>N>>K;

  getAnswer();

  return 0;
}

void getAnswer(){

  vector<int>tmp(N + 1, 0);
  vector<vector<int>>DP(N + 1, tmp);

  DP[1][1] = 1;
  DP[2][1] = 2;
  DP[3][1] = 3;

  for(int i{4}; i <= N; i++){

    DP[i][1] = i;

    for(int j{2}; j <= i / 2; j++){
      DP[i][j] = DP[i - 2][j - 1] + DP[i - 1][j];   // 이 점화식을 이용하면 풀림

      if(DP[i][j] > 1000000003)
        DP[i][j] = DP[i][j] % 1000000003;
    }
  }

  cout<<DP[N][K]<<"\n";
}