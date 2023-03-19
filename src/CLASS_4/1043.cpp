#include<iostream>
#include<vector>
#include<queue>
#define sync_with_stdio(false)
using namespace std;

int N ,M;

vector<int> getImpossibleList(){

    vector<int>impossible_list;
    int impossibles; cin >> impossibles;
    for(int i{0}; i < impossibles; i++){
        int num; cin >> num;
        impossible_list.push_back(num);
    }

    return impossible_list;
}

void setAdjList(vector<vector<bool>>&adj, vector<vector<int>>&parties){

    for(int i{0}; i < N + 1; i++){
        vector<bool>tmp(N + 1, false);
        tmp[i] = true;
        adj.push_back(tmp);
    }

    for(int i{0}; i < M; i++){
        int count; cin >> count;
        vector<int>participants;

        for(int j{0}; j < count; j++){

            int num; cin >> num;
            participants.push_back(num);

            for(int k{0}; k < j; k++){
                adj[num][participants[k]] = true;
                adj[participants[k]][num] = true;
            }
        }
        parties.push_back(participants);
    }
}

void setImpossible(vector<bool>& is_impossible, vector<int>&impossible_list, vector<vector<bool>>&adj){

    vector<bool>check(N + 1, false);
    queue<int>q;
    for(auto num : impossible_list){
        q.push(num);
    }

    while(!q.empty()){
        int num_now = q.front(); q.pop();
        if(check[num_now])
            continue;

        check[num_now] = true; 
        is_impossible[num_now] = true;

        for(int i{1}; i <= N; i++){
            if(adj[num_now][i]){
                if(check[i] == false){
                    q.push(i);
                }
            }
        }
    }
}

int getAnswer(vector<bool>& is_impossible, vector<vector<int>>& parties){

    int answer = 0;
    for(int i{0}; i < M; i++){

        bool is_possible = true;
        for(auto num : parties[i]){
            if(is_impossible[num]){
                is_possible = false;
                break;
            }
        }

        if(is_possible){
            answer++;
        }
    }

    return answer;
}

int main(){

    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    vector<bool>is_impossible(N + 1, false);
    vector<int>impossible_list = getImpossibleList();

    vector<vector<bool>>adj;
    vector<vector<int>>parties;
    setAdjList(adj, parties);

    setImpossible(is_impossible, impossible_list, adj);

    int answer = getAnswer(is_impossible, parties);

    cout<<answer<<"\n";

    return 0;
}