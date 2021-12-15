#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int result=0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    vector<vector<intl>>arr;

    for(int i{0}; i < N; i++){

        vector<int>tmp;
        for(int j{0}; j < M; j++){

            int num;
            cin>>num;

            if(num == 0)
                result++;

            tmp.push_back(num);
        }
        arr.push_back(tmp);
    }

    queue<int>node;

    for(int i{0}; i < N; i++){

        for(int j{0}; j < M; j++){

            if(arr[i][j] == 1){

                node.push(i*M + j);
                visited[i][j] = true;
            }
        }
    }

    if(result == 0){
        cout<<0<<"\n";
        return 0;
    }

    return 0;
}

void DFS(queue<int>node, vector<vector<bool>>& visited, vector<vector<int>>& graph){

    vector<int> tmp;

    while(!node.empty()){ 

        int start = node.front();

        int row = start / M;
        int col = start % M;


    }

    for(auto i : )
}