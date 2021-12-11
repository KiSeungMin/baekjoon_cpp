#include<iostream>
#include<queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    priority_queue<int, vector<int>, greater<int>>pque;

    for(int i{0}; i < N; i++){

        int num;
        cin>>num;

        if(num == 0){

            if(pque.size() == 0){
                cout<<0<<"\n";
                continue;
            }

            cout<<pque.top()<<"\n";
            pque.pop();
            continue;
        }

        pque.push(num);
    }

    return 0;
}