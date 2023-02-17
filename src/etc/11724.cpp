#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int node, edges;
vector<int>parent;
vector<vector<int>>graph;

void getInput(){

    cin.tie(NULL);
    cin >> node >> edges;

    for(int i{0}; i <= node; i++){
        parent.push_back(-1);
        vector<int>tmp;
        graph.push_back(tmp);
    }

    for(int i{0}; i < edges; i++){
        int num1, num2;
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }
}

void DFS(int num){

    for(auto adj : graph[num]){

        if(parent[adj] != -1)
            continue;

        parent[adj] = num;
        DFS(adj);
    }
}

int main(){

    getInput();
    DFS(1);

    int answer = 1;
    for(int i{2}; i <= node; i++){

        if(parent[i] != -1)
            continue;

        answer++;
        DFS(i);
    }

    cout<<answer<<"\n";

    return 0;
}