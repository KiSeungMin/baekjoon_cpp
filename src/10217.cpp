#include<iostream>
#include<vector>
using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin>>T:

  int airport, limit, ticket;

  for(int t{0}; t < T; t++){

    cin>>airport>>limit>>ticket;

    vector<int>tmp;
    vector<vector<int>> graph(N + 1, tmp);

    for(int i{0}; i < ticket; i++){

      int start, end, cost, time;
      cin>>start>>end>>cost>>time;

      vector<int>tmp;
      tmp.push_back(end);
      tmp.push_back(cost);
      tmp.push_back(time);

      graph[start].push_back(tmp);
    }

    vector<pair<int, int>>tmp2;
    vector<vector<pair<int, int>>>costAndTime(N+1, tmp2);

    costAndTime[1].push_back({0, 0});


  }

  return 0;
}