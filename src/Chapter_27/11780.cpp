#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>dist;
vector<vector<vector<int>>>route;
const int INF = 1000000000;

int main(){

  int N, M;
  cin>>N>>M;
  
  for(int i{0}; i < N +1; i++){

    vector<int>tmp(N + 1, INF);
    tmp[i] = 0;
    vector<int>tmp2;
    vector<vector<int>>tmp3(N + 1, tmp2);

    dist.push_back(tmp);
    route.push_back(tmp3);
  }

  for(int i{0}; i < M; i++){
    int num1, num2, num3;
    cin>>num1>>num2>>num3;

    if(num3 < dist[num1][num2]){
      dist[num1][num2] = num3;
      vector<int>tmp;
      tmp.push_back(num1);
      tmp.push_back(num2);
      route[num1][num2] = tmp;
    }
  }

  for(int k{1}; k <= N; k++){

    for(int i{1}; i <= N; i++){

      for(int j{1}; j <= N; j++){

        if(i == j)
          continue;

        else if(dist[i][k] + dist[k][j] < dist[i][j]){

          dist[i][j] = dist[i][k] + dist[k][j];

          vector<int>tmp;
          tmp.push_back(i);
          
          for(auto x : route[i][k]){
            if(x != i && x != j && x != k)
              tmp.push_back(x);
          }

          tmp.push_back(k);

          for(auto x : route[k][j]){
            if(x != j && x != i && x != k)
              tmp.push_back(x);
          }

          tmp.push_back(j);

          route[i][j] = tmp;
        }
      }
    }
  }

  for(int i{1}; i <= N; i++){

    for(int j{1}; j <= N; j++){

      if(dist[i][j] >= INF)
        dist[i][j] =0;

      cout<<dist[i][j]<<" ";
    }
    cout<<"\n";
  }

  for(int i{1}; i <=N; i++){

    for(int j{1}; j <=N; j++){

      cout<<route[i][j].size()<<" ";

      if(route[i][j].size() != 0){

        for(auto k : route[i][j])
          cout<<k<<" ";
      }
      
      cout<<"\n";
    }
  }
  
  return 0;
}