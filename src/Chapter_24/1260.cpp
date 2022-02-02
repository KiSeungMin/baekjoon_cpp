#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(stack<int> node, vector<bool>& visited, vector<vector<int>>& graph);
void BFS(queue<int> node, vector<bool>& visited, vector<vector<int>>& graph);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 정점 개수 N, 간선 개수 M, 시작 정점 번호 V
    int N, M ,V;
    cin>>N>>M>>V;
    
    vector<int>tmp;
    vector<vector<int>> graph(N+1, tmp);
    vector<bool>visited(N+1, false);
    vector<bool>visitedCopy=visited;

    for(int i{0}; i < M; i++){

        int node1, node2;
        cin>>node1>>node2;

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for(int i{0}; i < N+1; i++)
        sort(graph[i].begin(), graph[i].end());

    stack<int>stk;
    stk.push(V);
    visited[V]=true;

    DFS(stk, visited, graph);
    cout<<"\n";

    visited=visitedCopy;

    queue<int>que;
    que.push(V);
    visited[V]=true;

    BFS(que, visited, graph);
    cout<<"\n";

    return 0;
}

void DFS(stack<int> node, vector<bool>& visited, vector<vector<int>>& graph){

    cout<<node.top()<<" ";

    for(auto i : graph[node.top()]){

        if(visited[i] == false){
            node.push(i);
            visited[i]=true;
            DFS(node, visited, graph);
        }
    }    

    node.pop();
    return;
}

void BFS(queue<int> node, vector<bool>& visited, vector<vector<int>>& graph){

    cout<<node.front()<<" ";
    int start = node.front();
    node.pop();

    for(auto i : graph[start]){

        if(visited[i] == false){
            node.push(i);
            visited[i]=true;
        }
    }

    if(node.size() == 0)
        return;

    BFS(node, visited, graph);
}