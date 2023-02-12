#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

const int INF = 1000000000;
int node_cnt, edge_cnt;
vector<vector<int>>dist;

void getInput(){

    cin.tie(NULL);

    cin >> node_cnt >> edge_cnt;

    for(int i{0}; i <= node_cnt; i++){
        vector<int>tmp(node_cnt + 1, INF);
        tmp[i] = 0;
        dist.push_back(tmp);
    }

    for(int i{0}; i < edge_cnt; i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        if(cost < dist[start][end])
            dist[start][end] = cost;
    }
}

int getMin(int a, int b){
    return (a > b ? b : a);
}

void getAnswer(){
    for(int k{1}; k <= node_cnt; k++){
        for(int i{1}; i <= node_cnt; i++){
            for(int j{1}; j <= node_cnt; j++){
                dist[i][j] = getMin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int answer = INF;

    for(int i{1}; i <= node_cnt; i++){
        for(int j{1}; j <= node_cnt; j++){

            if(i == j)
                continue;

            int result = dist[i][j] + dist[j][i];

            answer = getMin(answer, result);
        }
    }

    cout<<(answer >= INF ? -1 : answer)<<"\n";
}

int main(){

    getInput();

    getAnswer();

    return 0;
}