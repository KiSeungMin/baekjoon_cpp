#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 2000000000;
vector<bool>visited;
vector<int>dist;
vector<vector<pair<int, int>>>adj;

void dijkstra(priority_queue<pair<int, int>>& pq){

    while(!pq.empty()){

        int start = pq.top().second;
        pq.pop();

        if(visited[start])
            continue;

        visited[start] = true;

        for(auto ad : adj[start]){

            int dist_now = ad.first;
            int goal = ad.second;

            if(dist[start] + dist_now < dist[goal]){
                dist[goal] = dist[start] + dist_now;
                pq.push({-1 * dist[goal], goal});
            }
        }
    }
}

int main(){

    int N, M;
    cin >> N >> M;

    for(int i{0}; i <= N; i++){
        visited.push_back(false);
        dist.push_back(INF);
        vector<pair<int, int>>tmp;
        adj.push_back(tmp);
    }

    for(int i{0}; i < M; i++){
        int start, end, dist;
        cin >> start >> end >> dist;
        adj[start].push_back({dist, end});
    }

    int start, goal;
    cin >> start >> goal;

    dist[start] = 0;
    priority_queue<pair<int, int>>pq;
    pq.push({0, start});
    dijkstra(pq);

    cout<<dist[goal]<<"\n";

    return 0;
}