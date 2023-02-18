#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

const int INF = 1000000000;

int getMin(int a, int b){
    return (a < b ? a : b);
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<vector<int>>graph;
    for(int i{0}; i < N; i++){
        vector<int>tmp(N, 0);
        for(int j{0}; j < N; j++){
            int num; cin >> num;

            if(num == 0)
                num = INF;

            tmp[j] = num;
        }
        graph.push_back(tmp);
    }

    for(int k{0}; k < N; k++){
        for(int i{0}; i < N; i++){
            for(int j{0}; j < N; j++){
                graph[i][j] = getMin(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i{0}; i < N; i++){
        for(int j{0}; j < N; j++){

            if(graph[i][j] == INF){
                cout<<0<<" ";
            } else{
                cout<<1<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}