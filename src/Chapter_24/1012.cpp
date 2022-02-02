#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int answer=0;
int N, M, K;

void DFS(stack<int>node, vector<vector<bool>>& visited, vector<vector<int>>& graph);

int main(){

    int T;
    cin>>T;
    
    for(int t{0}; t < T; t++){

        cin>>N>>M>>K;
        
        answer=0;
        vector<bool>tmp(M, false);
        vector<vector<bool>>visited(N, tmp);
        vector<vector<bool>>arr(N, tmp);

        for(int i{0}; i < K; i++){

            int node1, node2;
            cin>>node1>>node2;
            arr[node1][node2]=true;
        }

        vector<int>tmp2;
        vector<vector<int>>graph(N*M, tmp2);

        for(int i{0}; i < N; i++){

            for(int j{0}; j < M ; j++){

                if(arr[i][j] == 0 || (i == N-1 && j == M-1))
                    continue;

                else{

                    if(i == N-1){
                        
                        if(arr[i][j+1]){

                            graph[i*M + j].push_back( i * M + j + 1);
                            graph[i*M + j +1].push_back(i*M + j);
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

                            graph[i*M + j].push_back( i * M + j + 1);
                            graph[i*M + j +1].push_back(i*M + j);
                        }

                        if(arr[i+1][j]){

                            graph[i*M + j].push_back((i+1)*M + j);
                            graph[(i+1)*M + j].push_back(i*M + j);
                        }
                    }
                }
            }
        }

        for(int i{0}; i  < N; i++){

            for(int j{0}; j < M; j++){

                if(arr[i][j] == false || visited[i][j] == true)
                    continue;
                
                else{

                    stack<int>stk;
                    stk.push(i*M + j);
                    visited[i][j]=true;

                    DFS(stk, visited, graph);
                    answer++;
                }
            }
        }

        cout<<answer<<"\n";
    }

    return 0;
}


void DFS(stack<int>node, vector<vector<bool>>& visited, vector<vector<int>>& graph){

    for(auto i : graph[node.top()]){

        if(visited[i/M][i%M] == false){

            node.push(i);
            visited[i/M][i%M]=true;

            DFS(node, visited, graph);
        }
    }

    node.pop();
}