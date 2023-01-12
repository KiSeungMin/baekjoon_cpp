#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

int N;
int res=1;
vector<int>result;
vector<vector<bool>>visited;

void DFS(stack<int> node, vector<vector<int>>& graph);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    vector<vector<int>>arr;
    for(int i{0}; i < N; i++){
        vector<int>tmp;
        vector<bool>tmp2(N, false);

        string s;
        cin>>s;

        for(int k{0}; k < N; k++){
            if(s[k] == '0')
                tmp.push_back(0);
            else
                tmp.push_back(1);
        }
    
        arr.push_back(tmp);
        visited.push_back(tmp2);
    }

    vector<int>tmp;
    vector<vector<int>>graph(N*N, tmp);

    for(int i{0}; i  < N; i++){

        for(int j{0}; j  < N; j++){

            if(arr[i][j] == 0 || (i == N-1 && j == N-1))
                continue;

            else{
                
                if(i == N - 1){

                    if(arr[i][j+1] == 1)
                        graph[i*N + j].push_back(i*N + j+1);
                        graph[i*N + j + 1].push_back(i*N + j);
                }

                else if(j == N -1){
                    
                    if(arr[i+1][j] == 1)
                        graph[i * N + j].push_back((i+1)*N + j);
                        graph[(i+1)* N + j].push_back(i*N + j);
                }

                else{

                    if(arr[i][j+1] == 1)
                        graph[i*N + j].push_back(i*N + j+1);
                        graph[i*N + j + 1].push_back(i*N + j);

                    if(arr[i+1][j] == 1)
                        graph[i * N + j].push_back((i+1)*N + j);
                        graph[(i+1)*N + j].push_back(i*N + j);
                }
            }
        }
    }

    for(int i{0}; i < N; i++){

        for(int j{0}; j < N; j++){

            if(arr[i][j] == 0 || visited[i][j] == true)
                continue;

            if(arr[i][j] == 1 && visited[i][j] == false){
                
                stack<int>stk;
                stk.push(i*N + j);
                visited[i][j]=true;
                res = 1;

                DFS(stk, graph);
                result.push_back(res);
            }
        }
    }

    cout<<result.size()<<"\n";

    sort(result.begin(), result.end());
    for(auto i : result)
        cout<<i<<"\n";

    return 0;
}

void DFS(stack<int> node, vector<vector<int>>& graph){

    for(auto i : graph[node.top()]){

        if(visited[i/N][i%N] == false){

            visited[i/N][i%N] = true;
            res ++;
            node.push(i);
            DFS(node, graph);
        }
    }

    node.pop();
}