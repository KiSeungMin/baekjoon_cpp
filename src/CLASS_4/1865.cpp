#include<iostream>
#include<queue>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

const int INF = 1000000000;

void getEdges(int edge_cnt, int minus_edge_cnt, vector<vector<int>>& edges){

    for(int i{0}; i < edge_cnt; i++){
        int node1, node2, distance;
        cin >> node1 >> node2 >> distance;

        vector<int>edge1 = {node1, node2, distance};
        vector<int>edge2 = {node2, node1, distance};
        edges.push_back(edge1);
        edges.push_back(edge2);
    }

    for(int i{0}; i < minus_edge_cnt; i++){
        int start, end, distance;
        cin >> start >> end >> distance;

        vector<int>edge = {start, end, -1 * distance};
        edges.push_back(edge);
    }
}

int getMin(int a, int b){
    return (a < b ? a : b);
}

void getAnswer(){

    int node_cnt, edge_cnt, minus_edge_cnt;
    cin >> node_cnt >> edge_cnt >> minus_edge_cnt;

    vector<int>dist(node_cnt + 1, INF);
    vector<vector<int>>edges;
    getEdges(edge_cnt, minus_edge_cnt, edges);

    int start, end, distance;
    for(int i{0}; i < node_cnt - 1; i++){
        for(auto edge : edges){
            start = edge[0]; end = edge[1]; distance = edge[2];

            dist[end] = getMin(dist[end], dist[start] + distance);
        }
    }

    for(auto edge : edges){
        start = edge[0]; end = edge[1]; distance = edge[2];

        if(dist[start] + distance < dist[end]){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
    return;
}

int main(){

    int T; cin >> T;
    for(int t{0}; t < T; t++){
        getAnswer();
    }

    return 0;
}