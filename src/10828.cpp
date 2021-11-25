#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int>stk;

    int N;
    cin>>N;

    for(int i{0};i <N; i++){

        string s;
        cin>>s;

            if(s== "push"){
                int num;
                cin>>num;
                stk.push(num);
            }

            if(s == "pop"){

                if(stk.empty()){
                    cout<<-1<<endl;
                }
                else{
                    cout<<stk.top()<<endl;
                    stk.pop();
                }
            }
            
            if(s== "size"){
                cout<<stk.size()<<endl;
            }

            if(s== "empty"){   

                if(!stk.empty())
                    cout<<0<<endl;

                else
                    cout<<1<<endl;
            }

            if(s== "top"){
                if(stk.empty())
                    cout<<-1<<endl;

                else
                    cout<<stk.top()<<endl;
            }
        }

    return 0;
}