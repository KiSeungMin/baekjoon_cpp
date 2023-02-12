#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

const long long INF = 1000000000000;
int node_cnt, edge_cnt;
vector<long long>dist;
vector<vector<int>>graph;

void getInput(){

    cin.tie(NULL);

    cin >> node_cnt >> edge_cnt;

    for(int i{0}; i <= node_cnt; i++){
        dist.push_back(INF);
    }

    for(int i{0}; i < edge_cnt; i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        vector<int>tmp = {start, end, cost};
        graph.push_back(tmp);
    }
}

long long getMin(long long a, long long b){
    return (a > b ? b : a);
}

void getAnswer(){

    dist[1] = 0;

    for(int i{1}; i < node_cnt; i++){
        for(auto edge : graph){
            int start = edge[0]; int end = edge[1]; long long cost = edge[2];

            if(dist[start] == INF)
                continue;

            dist[end] = getMin(dist[end], dist[start] + cost);
        }
    }

    for(auto edge : graph){
        int start = edge[0]; int end = edge[1]; long long cost = edge[2];

        if(dist[start] == INF)
            continue;

        if(dist[start] + cost < dist[end]){
            cout<<-1<<"\n";
            return;
        }
    }

    cout.tie(NULL);
    for(int i{2}; i <= node_cnt; i++){
        cout<<(dist[i] >= INF ? -1 : dist[i])<<"\n";
    }
}



int main(){

    getInput();
    
    getAnswer();

    return 0;
}