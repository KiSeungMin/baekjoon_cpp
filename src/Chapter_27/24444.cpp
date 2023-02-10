#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

int node_cnt, edge_cnt, start_node;
int id{1};
vector<int>result;
vector<vector<int>>graph;

void getInput(){

    cin >> node_cnt >> edge_cnt >> start_node;

    vector<int>row;

    for(int i{0}; i <= node_cnt; i++){
        graph.push_back(row);
        result.push_back(0);
    }

    for(int i{0}; i < edge_cnt; i++){
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for(int i{0}; i <= node_cnt; i++){
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    getInput();

    result[start_node] = id;
    id++;

    queue<int>q;
    q.push(start_node);

    while(!q.empty()){

        int front = q.front();
        q.pop();

        for(int near_node : graph[front]){
            if(result[near_node] == 0){

                result[near_node] = id++;

                q.push(near_node);
            }
        }
    }

    for(int i{1}; i <= node_cnt; i++){
        cout<<result[i]<<"\n";
    }

    return 0;
}