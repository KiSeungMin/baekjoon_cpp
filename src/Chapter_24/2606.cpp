#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int answer=0;

void DFS(stack<int>node, vector<bool>& visited, vector<vector<int>>& graph);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N;
    cin>>M;

    vector<int>tmp;
    vector<vector<int>>graph(N+1, tmp);

    for(int i{0}; i < M; i++){

        int node1, node2;
        cin>>node1>>node2;

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    vector<bool>visited(N+1, false);
    visited[1]=true;
    stack<int>stk;
    stk.push(1);

    DFS(stk, visited, graph);

    cout<<answer<<"\n";

    return 0;
}

void DFS(stack<int>node, vector<bool>& visited, vector<vector<int>>& graph){

    for(auto i : graph[node.top()]){

        if(visited[i] == false){

            node.push(i);
            visited[i]=true;
            answer++;

            DFS(node, visited, graph);
        }
    }

    node.pop();
}