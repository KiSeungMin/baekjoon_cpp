#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 1000000000;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin>>T;

  int N, limit, ticket;

  for(int t{0}; t < T; t++){

    cin>>N>>limit>>ticket;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;

    vector<int>tmp;
    vector<vector<int>>tmp2;
    vector<vector<int>>graph(tmp2, N + 1);

    for(int i{0}; i < ticket; i++){

      int start, end, cost, time;
      cin>>start>>end>>cost>>time;

      vector<int>tmp;
      tmp.push_back(time);
      tmp.push_back(end);
      tmp.push_back(cost);

      graph[start].push_back(tmp);
    }

    vector<int>row(limit + 1, INF);
    vector<vector<int>>DP(N + 1, row);

    for(int i{0}; i < DP[1].size(); i++)
      DP[1][i] = 0;

    while(!que.empty()){

      vector<int>tmp = que.top();
      que.pop();

      int start = tmp[0];
      int end = tmp[1];
      int time = tmp[2];
      int cost = tmp[3];

      for(int i{0}; i + cost <= limit; i++){

        if(DP[start][i] + time < DP[end][i + cost]){

          for(int j{i + cost}; j <= limit; j++){

            DP[end][j] = DP[start][i] + time;
          }
        }
      }
    }

    int answer = INF;

    for(auto j : DP[N]){

      if(j < answer)
        answer = j;
    }

    if(answer == INF){

      cout<<"Poor KCM\n";
      continue;
    }

    cout<<answer<<"\n";

  }

  return 0;
}