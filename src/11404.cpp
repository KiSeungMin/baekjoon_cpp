#include<iostream>
#include<vector>
using namespace std;

const unsigned int INF = 2000000000; 

unsigned int getMin(unsigned int a, unsigned int b);

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin>>N>>M;

  vector<unsigned int>tmp(N + 1, INF);
  vector<vector<unsigned int>> cost(N + 1, tmp);

  for(int i{0}; i < M; i++){

    int num1, num2, num3;
    cin>>num1>>num2>>num3;

    if(num3  < cost[num1][num2])
      cost[num1][num2] = num3;
  }

  for(int i{0}; i < N + 1; i++)
    cost[i][i] =  0;

  
  for(int i{1}; i < N + 1; i++){

    for(int j{1}; j < N + 1; j++){

      for(int k{1}; k < N + 1; k++){

        if(j == k)
          continue;

        cost[j][k] = getMin(cost[j][k], cost[j][i] + cost[i][k]);

        if(cost[j][k] > INF)
          cost[j][k] = INF;
      }
    }
  }

  for(int i{1}; i < N + 1; i++){

    for(int j{1}; j < N + 1; j++){

      if(cost[i][j] >= INF)
        cost[i][j] = 0;

      if(i == j)
        cost[i][j] = 0;

      cout<<cost[i][j]<<" ";
    }

    cout<<"\n";
  }

  return 0;
}

unsigned int getMin(unsigned int a, unsigned int b){

  if(a > b)
    return b;

  return a;
}

