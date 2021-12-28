#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    vector<int>arr;

    for(int i{0}; i < N; i++){

        int num;
        cin>>num;
        arr.push_back(num);
    }

    priority_queue<pair<int, int>>pq;
    pair<int,int>tmp = {1, -1 * arr[0]};

    pq.push(tmp);

    for(int i{1}; i < N; i++){

        vector<pair<int, int>>tmp;

        while(!pq.empty()){

            pair<int, int> max = pq.top();

            int size = max.first;
            int number = -1 * max.second;

            if(arr[i] < number){

                tmp.push_back(max);
                pq.pop();
                continue;
            }

            if(arr[i] == number){

                for(auto j : tmp)
                    pq.push(j);

                break;
            }

            if(arr[i] > number){
                pq.push({size + 1, -1 * arr[i]});

                for(auto j : tmp)
                    pq.push(j);

                break;
            }
        }

        if(pq.empty()){

            pq.push({1, -1 * arr[i]});

            for(auto j : tmp)
                pq.push(j);
        }
    }

    cout<<pq.top().first<<"\n";

    return 0;
}