#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int N;
int answer=1000000000;

vector<vector<int>>score;

void getTeam(int num, vector<int>team);
void getAnswer(vector<int>team);

int main(){

    cin>>N;

    vector<int>tmp(N, 0);

    for(int i{0}; i<N; i++){

        for(int j{0}; j<N; j++)
            cin>>tmp[j];

        score.push_back(tmp);
    }

    vector<int>team;
    getTeam(0, team);

    cout<<answer<<endl;

    return 0;
}

void getTeam(int num, vector<int>team){

    team.push_back(num);

    if(team.size() == N/2){
        getAnswer(team);
        return;
    }

    else{
        for(int i{num + 1}; i < N; i++){
            
            if(i >= N)
                return;

            else
                getTeam(i, team);
        }
    }
}

void getAnswer(vector<int>team){

    int result1=0;
    int result2=0;

    vector<int>enemy;
    vector<bool>find(N, true);

    for(int i{0}; i< N/2; i++){
        find[team[i]]=false;
    }

    for(int i{0}; i<N; i++){
        
        if(find[i]){
            enemy.push_back(i);
        }
    }

    for(int i{0}; i<N/2; i++){
        for(int j{0}; j<N/2; j++){

            result1 += score[team[i]][team[j]];
            result2 += score[enemy[i]][enemy[j]];
        }
    }

    if(abs(result1 - result2) < answer){
        answer=abs(result1 - result2);
    }

    return;
}