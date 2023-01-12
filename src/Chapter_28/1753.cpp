#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int node, edge;
// startIndex
int start;
const long long INF = 999999999999;

int main(){

  cout.tie(NULL);
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin>>node>>edge;
  cin>>start;

  vector<pair<int, int>> tmp;
  vector<vector<pair<int, int>>> arr(20001, tmp);

  vector<long long>distance(20001, INF);

  for(int i{0}; i < edge; i++){

    int node1, node2, distance;
    cin>>node1>>node2>>distance;

    arr[node1].push_back({node2, distance});
  }

  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
  pq.push({0, start});

  while(!pq.empty()){

    long long dis = pq.top().first;
    long long index = pq.top().second;
    pq.pop();

    if(dis < distance[index])
      distance[index] = dis;

    else
      continue;

    for(auto i : arr[index]){

      // first : index, second : dinstance
      if(dis + i.second < distance[i.first])
        pq.push({dis + i.second , i.first});
    }
  }

  // print result
  for(int i{1}; i <= node; i++){
    
    if(distance[i] == INF)
      cout<<"INF\n";

    else
      cout<<distance[i]<<"\n";
  }
  return 0;
}