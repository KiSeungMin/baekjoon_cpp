#include<iostream>
#include<stack>
using namespace std;

int main(){

    int N;
    cin>>N;

    stack<int> stk;

    for(int i{0}; i < N; i++){
        
        int num;
        cin>>num;

        if(num==0)
            stk.pop();

        else
            stk.push(num);
    }

    int answer=0;

    while(!stk.empty()){

        answer+=stk.top();
        stk.pop();
    }

    cout<<answer<<endl;

    return 0;
}