#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){

    string input_str;
    string bomb;

    cin >> input_str >> bomb;

    deque<pair<char, int>>q;
    int bomb_index = 0;

    for(int i{0}; i < input_str.length(); i++){
        
        char c_now = input_str[i];

        if(c_now == bomb[bomb_index]){

            q.push_back({c_now, bomb_index});
            bomb_index++;

            if(bomb_index  == bomb.length()){
                for(int i{0}; i < bomb.length(); i++){
                    q.pop_back();
                }

                if(!q.empty()){
                    bomb_index = q.back().second + 1;
                }
                else{
                    bomb_index = 0;
                }
            }
        }

        else{

            if(c_now == bomb[0]){
                q.push_back({c_now, 0});
                bomb_index = 1;
            }
            else{
                q.push_back({c_now, -1});
                bomb_index = 0;
            }
        }
    }

    if(q.empty()){
        cout<<"FRULA";
    }
    else{
        while(!q.empty()){
            cout<<q.front().first; q.pop_front();
        }
    }
    cout<<endl;
    

    return 0;
}