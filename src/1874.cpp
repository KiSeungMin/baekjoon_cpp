#include<iostream>
#include<vector>
#include<stack>
#define sync_with_stdio(false)
using namespace std;

int main(){
    
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int>arr;

    for(int i{0}; i < N; i++){

        int  num;
        cin>>num;

        arr.push_back(num);
    }

    stack<int> start;
    stack<int> end;
    vector<char>result;

    for(int i{N}; i > 0 ; i --){
        end.push(i);
    }

    for(int i{0}; i < N ; i++){

        if(!start.empty() && start.top() == arr[i]){
            start.pop();
            result.push_back('-');
            continue;
        }

        else{

            while(!end.empty() && end.top() != arr[i]){
               
                start.push(end.top());
                end.pop();
                result.push_back('+');
            }

            if(end.empty()){

                cout<<"NO"<<endl;
                return 0;
            }

            else if(!end.empty() && end.top() == arr[i]){

                end.pop();
                result.push_back('+');
                result.push_back('-');
            }
        }
    }

    for(int i{0}; i <result.size(); i++){
        cout<<result[i]<<"\n";
    }

    return 0;
}