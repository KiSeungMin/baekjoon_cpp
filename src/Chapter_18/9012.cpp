#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){

    int N;
    cin>>N;

    for(int i{0}; i < N; i++){
        
        string s;
        cin>>s;
        stack<char>stk;

        for(int j{0}; j <s.length(); j++){
            
            if(s[j] == ')'){

                if(!stk.empty() && stk.top() == '(')
                    stk.pop();

                else if(stk.empty() || stk.top()==')'){
                    stk.push('(');
                    break;
                }
            }

            else if(s[j] =='(')
                stk.push('(');
        }

        if(stk.empty()){
            cout<<"YES"<<endl;
        }

        else
            cout<<"NO"<<endl;
    }

    return 0;
}