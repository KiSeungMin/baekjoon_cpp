#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

const int INF = 100000000;
int node_cnt, edge_cnt;
int goal_node1, goal_node2;
vector<vector<int>>graph;

void getInput(){

    
    cin >> node_cnt >> edge_cnt;

    for(int i{0}; i <= node_cnt; i++){
        vector<int>tmp(node_cnt + 1, INF);
        tmp[i] = 0;
        graph.push_back(tmp);
    }

    for(int i{0}; i < edge_cnt; i++){
        int start, end, dist;
        cin >> start >> end >> dist;

        graph[start][end] = dist;
        graph[end][start] = dist;
    }

    cin>>goal_node1>>goal_node2;
}

int getMin(int a, int b){
    return (a > b ? b : a);
}

void getDist(){
    for(int k{1}; k <= node_cnt; k++){
        for(int i{1}; i <= node_cnt; i++){
            for(int j{1}; j <= node_cnt; j++){
                graph[i][j] = getMin(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int getAnswer(){

    int dist1 = graph[1][goal_node1] + graph[goal_node1][goal_node2] + graph[goal_node2][node_cnt];
    int dist2 = graph[1][goal_node2] + graph[goal_node1][goal_node2] + graph[goal_node1][node_cnt];

    int answer = getMin(dist1, dist2);

    if(answer >= INF)
        return -1;

    return answer;
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    getInput();

    getDist();

    cout<< getAnswer()<<"\n";

    return 0;
}