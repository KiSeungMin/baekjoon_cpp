#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;
int answer=0;

void BFS(queue<int>node, vector<vector<bool>>& visited, vector<vector<int>>& graph);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    vector<vector<bool>>arr;

    for(int i{0}; i < N; i++){

        string s;
        cin>>s;
        vector<bool>tmp;

        for(int j{0}; j < M; j++){

            if(s[j] == '0')
                tmp.push_back(false);

            else
                tmp.push_back(true);
        }

        arr.push_back(tmp);
    }

    vector<bool>tmp(M, false);
    vector<vector<bool>>visited(N, tmp);

    vector<int>tmp2;
    vector<vector<int>>graph(N*M, tmp2);

    for(int i{0}; i < N; i++){

        for(int j{0}; j < M; j++){

            if(arr[i][j] == false || (i == N-1 && j == M-1))
                continue;

            else if(i == N-1){

                if(arr[i][j+1]){

                    graph[i * M + j].push_back(i*M + j+1);
                    graph[i*M + j+1].push_back(i*M + j);
                }
            }

            else if(j == M-1){

                if(arr[i+1][j]){

                    graph[i*M + j].push_back((i+1)*M + j);
                    graph[(i+1)*M + j].push_back(i*M + j);
                }
            }

            else{

                if(arr[i][j+1]){

                    graph[i * M + j].push_back(i*M + j+1);
                    graph[i*M + j+1].push_back(i*M + j);
                }

                if(arr[i+1][j]){

                    graph[i*M + j].push_back((i+1)*M + j);
                    graph[(i+1)*M + j].push_back(i*M + j);
                }
            }
        }
    }

    queue<int>que;
    que.push(0);
    visited[0][0]=true;
    answer++;

    BFS(que, visited, graph);

    cout<<answer<<"\n";

    return 0;
}

void BFS(queue<int>node, vector<vector<bool>>& visited, vector<vector<int>>& graph){

    answer++;
    vector<int>tmp;

    while(!node.empty()){

        int start =node.front();

        for(auto i : graph[start]){

            if(visited[i/M][i%M] == false){

                if(i == M*N-1)
                    return;

                visited[i/M][i%M]=true;
                tmp.push_back(i);   
            }
        }

        node.pop();
    }

    for(auto i : tmp)
        node.push(i);

    BFS(node, visited, graph);
}

