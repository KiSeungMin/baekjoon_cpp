#include<iostream>
#include<vector>
#include<queue>
#define sync_with_stdio(false)
using namespace std;

int node_cnt;
vector<int>parent;
vector<vector<int>>graph;

void getInput(){

    cin.tie(NULL);
    cin >> node_cnt;

    for(int i{0}; i <= node_cnt; i++){
        vector<int>tmp;
        graph.push_back(tmp);
        parent.push_back(-1);
    }

    for(int i{0}; i < node_cnt - 1; i++){
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }
}

void getParent(queue<int>& q){

    queue<int> next_que;

    while(!q.empty()){

        int parent_node = q.front(); q.pop();

        for(auto child_node : graph[parent_node]){
            if(parent[child_node] != -1)
                continue;

            parent[child_node] = parent_node;
            next_que.push(child_node);
        }
    }

    if(next_que.empty())
        return;

    getParent(next_que);
}

void printParent(){

    cout.tie(NULL);
    for(int i{2}; i <= node_cnt; i++){
        cout<<parent[i]<<"\n";
    }
}

int main(){

    getInput();

    parent[1] = 1;
    queue<int>q; q.push(1);

    getParent(q);

    printParent();

    return 0;
}