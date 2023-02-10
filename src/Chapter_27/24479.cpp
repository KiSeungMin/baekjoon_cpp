#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

int node, edge, start_node;
int id{1};
vector<int>result;
vector<vector<int>>graph;

void getInput(){
    cin >> node >> edge >> start_node;

    vector<int>row;
    for(int i{0}; i < node + 1; i++){
        graph.push_back(row);
        result.push_back(0);
    }

    for(int i{0}; i < edge; i++){
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
    }
}

void setInput(){
    result[start_node] = id;
    id++;

    for(int i{1}; i <= node; i++){
        sort(graph[i].begin(), graph[i].end());
    }
}

void DFS(vector<int>& near_nodes){

    for(auto near_node : near_nodes){

        if(result[near_node] == 0){
            result[near_node] = id;
            id++;

            DFS(graph[near_node]);
        }
    }
}

void printAnswer(){
    for(int i{1}; i <= node; i++)
        cout<<result[i]<<"\n";
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    getInput();

    setInput();

    DFS(graph[start_node]);

    printAnswer();

    return 0;
}