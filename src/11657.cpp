#include<iostream>
#include<vector>
using namespace std;

int N, M;
const long long INF = 999999999999; 

int main(){

  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin>>N>>M;

  vector<vector<int>>node;

  for(int i{0}; i < M; i++){
    vector<int>tmp;

    int start, end, time;
    cin>>start>>end>>time;

    tmp.push_back(start);
    tmp.push_back(end);
    tmp.push_back(time);

    node.push_back(tmp);
  }

  vector<long long>dist(N + 1, INF);
  dist[1] = 0;

  for(int i{0}; i < N-1; i++){

    for(auto j : node){
      
      if(dist[j[0]] == INF)
        continue;

      else{

        if(dist[j[0]] + j[2] < dist[j[1]])
          dist[j[1]] = dist[j[0]] + j[2];
      }
    }
  }

  for(auto j : node){

    if(dist[j[0]] == INF) 
      continue;

    else{

      if(dist[j[0]] + j[2]  < dist[j[1]]){
        cout<<-1<<"\n";
        return 0;
      }
    }
  }

  for(int i {2}; i <= N; i++){

    if(dist[i] == INF)
      dist[i] = -1;

    cout<<dist[i]<<"\n";
  }

  return 0;
}