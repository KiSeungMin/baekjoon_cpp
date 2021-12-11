#include<iostream>
#include<queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    priority_queue<int> pque;

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

        else{
            pque.push(num);
        }
    }

    return 0;
}