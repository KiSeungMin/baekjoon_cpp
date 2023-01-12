#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int node, edge;
int goal1, goal2;

long long getAnswer(int start, int end, vector<vector<pair<int, int>>>& arr);

const long long INF = 999999999999;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>node>>edge;

  vector<pair<int, int>>tmp;
  vector<vector<pair<int, int>>> arr(node + 1, tmp);

  for(int i{0}; i < edge; i++){

    int node1, node2, distance;
    cin>>node1>>node2>>distance;

    arr[node1].push_back({distance, node2});
    arr[node2].push_back({distance , node1});
  }

  cin>>goal1>>goal2;

  long long answer1 = getAnswer(1, goal1, arr) + getAnswer(goal1, goal2, arr) + getAnswer(goal2, node, arr);
  long long answer2 = getAnswer(1, goal2, arr) + getAnswer(goal2, goal1, arr) + getAnswer(goal1, node, arr);

  if(answer1 >= INF && answer2 >= INF)
    cout<<-1<<"\n";

  else if(answer1 <= answer2)
    cout<<answer1<<"\n";

  else
    cout<<answer2<<"\n";

  return 0;
}

long long getAnswer(int start, int end, vector<vector<pair<int, int>>>& arr){

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  vector<long long>dist(node + 1, INF);

  pq.push({0, start});

  while(!pq.empty()){

    long long distance = pq.top().first;
    int index = pq.top().second;
    pq.pop();

    if(distance < dist[index])
      dist[index] = distance;

    else
      continue;

    for(auto i : arr[index]){

      if(dist[index] + i.first < dist[i.second])
        pq.push({dist[index] + i.first, i.second});
    }
  }

  return dist[end];
}