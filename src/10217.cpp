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

  int airport, limit, ticket;

  for(int t{0}; t < T; t++){

    cin>>airport>>limit>>ticket;

    vector<vector<int>>tmp;
    vector<vector<vector<int>>>graph(airport + 1, tmp);

    for(int i{0}; i < ticket; i++){

      int start, end, cost, time;
      cin>>start>>end>>cost>>time;

      vector<int>tmp;
      tmp.push_back(end);
      tmp.push_back(time);
      tmp.push_back(cost);

      graph[start].push_back(tmp);
    }

    vector<pair<int, int>>tmp2;
    vector<vector<pair<int, int>>>TimeAndCost(airport+1, tmp2);

    TimeAndCost[1].push_back({0, 0});

    for(int i{1}; i < airport; i++){

      for(auto j : TimeAndCost[i]){

        for(auto k : graph[i]){

          if(j.second + k[2] <= limit){

            TimeAndCost[k[0]].push_back({j.first + k[1], j.second + k[2]});
          }
        }
      }
    }

    if(TimeAndCost[airport].size() == 0){

      cout<<"Poor KCM\n";
      continue;
    }

    sort(TimeAndCost[airport].begin(), TimeAndCost[airport].end());

    cout<<TimeAndCost[airport][0].first<<"\n";

  }

  return 0;
}