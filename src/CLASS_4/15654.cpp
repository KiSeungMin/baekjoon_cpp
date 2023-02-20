#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int possible, limit;
vector<int>possibles;

void getAnswer(vector<int>&num_list, vector<bool>&check){

    if(num_list.size() == limit){
        for(auto i : num_list){
            cout<<i<<" ";
        }
        cout<<"\n";
        
        return;
    }

    for(int i{0}; i < possible; i++){
        if(!check[i]){
            vector<int>next_num_list = num_list;
            vector<bool>next_check = check;
            next_num_list.push_back(possibles[i]);
            next_check[i] = true;
            getAnswer(next_num_list, next_check);            
        }
    }
}

int main(){

    cin >> possible >> limit;

    vector<bool>check;
    for(int i{0}; i < possible; i++){
        int num; cin >> num;
        possibles.push_back(num);
        check.push_back(false);
    }

    sort(possibles.begin(), possibles.end());

    for(int i{0}; i < possible; i++){
        vector<int>tmp = {possibles[i]};
        check[i] = true;
        getAnswer(tmp, check);
        check[i] = false;
    }

    return 0;
}
