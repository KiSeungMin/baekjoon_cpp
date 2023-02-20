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
    int N, M; cin >> N >> M;

    vector<vector<int>>graph;
    for(int i{0}; i <= N; i++){
        vector<int>row(N + 1, INF);
        row[i] = 0;
        graph.push_back(row);
    }
    
    

    for(int i{0}; i < M; i++){
        int num1, num2;
        cin >> num1 >> num2;

        graph[num1][num2] = 1;
        graph[num2][num1] = 1;
    }

    for(int k{1}; k <= N; k++){
        for(int i{1}; i <= N; i++){
            for(int j{1}; j <= N; j++){
                graph[i][j] = getMin(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int answer = INF;
    int answer_index = 0;

    for(int i{1}; i <= N; i++){
        int result = 0;
        for(int j{1}; j <= N; j++){
            result += graph[i][j];
        }  

        if(result < answer){
            answer = result;
            answer_index = i;
        }
    }

    cout<<answer_index<<"\n";

    return 0;
}