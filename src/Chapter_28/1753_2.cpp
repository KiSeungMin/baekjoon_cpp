#include<iostream>
#include<vector>
#include<queue>
#define sync_with_stdio(false)
using namespace std;

const int INF = 2000000000;
int node_cnt, edge_cnt, start_node;
vector<int>dist;
vector<vector<pair<int, int>>>graph;

void getInput(){

    cin >> node_cnt >> edge_cnt >> start_node;

    for(int i{0}; i <= node_cnt; i++){
        vector<pair<int, int>>tmp;

        graph.push_back(tmp);
        dist.push_back(INF);
    }

    for(int i{0}; i < edge_cnt; i++){
        int start, end, distance;
        cin >> start >> end >>distance;
        graph[start].push_back({distance, end});
    }
}

void dijkstra(priority_queue<pair<int, int>>& pq){

    while(!pq.empty()){

        int index_now = pq.top().second; pq.pop();

        if(dist[index_now] != INF){

            for(auto near_node : graph[index_now]){

                int distance = near_node.first;
                int index_near = near_node.second;

                if(dist[index_now] + distance < dist[index_near]){
                    dist[index_near] = dist[index_now] + distance;
                    pq.push({-1 * dist[index_near], index_near});
                }
            }
        }
    }
}

void printAnswer(){

    for(int i{1}; i <= node_cnt; i++){

        if(dist[i] == INF)
            cout<<"INF\n";
        else    
            cout<<dist[i]<<"\n";
    }
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    getInput();

    dist[start_node] = 0;
    priority_queue<pair<int ,int>> pq;

    pq.push({0, start_node});

    dijkstra(pq);

    printAnswer();

    return 0;
}